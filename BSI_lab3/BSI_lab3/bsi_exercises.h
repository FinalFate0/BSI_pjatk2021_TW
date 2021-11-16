#ifndef BSI_EXERCISES_H
#define BSI_EXERCISES_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "bsi_functions.h"

const double EX28_MTTF = 1140;
const double EX27_FR = 0.0001;
const double EX26_FR = 0.7;


void ex_0204() {
	std::string rel_string = "";
	double reliability = 0;
	std::string time_string = "";
	double time = 0;
	double mtbf = 0;
	double failure_rate = 0;

	std::cout << "Please provide the required reliability - value between (0, 1): ";
	std::cin >> rel_string;
	try {
		reliability = std::stod(rel_string);
		if (reliability >= 1 || reliability <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument e) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}
	


	std::cout 
		<< "Please provide the number of hours for which " << std::endl
		<< "device has to maintain required reliability - value > 0: ";
	std::cin >> time_string;
	try {
		time = std::stod(time_string);
		if (time <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument e) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}


	mtbf = mttf_est_from_rel_time(reliability, time);
	std::cout << std::endl << "Minimum mean time before failures is: " << mtbf << std::endl;

	failure_rate = fr_from_mttf(mtbf);
	std::cout << std::endl << "Maximum failure rate is: " << failure_rate << std::endl;
	
	return;

}

void ex_0207() {
	double rel = 0;
	double km = 0;
	std::string km_str = "";

	std::cout << "Please provide desired distance - value must be positive: ";
	std::cin >> km_str;
	try {
		km = std::stod(km_str);
		if (km <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument e) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}

	rel = reliability(km, EX27_FR);

	std::cout << std::endl << "Probability that the destination is reached: " << rel * 100 << "%" << std::endl;

	return;
}

void ex_0208_a() {

	double t_hr = 0;
	double u_rel = 0;
	std::string t_hr_str = "";

	std::cout << "Please provide desired time in hours - value must be positive: ";
	std::cin >> t_hr_str;
	try {
		t_hr = std::stod(t_hr_str);
		if (t_hr <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument e) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}

	u_rel = unreliability(
		reliability(
			t_hr,
			fr_from_mttf(EX28_MTTF)
		)
	);

	std::cout << std::endl << "Probability of failure during a " << t_hr << "-hour flight:" << u_rel * 100 << "%" << std::endl;

	return;
}

void ex_0208_b() {
	double des_rel = 0;
	std::string des_rel_s = "";
	double max_t = 0;
	
	std::cout << "Please provide desired reliability - value between (0, 1): ";
	std::cin >> des_rel_s;
	try {
		des_rel = std::stod(des_rel_s);
		if (des_rel >= 1 || des_rel <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}
	max_t = max_operation_time(EX28_MTTF, des_rel);

	std::cout << std::endl << "Maximum duration of a flight with reliability >= " << des_rel << ":" << max_t << " hours" << std::endl;

	return;
}

void ex_0316() {
	double system_reliability = 0;

	int n = 0;
	std::string n_str = "";
	int k = 0;
	std::string k_str = "";
	double single_rel = 0;
	std::string rel_str = "";

	std::cout << "Please provide the total amount devices - value must be positive: ";
	std::cin >> n_str;
	try {
		n = std::stoi(n_str);
		if (n <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}

	std::cout << "Please provide the required amount of functional devices - value must be positive and not bigger than total: ";
	std::cin >> k_str;
	try {
		k = std::stoi(k_str);
		if (k <= 0 && k > n) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}

	std::cout << "Please provide the required reliability of a single device - value between (0, 1): ";
	std::cin >> rel_str;
	try {
		single_rel = std::stoi(rel_str);
		if (single_rel >= 1 || single_rel <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}

	system_reliability = parallel_sys_rel_k_out_of_n(k, n, single_rel);

	std::cout << std::endl << "Probability of system success: " << system_reliability * 100 << "%" << std::endl;

	return;
}

void ex_0318() {
	int n_components = 0;

	double min_rel = 0;
	std::string min_rel_str = "";
	double comp_rel = 0;
	std::string comp_rel_str = "";

	std::cout << "Please provide the reliability of a single component - value between (0, 1): ";
	std::cin >> comp_rel_str;
	try {
		comp_rel = std::stod(comp_rel_str);
		if (comp_rel >= 1 || comp_rel <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}

	std::cout << "Please provide the minimum required system reliability - value between (0, 1): ";
	std::cin >> min_rel_str;
	try {
		min_rel = std::stoi(min_rel_str);
		if (min_rel >= 1 || min_rel <= 0) {
			throw std::out_of_range("");
		}
	}
	catch (std::invalid_argument) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}

	n_components = max_comp_series_system(min_rel, comp_rel);

	std::cout << std::endl << "Maximum number of components allowed: " << n_components << std::endl;

	return;
}

#endif
