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

	std::cout << "Please provide required reliability - value between (0, 1): ";
	std::cin >> rel_string;
	try {
		reliability = std::stod(rel_string);
	}
	catch (std::invalid_argument) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}
	if (reliability >= 1 || reliability <= 0) {
		std::cout << std::endl << "Wrong reliability value!" << std::endl;
		return;
	}


	std::cout 
		<< "Please provide number of hours for which " << std::endl
		<< "device has to maintain reliability - value > 0: ";
	std::cin >> time_string;
	try {
		time = std::stod(time_string);
	}
	catch (std::invalid_argument e) {
		std::cout << std::endl << "Wrong data format!" << std::endl;
		return;
	}
	catch (std::out_of_range e) {
		std::cout << std::endl << "Value out of range!" << std::endl;
		return;
	}
	if (time <= 0) {
		std::cout << std::endl << "Wrong reliability value!" << std::endl;
		return;
	}

	mtbf = mttf_est_from_rel_time(reliability, time);
	std::cout << std::endl << "Minimum mean time before failures is: " << mtbf << std::endl;

	failure_rate = fr_from_mttf(mtbf);
	std::cout << std::endl << "Maximum failure rate is: " << failure_rate << std::endl;
	
	return;

}

void ex_0206_a() {
	double ur = 0;

	double t = 0;
	std::string t_str = "";

	ur = unreliability(
		reliability(t, EX26_FR)
	);
}

void ex_0207() {
	double rel = 0;
	double km = 0;
	std::string km_str = "";

	rel = reliability(km, EX27_FR);

	return;
}

void ex_0208_a() {

	double t_hr = 0;
	double u_rel = 0;

	u_rel = unreliability(
		reliability(
			t_hr,
			fr_from_mttf(EX28_MTTF)
		)
	);

}

void ex_0208_b() {
	double des_rel = 0;
	std::string des_rel_s = "";
	double max_t = 0;
	

	max_t = max_operation_time(EX28_MTTF, des_rel);

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


	system_reliability = parallel_sys_rel_k_out_of_n(k, n, single_rel);

	return;
}

void ex_0318() {
	int n_components = 0;

	double min_rel = 0;
	std::string min_rel_str = "";
	double comp_rel = 0;
	std::string comp_rel_str = "";

	n_components = max_comp_series_system(min_rel, comp_rel);

	return;
}

#endif
