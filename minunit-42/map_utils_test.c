#include "../srcs/utils.h"
#include "../srcs/so_long.h"
#include "../srcs/get_next_line/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include "minunit.h"

MU_TEST_SUITE(passing_char_0_to_the_is_path_function_should_be_1)
{
    //ARRANGE
    int         i               = 0;
    t_map       *map;
    t_map       *fmap;
    t_map       *back           = NULL;
    int         fd              = open("maps_test/valid_map.ber", O_RDONLY);
    char        *exp_cols[6];
    size_t      amout_cols[]     = {12, 12, 12, 12, 12, 12};
    exp_cols[0]                 = "111111111111";
    exp_cols[1]                 = "1000000C0001";
    exp_cols[2]                 = "1C1110000001";
    exp_cols[3]                 = "100011100C01";
    exp_cols[4]                 = "100P111000E1";
    exp_cols[5]                 = "111111111111";

    //ACT
    map = get_map(fd);
    fmap = map;

    //ASSERTS
    while (map)
    {
        mu_assert(back == map->back, "address is different");
        mu_assert_int_eq(amout_cols[i], map->amout_cols);
        mu_assert_string_eq(exp_cols[i++], map->cols);
        back = map;
        map = map->next;
    }
    clear_map(&fmap, free);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(passing_char_0_to_the_is_path_function_should_be_1);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}