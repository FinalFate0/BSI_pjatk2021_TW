#include <cmath>

double ex_0207_car_trip(double km_distance) {
	const double failure_rate = 0.0001;
	return 1 - std::exp(failure_rate * km_distance);

	
}