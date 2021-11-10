#include <cmath>

double ex_0207_car_trip(double km_distance) {
	const double failure_rate = 0.0001;
	return 100 - km_distance * failure_rate;
}

double ex_0208_airliner_a(double MTTF_t_hrs, int hrs) {
	double failure_rate = 1 / MTTF_t_hrs;
	double reliability_a = std::exp(-failure_rate * hrs);
	return 1-reliability_a;

}

//TODO
double ex_0208_airliner_b(double MTTF_t_hrs, double desired_reliability) {
	double failure_rate = 1 / MTTF_t_hrs;
	double time;
	//double reliability_b = std::exp(-failure_rate * time);

	return time;
}