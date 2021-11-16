#include <cmath>
#include <iostream>

#include <iostream>
#include <string>

#include "bsi_exercises.h"
#include "bsi_functions.h"


int main() {
	std::cout << "Welcome -> This is your safe(ty) space!" << std::endl
		<< " ______	       ________	    ______" << std::endl
		<< "||    \\\\      /   ____/    |__  __|"<< std::endl
		<< "||____//      \\___  \\	     | 	|" << std::endl
		<< "||    \\\\     ___ /  /       _|  |_" << std::endl
		<< "||____//    |______/       |______|" << std::endl;

	std::cout << std::endl;
		bool keep_going = true;

	while (keep_going) {
		int exercise = 0;
		std::string ex_str;
		std::cout
			<< "What execrise would you like to do?" << std::endl
			<< "0 - I don't want to do math :(   =>  finish program" << std::endl
			<< "1 - exercise 4 from set 2" << std::endl
			<< "2 - exercise 7 from set 2" << std::endl
			<< "3 - exercise 8a from set 2" << std::endl
			<< "4 - exercise 8b from set 2" << std::endl
			<< "5 - exercise 16 from set 3" << std::endl
			<< "6 - exercise 18 from set 8" << std::endl
			<< "============================"<< std::endl
			<< "Please provide your ansewer: ";
		std::cin >> ex_str;
		try {
			exercise = std::stoi(ex_str);
			if (exercise > 6 || exercise < 0)
				throw std::out_of_range("");
		}
		catch (std::invalid_argument e) {
			std::cout << "Wrong argument provided\nExiting program :(" << std::endl;
			return 0;
		}
		catch (std::out_of_range e) {
			std::cout << "There is no such exercise :(\nTry again" << std::endl;
			continue;
		}

		switch (exercise) {
			case 1:
				ex_0204();
				break;
			case 0:
				keep_going = false;
		}


	}

	return 0;
}