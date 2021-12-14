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
#include "cryptopp/base64.h"
#include "cryptopp/rsa.h"
#include "cryptopp/elgamal.h"


#include <string>


/**
* This function encrypts a file with ElGamal cipher with random key which is saved to file
*
* @param[in]        input       file to be encrypted
*
*/
void encryptElGamal(const char* input) {
    CryptoPP::AutoSeededRandomPool rng;

    
    CryptoPP::ElGamal::Decryptor decryptor;
    decryptor.AccessKey().GenerateRandomWithKeySize(rng, 2048);
    const CryptoPP::ElGamalKeys::PrivateKey& privKey = decryptor.AccessKey();

    std::cout << "generatedKey" << std::endl;

    privKey.Save(CryptoPP::FileSink("elgamal.der", true).Ref());
    std::cout << "key saved to: elgamal.der" << std::endl;
    
    CryptoPP::ElGamal::Encryptor encryptor(decryptor);
    const CryptoPP::PublicKey& pubKey = encryptor.AccessKey();

    try {
        CryptoPP::FileSource s(input, true,
            new CryptoPP::PK_EncryptorFilter(rng, encryptor,
                new CryptoPP::FileSink("EncryptedElGamalFile.txt")
            )
        );
    }
    catch (CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}


/**
* This function decrypts a file encoded with ElGamal cipher with provided key
*
* @param[in]        input       file to be decrypted
* @param[in]        EGkey       key to decrypt file with
*
*/

void decryptElGamal(const char* input, const char* EGkey) {
    CryptoPP::AutoSeededRandomPool rng;
    CryptoPP::ElGamal::PrivateKey privKey;
    privKey.Load(CryptoPP::FileSource(EGkey, true).Ref());
    CryptoPP::ElGamal::Decryptor d(privKey);

    try {
        CryptoPP::FileSource s(input, true,
            new CryptoPP::PK_DecryptorFilter(rng, d,
                new CryptoPP::FileSink("DecryptedElGamalFile.txt")
            )
        );
    }
    catch(CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

/**
* This function encrypts a file with RSA cipher with random key which is saved to file
*
* @param[in]        input       file to be decrypted
*
*/

void encryptRSA(const char* input) {
    CryptoPP::AutoSeededRandomPool rng;


    CryptoPP::RSA::PrivateKey privKey;
    privKey.GenerateRandomWithKeySize(rng, 3072);
    privKey.Save(CryptoPP::FileSink("rsaKey.txt").Ref());
    std::cout << "Key saved to: rsaKey.txt" << std::endl;

    CryptoPP::RSA::PublicKey  pubKey(privKey);

    CryptoPP::RSAES_OAEP_SHA_Encryptor e(pubKey);

    try {
        CryptoPP::FileSource s(input, true,
            new CryptoPP::PK_EncryptorFilter(rng, e,
                new CryptoPP::FileSink("EncryptedRSAFile.txt"))
        );
    }
    catch (CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

/**
* This function decrypts a file encoded with RSA cipher with provided key
*
* @param[in]        input       file to be decrypted
* @param[in]       RSAkey       key to decrypt file with
*
*/



void decryptRSA(const char* input, const char* RSAkey) {
    CryptoPP::AutoSeededRandomPool rng;
    
    CryptoPP::RSA::PrivateKey privKey;
    privKey.Load(CryptoPP::FileSource(RSAkey, true).Ref());

    CryptoPP::RSAES_OAEP_SHA_Decryptor d(privKey);

    try {
        CryptoPP::FileSource s(input, true,
            new CryptoPP::PK_DecryptorFilter(rng, d,
                new CryptoPP::FileSink("DecryptedRSAFile.txt")
            )
        );
    }
    catch (CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}



/**
* This function encrypts a file with an AES cipher
*
* @param[in]        input       file to be encrypted
* @param[in]         key        key to encrypt file with
* @param[in]          iv        inicialization vector to encrypt file with
*
*/


void encryptAes(const char *input, std::vector<uint8_t> key, std::vector<uint8_t> iv) {
    try
    {
        CryptoPP::CBC_Mode< CryptoPP::AES >::Encryption aes;
        aes.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::FileSource s(input, true,
            new CryptoPP::StreamTransformationFilter(
                aes,
                new CryptoPP::FileSink("EncryptedAESFile.txt")
            )
        );

    }
    catch (const CryptoPP::Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

/**
* This function encrypts a file with an RC5 cipher
*
* @param[in]        input       file to be encrypted
* @param[in]         key        key to encrypt file with
* @param[in]          iv        inicialization vector to encrypt file with
*
*/

void encryptRc5(const char *input, std::vector<uint8_t> key, std::vector<uint8_t> iv) {
    try
    {
        CryptoPP::CBC_Mode< CryptoPP::RC5 >::Encryption rc5;
        rc5.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::FileSource s(input, true,
            new CryptoPP::StreamTransformationFilter(rc5,
                new CryptoPP::FileSink("EncryptedRC5File.txt")
            )
        );
    }
    catch (const CryptoPP::Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

/**
* This function encrypts a file with an IDEA cipher
*
* @param[in]        input       file to be encrypted
* @param[in]         key        key to encrypt file with
* @param[in]          iv        inicialization vector to encrypt file with
*
*/


void encryptIdea(const char *input, std::vector<uint8_t> key, std::vector<uint8_t> iv) {
    try
    {

        CryptoPP::CBC_Mode< CryptoPP::IDEA >::Encryption idea;
        idea.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::FileSource s(input, true,
            new CryptoPP::StreamTransformationFilter(idea,
                new CryptoPP::FileSink("EncryptedIDEAFile.txt")
            )
        );
    }
    catch (const CryptoPP::Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

/**
* This function decrypts a file encrypted with an IDEA cipher
*
* @param[in]        input       file to be decrypted
* @param[in]         key        key to decrypt file with
* @param[in]          iv        inicialization vector to decrypt file with
*
*/

void decryptIdea(const char *input, std::vector<uint8_t> key, std::vector<uint8_t>iv) {
    std::string recoveredIdea;

    try
    {
        CryptoPP::CBC_Mode< CryptoPP::IDEA >::Decryption dIdea;
        dIdea.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::FileSource s(input, true,
            new CryptoPP::StreamTransformationFilter(dIdea,
                new CryptoPP::FileSink("DecryptedIDEAFile.txt")
            )
        );



    }
    catch (const CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}

/**
* This function decrypts a file encrypted with an Rc5 cipher
*
* @param[in]        input       file to be decrypted
* @param[in]         key        key to decrypt file with
* @param[in]          iv        inicialization vector to decrypt file with
*
*/

void decryptRc5(const char *input, std::vector<uint8_t> key, std::vector<uint8_t>iv) {
    std::string recoveredRc5;

    try
    {
        CryptoPP::CBC_Mode< CryptoPP::RC5 >::Decryption dRc5;
        dRc5.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::FileSource s(input, true,
            new CryptoPP::StreamTransformationFilter(dRc5,
                new CryptoPP::FileSink("DecryptedRC5File.txt")
            )
        );
    }
    catch (const CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

}

/**
* This function decrypts a file encrypted with an AES cipher
*
* @param[in]        input       file to be decrypted
* @param[in]         key        key to decrypt file with
* @param[in]          iv        inicialization vector to decrypt file with
*
*/

void decryptAes(const char *input, std::vector<uint8_t> key, std::vector<uint8_t>iv) {
    try
    {
        CryptoPP::CBC_Mode< CryptoPP::AES >::Decryption dAes;
        dAes.SetKeyWithIV(key.data(), key.size(), iv.data());

        CryptoPP::FileSource s(input, true,
                new CryptoPP::StreamTransformationFilter(
                    dAes,
                    new CryptoPP::FileSink("DecryptedAESFile.txt")

            ));
    }
    catch (const CryptoPP::Exception& e) {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
}


#endif // !BSI_CRYPTO_FUNCTIONS_H
