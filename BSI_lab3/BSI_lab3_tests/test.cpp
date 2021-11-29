#include "pch.h"
#include "../BSI_lab3/bsi_exercises.h"
#include <cfenv>


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

TEST(seriesSystem, MinSysRelZeroRezultsInZero) {
	EXPECT_EQ(max_comp_series_system(0.85, 0.0), 0);
}

TEST(maxOperationTime, LnZeroGivesInfinity) {
	EXPECT_DOUBLE_EQ(max_operation_time(10, 0), std::numeric_limits<double>::infinity());
}

TEST(ex0204, WrongFormat) {
	testing::internal::CaptureStdout();
	std::istringstream iss("qwerty");
	std::cin.rdbuf(iss.rdbuf());
	ex_0204();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide the required reliability - value between (0, 1): \nWrong data format!\n");
}

TEST(ex0204, OutOfRange) {
	testing::internal::CaptureStdout();
	std::istringstream iss("2");
	std::cin.rdbuf(iss.rdbuf());
	ex_0204();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide the required reliability - value between (0, 1): \nValue out of range!\n");
}
TEST(ex0207, WrongFormat) {
	testing::internal::CaptureStdout();
	std::istringstream iss("qwerty");
	std::cin.rdbuf(iss.rdbuf());
	ex_0207();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide desired distance - value must be positive: \nWrong data format!\n");
}

TEST(ex0207, OutOfRange) {
	testing::internal::CaptureStdout();
	std::istringstream iss("-1");
	std::cin.rdbuf(iss.rdbuf());
	ex_0207();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide desired distance - value must be positive: \nValue out of range!\n");
}
TEST(ex0208a, WrongFormat) {
	testing::internal::CaptureStdout();
	std::istringstream iss("qwerty");
	std::cin.rdbuf(iss.rdbuf());
	ex_0208_a();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide desired time in hours - value must be positive: \nWrong data format!\n");
}

TEST(ex0208a, OutOfRange) {
	testing::internal::CaptureStdout();
	std::istringstream iss("-1");
	std::cin.rdbuf(iss.rdbuf());
	ex_0208_a();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide desired time in hours - value must be positive: \nValue out of range!\n");
}
TEST(ex0208b, WrongFormat) {
	testing::internal::CaptureStdout();
	std::istringstream iss("qwerty");
	std::cin.rdbuf(iss.rdbuf());
	ex_0208_b();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide desired reliability - value between (0, 1): \nWrong data format!\n");
}

TEST(ex0208b, OutOfRange) {
	testing::internal::CaptureStdout();
	std::istringstream iss("2");
	std::cin.rdbuf(iss.rdbuf());
	ex_0208_b();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide desired reliability - value between (0, 1): \nValue out of range!\n");
}
TEST(ex0316, WrongFormat) {
	testing::internal::CaptureStdout();
	std::istringstream iss("qwerty");
	std::cin.rdbuf(iss.rdbuf());
	ex_0316();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide the total amount devices - value must be positive: \nWrong data format!\n");
}

TEST(ex0316, OutOfRange) {
	testing::internal::CaptureStdout();
	std::istringstream iss("-1");
	std::cin.rdbuf(iss.rdbuf());
	ex_0316();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide the total amount devices - value must be positive: \nValue out of range!\n");
}
TEST(ex0318, WrongFormat) {
	testing::internal::CaptureStdout();
	std::istringstream iss("qwerty");
	std::cin.rdbuf(iss.rdbuf());
	ex_0318();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide the reliability of a single component - value between (0, 1): \nWrong data format!\n");
}

TEST(ex0318, OutOfRange) {
	testing::internal::CaptureStdout();
	std::istringstream iss("2");
	std::cin.rdbuf(iss.rdbuf());
	ex_0318();
	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ(output, "Please provide the reliability of a single component - value between (0, 1): \nValue out of range!\n");
}
