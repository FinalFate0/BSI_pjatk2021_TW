#include <stdio.h>
#include <stdlib.h>
#include <openssl/bio.h> 
#include <openssl/err.h>
#include <openssl/ssl.h>

void init_ssl() {
	SSL_load_error_strings();
	SSL_library_init();
}

int main() {
	init_ssl();
}