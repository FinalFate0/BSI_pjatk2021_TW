/**
* @author Jan Wieczorek 21024
* @author Tymoteusz Urbanowicz 20149
*/

#include <vector>
#include <fstream>
#include "cryptoFunc.h"




/** encryption key */
const std::vector<uint8_t> key = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm' };

/** initialization vector */
const std::vector<uint8_t> iv = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'i', 'j', 'k', 'l', 'm' };

/** initialization vector */
const std::vector<uint8_t> ivIdea = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };


/**
* Main function serving as user command line interface
*/

int main() {

	std::cout << "Welcome -> This is your safe(ty) space!" << std::endl
		<< "========================================" << std::endl
		<< " ______	       ________	    ______" << std::endl
		<< "||    \\\\      /   ____/    |__  __|" << std::endl
		<< "||____//      \\___  \\	     | 	|" << std::endl
		<< "||    \\\\     ___ /  /       _|  |_" << std::endl
		<< "||____//    |______/       |______|" << std::endl
		<< "========================================" << std::endl;

	std::cout << std::endl;
	bool keep_going = true;

	while (keep_going) {
		int action = 0;
		std::string action_str;

		std::cout
			<< "0  -  end program" << std::endl
			<< "1  -  encrypt AES" << std::endl
			<< "2  -  decrypt AES" << std::endl
			<< "3  -  encrypt RC5" << std::endl
			<< "4  -  decrypt RC5" << std::endl
			<< "5  -  encrypt IDEA" << std::endl
			<< "6  -  dncrypt IDEA" << std::endl
			<< "7  -  encrypt RSA" << std::endl
			<< "8  -  decrypt RSA" << std::endl
			<< "9  -  encrypt ElGamal" << std::endl
			<< "10 -  decrypt ElGamal" << std::endl
			<< "Please choose your action" << std::endl;
		std::cin >> action_str;
		try {
			action = std::stoi(action_str);
			if (action > 10 || action < 0)
				throw std::out_of_range("");
		}
		catch (std::invalid_argument e) {
			std::cout << "Wrong argument provided\nExiting program :(" << std::endl;
			return 0;
		}
		catch (std::out_of_range e) {
			std::cout << "There is no such action :(\nTry again" << std::endl;
			continue;
		}

		switch (action) {
		case 1: 
			{
			std::string path;
			std::cout << "Please provide path to file you want to encrypt" << std::endl;
			std::cin >> path;
			encryptAes(path.c_str(), key, iv);
			}
			break;
		case 2:
			{
			std::string path;
			std::cout << "Please provide path to file you want to decrypt" << std::endl;
			std::cin >> path;
			decryptAes(path.c_str(), key, iv);
			}
			break;
		case 3:
			{
			std::string path;
			std::cout << "Please provide path to file you want to encrypt" << std::endl;
			std::cin >> path;
			encryptRc5(path.c_str(), key, iv);
			}
			break;
		case 4:
			{
			std::string path;
			std::cout << "Please provide path to file you want to decrypt" << std::endl;
			std::cin >> path;
			decryptRc5(path.c_str(), key, iv);
			}
			break;
		case 5:
			{
			std::string path;
			std::cout << "Please provide path to file you want to encrypt" << std::endl;
			std::cin >> path;
			encryptIdea(path.c_str(), key, ivIdea);
			}
			break;
		case 6:
			{
			std::string path;
			std::cout << "Please provide path to file you want to decrypt" << std::endl;
			std::cin >> path;
			decryptIdea(path.c_str(), key, ivIdea);
			}
			break;
		case 7:
			{
			std::string path;
			std::cout << "Please provide path to file you want to encrypt" << std::endl;
			std::cin >> path;
			encryptRSA(path.c_str());
			}
			break;
		case 8:
			{
			std::string path, key;
			std::cout << "Please provide path to file you want to decrypt" << std::endl;
			std::cin >> path;
			std::cout << "Please provide path to key you want to decrypt with" << std::endl;
			std::cin >> key;
			decryptRSA(path.c_str(), key.c_str());
			}
			break;
		case 9:
			{
			std::string path;
			std::cout << "Please provide path to file you want to encrypt" << std::endl;
			std::cin >> path;
			encryptElGamal(path.c_str());
			}
			break;
		case 10:
			{
			std::string path, key;
			std::cout << "Please provide path to file you want to decrypt" << std::endl;
			std::cin >> path;
			std::cout << "Please provide path to key you want to decrypt with" << std::endl;
			std::cin >> key;
			decryptElGamal(path.c_str(), key.c_str());
			}
			break;
		default:
		case 0:
			keep_going = false;
		}
	}
}