double ex_0207_car_trip(double km_distance) {
	const double failure_rate = 0.0001;
	return 100 - km_distance * failure_rate;
}