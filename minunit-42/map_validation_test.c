#include "../srcs/utils.h"
#include "../srcs/so_long.h"
#include "../srcs/get_next_line/get_next_line.h"
#include "../srcs/libft/srcs/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "minunit.h"

MU_TEST_SUITE(passing_a_map_valid_should_be_1)
{
    //ARRANGE
    int         result;
    t_map       *map;
    t_info      *info           = ft_newinfo();
    int         expected        = 1;
    int         collec          = 3;
    int         fd              = open("maps_test/valid_map.ber", O_RDONLY);

    //ACT
    map = get_map(fd);
    result = map_validation(map, &info);

    //ASSERTS
    mu_assert_int_eq(expected, result);
    mu_assert_int_eq(collec, info->c);
    clear_map(&map, free);
    if (info)
        free(info);
}

MU_TEST_SUITE(passing_a_map_with_no_1_in_the_top_wall_should_be_0)
{
    //ARRANGE
    int         result;
    t_map       *map;
    t_info      *info           = ft_newinfo();
    int         collec          = 0;
    int         expected        = 0;
    int         fd              = open("maps_test/x_in_top_wall.ber", O_RDONLY);

    //ACT
    map = get_map(fd);
    result = map_validation(map, &info);

    //ASSERTS
    mu_assert_int_eq(expected, result);
    mu_assert_int_eq(collec, info->c);
    clear_map(&map, free);
    if (info)
        free(info);
}

MU_TEST_SUITE(passing_a_map_with_no_1_in_the_down_wall_should_be_0)
{
    //ARRANGE
    int         result;
    t_map       *map;
    t_info      *info           = ft_newinfo();
    int         collec          = 3;
    int         expected        = 0;
    int         fd              = open("maps_test/y_in_down_wall.ber", O_RDONLY);

    //ACT
    map = get_map(fd);
    result = map_validation(map, &info);

    //ASSERTS
    mu_assert_int_eq(expected, result);
    mu_assert_int_eq(collec, info->c);
    clear_map(&map, free);
    if (info)
        free(info);
}

MU_TEST_SUITE(passing_a_map_no_rectangle_should_be_0)
{
    //ARRANGE
    int         result;
    t_map       *map;
    t_info      *info           = ft_newinfo();
    int         collec          = 0;
    int         expected        = 0;
    int         fd              = open("maps_test/no_square.ber", O_RDONLY);

    //ACT
    map = get_map(fd);
    result = map_validation(map, &info);

    //ASSERTS
    mu_assert_int_eq(expected, result);
    mu_assert_int_eq(collec, info->c);
    clear_map(&map, free);
    if (info)
        free(info);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_a_map_valid_should_be_1);
    MU_RUN_TEST(passing_a_map_with_no_1_in_the_top_wall_should_be_0);
    MU_RUN_TEST(passing_a_map_with_no_1_in_the_down_wall_should_be_0);
    MU_RUN_TEST(passing_a_map_no_rectangle_should_be_0);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}