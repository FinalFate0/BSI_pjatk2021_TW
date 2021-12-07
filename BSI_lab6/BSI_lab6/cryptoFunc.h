#ifndef BSI_CRYPTO_FUNCTIONS_H
#define BSI_CRYPTO_FUNCTIONS_H

#include "cryptopp/cryptlib.h"
#include "cryptopp/rijndael.h"
#include "cryptopp/modes.h"
#include "cryptopp/files.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"
#include "cryptopp/rc5.h"
#include "cryptopp/idea.h"

#include <string>


std::string encryptAes(std::string input, std::vector<uint8_t> key, std::vector<uint8_t> iv) {
    std::string cipherAes;
    try
    {

        CryptoPP::CBC_Mode< CryptoPP::AES >::Encryption aes;
        aes.SetKeyWithIV(key.data(), key.size(), iv.data());


        CryptoPP::StringSource s(input, true,
            new CryptoPP::StreamTransformationFilter(aes,
                new CryptoPP::StringSink(cipherAes)
            )
        );
    }
    catch (const CryptoPP::Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return cipherAes;
}

std::string encryptRc5(std::string input, std::vector<uint8_t> key, std::vector<uint8_t> iv) {
    std::string cipherRc5;
    try
    {

        CryptoPP::CBC_Mode< CryptoPP::RC5 >::Encryption rc5;
        rc5.SetKeyWithIV(key.data(), key.size(), iv.data());


        CryptoPP::StringSource s(input, true,
            new CryptoPP::StreamTransformationFilter(rc5,
                new CryptoPP::StringSink(cipherRc5)
            )
        );
    }
    catch (const CryptoPP::Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    return cipherRc5;
}

std::string encryptIdea(std::string input, std::vector<uint8_t> key, std::vector<uint8_t> iv) {
    std::string cipherIdea;
    try
    {

        CryptoPP::CBC_Mode< CryptoPP::IDEA >::Encryption idea;
        idea.SetKeyWithIV(key.data(), key.size(), iv.data());


        CryptoPP::StringSource s(input, true,
            new CryptoPP::StreamTransformationFilter(idea,
                new CryptoPP::StringSink(cipherIdea)
            )
        );
    }
    catch (const CryptoPP::Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    return cipherIdea;
}

std::string decryptIdea(std::string input, std::vector<uint8_t> key, std::vector<uint8_t>iv) {
    std::string recoveredIdea;

    try
    {
        CryptoPP::CBC_Mode< CryptoPP::IDEA >::Decryption dIdea;
        dIdea.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::StringSource s(input, true,
            new CryptoPP::StreamTransformationFilter(dIdea,
                new CryptoPP::StringSink(recoveredIdea)
            )
        );
    }
    catch (const CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return recoveredIdea;

}

std::string decryptRc5(std::string input, std::vector<uint8_t> key, std::vector<uint8_t>iv) {
    std::string recoveredRc5;

    try
    {
        CryptoPP::CBC_Mode< CryptoPP::RC5 >::Decryption dRc5;
        dRc5.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::StringSource s(input, true,
            new CryptoPP::StreamTransformationFilter(dRc5,
                new CryptoPP::StringSink(recoveredRc5)
            )
        );
    }
    catch (const CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return recoveredRc5;
}

std::string decryptAes(std::string input, std::vector<uint8_t> key, std::vector<uint8_t>iv) {
    std::string recoveredAes;

    try
    {
        CryptoPP::CBC_Mode< CryptoPP::AES >::Decryption dAes;
        dAes.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::StringSource s(input, true,
            new CryptoPP::StreamTransformationFilter(dAes,
                new CryptoPP::StringSink(recoveredAes)
            )
        );
    }
    catch (const CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

    return recoveredAes;
}


#endif // !BSI_CRYPTO_FUNCTIONS_H
