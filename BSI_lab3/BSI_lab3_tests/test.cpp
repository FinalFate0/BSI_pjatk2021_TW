#include "pch.h"
#include "../BSI_lab3/bsi_exercises.h"


TEST(factorialTest, PositiveInput) {
	EXPECT_EQ(factorial(5), 120);
}

TEST(factorialTest, ZeroInput) {
	EXPECT_EQ(factorial(0),1);
}

TEST(factorialTest, NegativeInput) {
	EXPECT_EQ(factorial(-3), -3);
}

TEST(binominalCoefficientTest, KOneSmallerThanN) {
	EXPECT_EQ(binominal_coefficient(5, 4), 5);
}

TEST(binominalCoefficientTest, KBiggerThanN) {
	EXPECT_EQ(binominal_coefficient(4, 5), 5);
}

TEST(unreliabilityTest, isOneMinusReliability) {
	EXPECT_DOUBLE_EQ(unreliability(0.84), 0.16);
}

TEST(reliabilityTest, TimeEqualsFailureRate) {
	EXPECT_DOUBLE_EQ(reliability(1, 1), 0.36787944117144232159552377016146);
}

TEST(reliabilityTest, PositiveValuesGiveLessThanOne) {
	EXPECT_DOUBLE_EQ(reliability(1000, 0.0001), 0.90483741803595952);
}

TEST(mttfEstReliabilityTimeTest, PositiveValues) {
	EXPECT_DOUBLE_EQ(mttf_est_from_rel_time(0.74, 8), 26.568796714909578);
}

TEST(fRateFromMttfTest, outputEqualsOneOverInput) {
	EXPECT_DOUBLE_EQ(fr_from_mttf(8.0), 0.125);
}


TEST(parallelSystem, KsmallerThanNAndNsmallerThanKEqual) {
	EXPECT_DOUBLE_EQ(
		parallel_sys_rel_k_out_of_n(4, 5, 0.9),
		parallel_sys_rel_k_out_of_n(5, 4, 0.9));
}

TEST(parallelSystem, ZeroReliabilityIsZeroSysReliability) {
	EXPECT_DOUBLE_EQ(parallel_sys_rel_k_out_of_n(4, 5, 0), 0);
}


TEST(seriesSystem, MinRelZeroRezultsInZero) {
	EXPECT_EQ(max_comp_series_system(0.85, 0.0), 0);
}

TEST(seriesSystem, CompRelEqalToSysResultsInOneComp) {
	EXPECT_EQ(max_comp_series_system(0.9, 0.9), 1);
}
