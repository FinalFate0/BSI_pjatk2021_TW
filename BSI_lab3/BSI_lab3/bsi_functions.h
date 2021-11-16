#ifndef BSI_REL_MATH_H
#define BSI_REL_MATH_H

#include <cmath>
#include <vector>
#include <sstream>


/**
* This function calculates maximum number of identical components in a system
* so that its reliability doesn't fall bellow required minimum
* 
* @param[in]	min_sys_rel		minimum system reliability
* @param[in]	comp_rel		reliability of a single component
* 
* @return		count			maximum number of components
* 
*/

int max_comp_series_system(double min_sys_rel, double comp_rel) {
	int count = 0;
	int s_rel = 1;
	do {
		s_rel *= comp_rel;
		if (s_rel < min_sys_rel && min_sys_rel != 0)
			break;
		count++;
	} while (true);
}


/**
* This function calculates maximum operation time for desired reliability and
* mean time to failure given that the failure rate is constant
* 
* @param[in]		mttf		mean time to failure
* @param[in]	   des_rel		desired reliability
* 
* @return			time		maximum time device can operate with given reliability
* 
*/
double max_operation_time(const double mttf, const double des_rel) {
	double time = -std::log(des_rel) * mttf;
	return time;
}


/**
* This function calculates the estimation of mean time to failure for
* device with required reliability for work time t
* 
* @param[in]	   rel			required reliability
* @param[in]		t			time for which reliability is to be mainained
* 
* @retur		  mttf			estimated mean time to failure
* 
*/
double mttf_est_from_rel_time(double rel, double t) {
	double mttf = -t / std::log(rel);
	return mttf;
}

/**
* This function changes MTTF to failure rate given that failure rate is
* constant in time
* 
* @param[in]		mttf		mean time to failure
* 
* @return			fr			failure rate
* 
*/
double fr_from_mttf(double mttf) {
	double fr = 1 / mttf;
	return fr;
}



/**
* This function calculates a reliability given constant failure rate,
* based on the exponential distribution
* 
* @param[in]		t		time that reliability is calculated for
* @param[in]	  f_rate	constant failure rate for a period of time
*
* @return			r		calculated reliability
* 
* <b> important: </b> it is up to the caller to provide a proper ratio
* of t and time for which f_rate is given
* 
*/

double reliability(const double t, const double f_rate) {
	double r = 0;
	r = std::exp(-f_rate * t);
	return r;
}
/**
* This function returns unreliability of a system based on its reliability
*
* @param[in]		rel		system unreliability
* 
* @return			ur		calculated unreliability
* 
*/
double unreliability(const double rel) {
	double ur = 1 - rel;
	return ur;
}

/**
* @param[in]	n		a value which factorial of is to be returned
* @return		f		a factorial of n
*/
int factorial(int n) {
	if (n == 0)
		return 1;

	int f = 1;
	do {
		f *= n;
	} while (--n > 1);
	return f;
}

/**
* This function takes two int parameters and returns a binominal coefficient 
* of n choose k. If k > n they are switched
* 
* @param[in]	n			number of elements in set N
* @param[in]	k			size of subset of N
* 
* @return	 bin_coef		calculated binominal coefficient
* 
*/
int binominal_coefficient(int n, int k) {
	if (k > n) {
		int temp = k;
		k = n;
		n = temp;
	}
	int bin_coef = factorial(n) / (factorial(k) * factorial(n - k));
	return bin_coef;
}


/**
* This function calculates the reliability of a system composed of n elements,
* with the succes factor being: at least k of them are working. All elements
* are considered to have the same reliability
* 
* @param[in]		k			min number of components required to work
* @param[in]		n			total number of components
* @param[in]  single_comp_rel	reliability of a single component
*
* @return		sys_rel			reliability of the system
*/
double parallel_sys_rel_k_out_of_n(int k, int n, double single_comp_rel) {
	double sys_rel = 0;
	
	if (k > n) {
		int temp = k;
		k = n;
		n = temp;
	}

	while (k <= n) {
		sys_rel += binominal_coefficient(n, k)
			* std::pow(single_comp_rel, k)
			* std::pow(1 - single_comp_rel, n - k);
		k++;
	}

	return sys_rel;

}

#endif