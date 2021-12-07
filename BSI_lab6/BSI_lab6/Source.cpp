#include "cryptopp/cryptlib.h"
#include "cryptopp/rijndael.h"
#include "cryptopp/modes.h"
#include "cryptopp/files.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"
#include "cryptopp/rc5.h"
#include "cryptopp/idea.h"

#include "cryptoFunc.h"

#include <fstream>
#include <iostream>
#include <string>

std::vector<uint8_t> key = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm'};
std::vector<uint8_t> iv = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm' };

void encryptFile(std::string path) {

}


int main(int argc, char* argv[])
{





    using namespace CryptoPP;

    AutoSeededRandomPool prng;
    HexEncoder encoder(new FileSink(std::cout));


    std::string plain = "CBC Mode Test";
    std::string cipherAes,cipherRc5, cipherIdea, recoveredAes, recoveredIdea, recoveredRc5;

    std::cout << "plain text: " << plain << std::endl;


    std::fstream file;
    file.open("test.txt", std::ios::in);
    std::string payload;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line;
            payload += line + "\n";
        }
    }
    file.close();



    std::cout << payload << std::endl;

    cipherAes = encryptAes(payload, key, iv);
    cipherRc5 = encryptRc5(cipherAes, key, iv);
    cipherIdea = encryptIdea(cipherRc5, key, iv);


    file.open("test.txt", std::ios::out);
    if(file.is_open())
        file << cipherIdea;
    file.close();



    std::cout << "key: ";
    encoder.Put(key.data(), key.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "iv: ";
    encoder.Put(iv.data(), iv.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "cipher text: ";
    encoder.Put((const byte*)&cipherIdea[0], cipherIdea.size());
    encoder.MessageEnd();
    std::cout << std::endl;


    recoveredIdea = decryptIdea(cipherIdea, key, iv);
    recoveredRc5 = decryptRc5(recoveredIdea, key, iv);
    recoveredAes = decryptAes(recoveredRc5, key, iv);

    std::cout << recoveredAes << std::endl;

    return 0;
}