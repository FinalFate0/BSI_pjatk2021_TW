#include <cmath>
#include <iostream>

#include <iostream>
#include <string>

#include "bsi_exercises.h"
#include "bsi_functions.h"

const std::string desc_0204 = "\t\tEstimate the maximum permissible failure rate and\n \t\tminimum MTBF for a device that has to have\n \t\treliability R for time t";
const std::string desc_0207 = "\t\tA car has a failure rate of 0.0001/km\n \t\tCalculate the reliability that the car\n \t\t will reach s kilometers twithout accident ";
const std::string desc_0208a = "\t\tThe weather radar system of an airplane has an MTTF of 1140 hours\n \t\tCalculate probability of failure during t hour flight";
const std::string desc_0208b = "\t\tThe weather radar system of an airplane has an MTTF of 1140 hours\n \t\tCalculate the maximum flight duration\n \t\t that the reliability doesn't drop below R";
const std::string desc_0316 = "\t\tCalculate the reliability of a system that consists of n identical elements\n \t\t";


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
			<< "What exercise would you like to do?" << std::endl
			<< "0 - I don't want to do math :(   =>  finish program" << std::endl
			<< "1 - exercise 4 from set 2" << std::endl
			<< desc_0204 << std::endl
			<< "2 - exercise 7 from set 2" << std::endl
			<< "3 - exercise 8a from set 2" << std::endl
			<< "4 - exercise 8b from set 2" << std::endl
			<< "5 - exercise 16 from set 3" << std::endl
			<< "6 - exercise 18 from set 3" << std::endl
			<< "============================"<< std::endl
			<< "Please provide your answer: ";
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
			case 2:
				ex_0207();
				break;
			case 3:
				ex_0208_a();
				break;
			case 4:
				ex_0208_b();
				break;
			case 5:
				ex_0316();
				break;
			case 6:
				ex_0318();
				break;
			default:
			case 0:
				keep_going = false;
		}


	}

	return 0;
}