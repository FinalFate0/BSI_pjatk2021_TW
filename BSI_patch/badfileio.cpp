#include <fstream>
#include <string>
#include <iostream>

int main(){

    while(true){
        std::string name;
        std::cout<< "if you wish to exit program press 0";
        std::cout << "Input file to print: ";
        std::cin >>name;

        if(name[0] == '0'){
            break;
        }

        std::ifstream inputfile(name);
        std::string line;
        while(std::getline(inputfile, line)){
            std::cout << line;
        }

    }
}