#include "test_bonus.h"

MU_TEST_SUITE(test)
{
    //ARRANGE
    t_info      info;
    int         i               = 0;
    int         fd              = open("maps_test/valid_map.ber", O_RDONLY);
    char        *exp_cols[6];
    exp_cols[0]                 = "111111111111";
    exp_cols[1]                 = "1000000C0001";
    exp_cols[2]                 = "1C111000E001";
    exp_cols[3]                 = "100011100C01";
    exp_cols[4]                 = "100P111000E1";
    exp_cols[5]                 = "111111111111";

    //ACT
    info.map = get_map(fd);
    insert_enemies(&info);

    //ASSERTS
    while (info.map)
    {
        mu_assert_string_eq(exp_cols[i++], info.map->cols);
        info.map = info.map->next;
    }
    clear_map(&info.map, free);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}