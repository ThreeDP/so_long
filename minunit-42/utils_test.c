#include "../srcs/utils.h"
#include "minunit.h"

MU_TEST_SUITE(passing_char_0_to_the_is_path_function_should_be_1)
{
    //ARRANGE
    char        c               = '0';
    int         expected_result = 1;
    int         result;
    
    //ACT
    result = is_path(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_1_to_the_is_path_function_should_be_0)
{
    //ARRANGE
    char        c               = '1';
    int         expected_result = 0;
    int         result;
    
    //ACT
    result = is_path(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_0_to_the_is_wall_function_should_be_0)
{
    //ARRANGE
    char        c               = '0';
    int         expected_result = 0;
    int         result;
    
    //ACT
    result = is_wall(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_1_to_the_is_wall_function_should_be_1)
{
    //ARRANGE
    char        c               = '1';
    int         expected_result = 1;
    int         result;
    
    //ACT
    result = is_wall(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_Z_to_the_is_collec_function_should_be_0)
{
    //ARRANGE
    char        c               = 'Z';
    int         expected_result = 0;
    int         result;
    
    //ACT
    result = is_collec(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_C_to_the_is_collec_function_should_be_1)
{
    //ARRANGE
    char        c               = 'C';
    int         expected_result = 1;
    int         result;
    
    //ACT
    result = is_collec(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_Z_to_the_is_exit_function_should_be_0)
{
    //ARRANGE
    char        c               = 'Z';
    int         expected_result = 0;
    int         result;
    
    //ACT
    result = is_exit(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_E_to_the_is_exit_function_should_be_1)
{
    //ARRANGE
    char        c               = 'E';
    int         expected_result = 1;
    int         result;
    
    //ACT
    result = is_exit(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_Z_to_the_is_player_function_should_be_0)
{
    //ARRANGE
    char        c               = 'Z';
    int         expected_result = 0;
    int         result;
    
    //ACT
    result = is_player(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(passing_char_P_to_the_is_player_function_should_be_1)
{
    //ARRANGE
    char        c               = 'P';
    int         expected_result = 1;
    int         result;
    
    //ACT
    result = is_player(c);

    //ASSERTS
    mu_assert_int_eq(expected_result, result);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_char_0_to_the_is_path_function_should_be_1);
    MU_RUN_TEST(passing_char_1_to_the_is_path_function_should_be_0);
    MU_RUN_TEST(passing_char_0_to_the_is_wall_function_should_be_0);
    MU_RUN_TEST(passing_char_1_to_the_is_wall_function_should_be_1);
    MU_RUN_TEST(passing_char_Z_to_the_is_collec_function_should_be_0);
    MU_RUN_TEST(passing_char_C_to_the_is_collec_function_should_be_1);
    MU_RUN_TEST(passing_char_Z_to_the_is_exit_function_should_be_0);
    MU_RUN_TEST(passing_char_E_to_the_is_exit_function_should_be_1);
    MU_RUN_TEST(passing_char_Z_to_the_is_player_function_should_be_0);
    MU_RUN_TEST(passing_char_P_to_the_is_player_function_should_be_1);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}