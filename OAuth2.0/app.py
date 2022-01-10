import requests
from flask import Flask, session, request, abort, redirect, render_template
from flask_sqlalchemy import SQLAlchemy
import google.oauth2.credentials
import google_auth_oauthlib.flow
#from werkzeug.wrappers import request
from pip._vendor import cachecontrol

app = Flask(__name__)
app.secret_key = 'supersecretkey'
app.config['SQLALCHEMY_DATABASE_URI'] = 'slqite:///bsiUsers.db'
db = SQLAlchemy(app)

class User(db.Model):
    username = db.Column(db.String(80), primary_key=True)
    email = db.Column(db.String(120), unique=True, nullable=False)

    def __repr__(self) -> str:
        return '<Name %r>' % self.username

GOOGLE_CLIENT_ID = "78230996300-7n84ekv6lo7kc8d60l5hf2aaroop108u.apps.googleusercontent.com"

flow = google_auth_oauthlib.flow.Flow.from_client_secrets_file(
    'client_secret.json',
    #scopes=['https://www.googleapis.com/auth/drive.metadata.readonly'])
    scopes=['https://www.googleapis.com/auth/userinfo.profile',
            'https:://www.googleapis.com/auth/userinfo.email',
            'openid'])

flow.redirect_uri = 'http://localhost:5000/callback'

authorization_url, state = flow.authorization_url(
    access_type='offline',
    include_granted_scopes='true')


@app.route('/login')
def login():
    authorization_url, state = flow.authorization_url()
    session['state'] = state
    return redirect(authorization_url)


@app.route('/callback')
def callback():
    flow.fetch_token(authorization_response=request.url)
    if not session['state'] == request.args['state']:
        abort(500)
    
    credentials = flow.credentials
    request_session = requests.session()
    cached_session = cachecontrol.CacheControl(request_session)
    token_request = google.auth.transport.requests.Request(session=cached_session)

    id_info = google.oauth2.id_token.verify_oauth2_token(
        id_token=credentials._id_token,
        request=token_request,
        audience=GOOGLE_CLIENT_ID
    )

    if not db.session.query(db.exists().where(User.name ==id_info.get('name') )).scalar():
        u = User(
            id_info.get('name'),
            id_info.get('email')
            )
        db.session.add(u)
        db.session.commit()
    session['username'] = id_info.get('name')
    return redirect('/')




@app.route('/')
def home():
    if 'username' not in session: 
        return render_template('./index.html')
    return render_template('welcome.html')

@app.route('/logout')
def logout():
    session.clear()
    return redirect('/')