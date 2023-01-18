#include "test_mandatory.h"

MU_TEST_SUITE(passing_a_str_with_dot_ber_should_be_zero)
{
    //ARRANGE
    int         result;
    char        *s1                 = "test.ber";
    char        *set                = ".ber";
    int         expected            = 0;

    //ACT
    result = check_extension(s1, set);

    //ASSERTS
    mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(passing_a_str_no_dot_ber_should_be_one)
{
    //ARRANGE
    int         result;
    char        *s1                 = "test";
    char        *set                = ".ber";
    int         expected            = 1;

    //ACT
    result = check_extension(s1, set);

    //ASSERTS
    mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(passing_a_str_ber_dot_ber_should_be_zero)
{
    //ARRANGE
    int         result;
    char        *s1                 = "ber.ber";
    char        *set                = ".ber";
    int         expected            = 0;

    //ACT
    result = check_extension(s1, set);

    //ASSERTS
    mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(passing_a_empty_str_should_be_1)
{
    //ARRANGE
    int         result;
    char        *s1                 = "";
    char        *set                = ".ber";
    int         expected            = 1;

    //ACT
    result = check_extension(s1, set);

    //ASSERTS
    mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(passing_a_str_dot_ber_only_should_be_1)
{
    //ARRANGE
    int         result;
    char        *s1                 = ".ber";
    char        *set                = ".ber";
    int         expected            = 1;

    //ACT
    result = check_extension(s1, set);

    //ASSERTS
    mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(passing_a_path_a_str_dot_ber_only_should_be_1)
{
    //ARRANGE
    int         result;
    char        *s1                 = "/path/.ber";
    char        *set                = ".ber";
    int         expected            = 1;

    //ACT
    result = check_extension(s1, set);

    //ASSERTS
    mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(passing_a_path_a_str_map_dot_ber_should_be_0)
{
    //ARRANGE
    int         result;
    char        *s1                 = "/path/map.ber";
    char        *set                = ".ber";
    int         expected            = 0;

    //ACT
    result = check_extension(s1, set);

    //ASSERTS
    mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_a_str_with_dot_ber_should_be_zero);
    MU_RUN_TEST(passing_a_str_no_dot_ber_should_be_one);
    MU_RUN_TEST(passing_a_str_ber_dot_ber_should_be_zero);
    MU_RUN_TEST(passing_a_empty_str_should_be_1);
    MU_RUN_TEST(passing_a_str_dot_ber_only_should_be_1);
    MU_RUN_TEST(passing_a_path_a_str_dot_ber_only_should_be_1);
    MU_RUN_TEST(passing_a_path_a_str_map_dot_ber_should_be_0);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}