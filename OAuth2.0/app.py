from flask import Flask, redirect, render_template
import google.oauth2.credentials
import google_auth_oauthlib.flow

app = Flask(__name__)

flow = google_auth_oauthlib.flow.Flow.from_client_secrets_file(
    'client_secret.json',
    scopes=['https://www.googleapis.com/auth/drive.metadata.readonly'])

flow.redirect_uri = 'http://localhost:5000'

authorization_url, state = flow.authorization_url(
    access_type='offline',
    include_granted_scopes='true')


@app.route('/login')
def hello():
    return redirect(authorization_url)

@app.route('/')
def test():
    return render_template('index.html')