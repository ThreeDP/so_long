#include "test_mandatory.h"

MU_TEST_SUITE(test)
{
    //ARRANGE
    int         i               = 0;
    t_map       *map;
    t_map       *fmap;
    int         fd              = open("maps_test/valid_map.ber", O_RDONLY);
    char        *exp_cols[6];
    exp_cols[0]                 = "111111111111";
    exp_cols[1]                 = "1XXXXXXXXXX1";
    exp_cols[2]                 = "1X111XXXXXX1";
    exp_cols[3]                 = "1XXX111XXXX1";
    exp_cols[4]                 = "1XXX111XXXS1";
    exp_cols[5]                 = "111111111111";

    //ACT
    map = get_map(fd);
    fmap = map;
    map = map->next;
    map = map->next;
    map = map->next;
    map = map->next;
    map_path(map, 3);

    while (map->back)
        map = map->back;

    //ASSERTS
    while (map)
    {
        mu_assert_string_eq(exp_cols[i++], map->cols);
        map = map->next;
    }
    clear_map(&fmap, free);
}

MU_TEST_SUITE(test2)
{
    //ARRANGE
    int         i               = 0;
    t_map       *map;
    t_map       *fmap;
    int         fd              = open("maps_test/close_collecs.ber", O_RDONLY);
    char        *exp_cols[6];
    exp_cols[0]                 = "111111111111";
    exp_cols[1]                 = "1XXXXXXXXXX1";
    exp_cols[2]                 = "1X111XXXXXX1";
    exp_cols[3]                 = "1XXX111X1S11";
    exp_cols[4]                 = "1XXX111X10C1";
    exp_cols[5]                 = "111111111111";

    //ACT
    map = get_map(fd);
    fmap = map;
    map = map->next;
    map = map->next;
    map = map->next;
    map = map->next;
    map_path(map, 3);

    while (map->back)
        map = map->back;

    //ASSERTS
    while (map)
    {
        mu_assert_string_eq(exp_cols[i++], map->cols);
        map = map->next;
    }
    clear_map(&fmap, free);
}

MU_TEST_SUITE(test3)
{
    //ARRANGE
    int         i               = 0;
    t_map       *map;
    t_map       *fmap;
    int         fd              = open("maps_test/exit_close.ber", O_RDONLY);
    char        *exp_cols[6];
    exp_cols[0]                 = "111111111111";
    exp_cols[1]                 = "1XXXXXXXXXX1";
    exp_cols[2]                 = "1X111XXXXXX1";
    exp_cols[3]                 = "1XXX111X1111";
    exp_cols[4]                 = "1XXX111X10E1";
    exp_cols[5]                 = "111111111111";

    //ACT
    map = get_map(fd);
    fmap = map;
    map = map->next;
    map = map->next;
    map = map->next;
    map = map->next;
    map_path(map, 3);

    while (map->back)
        map = map->back;

    //ASSERTS
    while (map)
    {
        mu_assert_string_eq(exp_cols[i++], map->cols);
        map = map->next;
    }
    clear_map(&fmap, free);
}

MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test);
    MU_RUN_TEST(test2);
    MU_RUN_TEST(test3);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}