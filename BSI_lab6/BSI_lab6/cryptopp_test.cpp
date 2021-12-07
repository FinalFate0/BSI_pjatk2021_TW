//#include <vector>
//#include <iostream>
//
//#include <cryptopp/cryptlib.h>
//#include <cryptopp/rijndael.h>
//#include <cryptopp/modes.h>
//#include <cryptopp/aes.h>
//#include <cryptopp/filters.h>
//#include <cryptopp/osrng.h>
//#include <cryptopp/base64.h>
//#include <cryptopp/rc5.h>
//
//
//
//CryptoPP::SecByteBlock getKey(int);
//std::vector<uint8_t> key = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm'};
//std::vector<uint8_t> iv = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm' };
//
////std::string encrypt(const std::string& input, const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv) {
//std::string encrypt(const std::string& input, const CryptoPP::SecByteBlock& key, const CryptoPP::SecByteBlock& iv) {
//    std::string cipher = "";
//
//    //auto aes = CryptoPP::AES::Encryption(key.data(), key.size());
//    //auto aes_cbc = CryptoPP::CBC_Mode_ExternalCipher::Encryption(aes, iv.data());
//
//    
//
//    CryptoPP::CBC_Mode_ExternalCipher::Encryption e;
//    e.SetKeyWithIV(key.data(), key.size(), iv.data());
//
//    auto rs5 = CryptoPP::RC5::Encryption();
//    try {
//        CryptoPP::StringSource ss(
//            input,
//            true,
//            new CryptoPP::StreamTransformationFilter(
//                e,
//                new CryptoPP::StringSink(cipher)
//                //new CryptoPP::Base64Encoder(
//                //    new CryptoPP::StringSink(cipher)
//                //)
//            )
//        );
//    }
//    catch (const CryptoPP::Exception& e) {
//        std::cerr << e.what() << std::endl;
//    }
//
//    return cipher;
//}
//
//std::string decrypt(const std::string& cipher_text, const std::vector<uint8_t>& key, const std::vector<uint8_t>& iv) {
//    std::string plain_text;
//
//    auto aes = CryptoPP::AES::Decryption(key.data(), key.size());
//    auto aes_cbc = CryptoPP::CBC_Mode_ExternalCipher::Decryption(aes, iv.data());
//
//    CryptoPP::StringSource ss(
//        cipher_text,
//        true,
//        new CryptoPP::Base64Decoder(
//            new CryptoPP::StreamTransformationFilter(
//                aes_cbc,
//                new CryptoPP::StringSink(plain_text)
//            )
//        )
//    );
//
//    return plain_text;
//}
//
//int main() {
//    static constexpr size_t AES_KEY_SIZE = 256 / 8; //AES-256
//
//    const std::string input{ "Secret message" };
//    //std::vector<uint8_t> key(AES_KEY_SIZE);
//    //std::vector<uint8_t> iv(CryptoPP::AES::BLOCKSIZE);
//
//    CryptoPP::NonblockingRng rand;
//    //rand.GenerateBlock(key.data(), key.size());
//    //rand.GenerateBlock(iv.data(), iv.size());
//
//    auto cipher = encrypt(input, getKey(16), getKey(16));
//    auto plain_text = decrypt(cipher, key, iv);
//
//
//    std::cout << "plain text: " << input << std::endl <<
//        "key: " << key.data() << std::endl <<
//        "encrypted: " << cipher << std::endl <<
//        "decrypted: " << plain_text << std::endl;
//
//    if (plain_text != input) {
//        std::cout << "" << std::endl;
//    }
//
//    return 0;
//}
//
//CryptoPP::SecByteBlock getKey(int size) {
//
//    CryptoPP::SecByteBlock key(size);
//    for (int i = 0; i < size; i++) {
//        CryptoPP::byte* data = key.data();
//        *(data + i) = i + 5;
//        std::cout << *(key.data() + i) << std::endl;
//    }
//    return key;
//}