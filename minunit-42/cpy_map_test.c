#include "../srcs/utils.h"
#include "../srcs/so_long.h"
#include "../srcs/get_next_line/get_next_line.h"
#include "../srcs/libft/srcs/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "minunit.h"

MU_TEST_SUITE(test)
{
    //ARRANGE
    t_map       *map;
    t_map       *cpy;
    int         fd              = open("maps_test/valid_map.ber", O_RDONLY);

    //ACT
    map = get_map(fd);
    cpy = cpy_map(map);
    close(fd);

    //ASSERTS
    while (map->next)
    {
        mu_assert_string_eq(map->cols, cpy->cols);
        mu_assert_int_eq(map->line, cpy->line);
        mu_assert_int_eq(map->amount_cols, cpy->amount_cols);
        map = map->next;
        cpy = cpy->next;
    }
    while (map->back)
        map = map->back;
    while (cpy->back)
        cpy = cpy->back;
    clear_map(&map, free);
    clear_map(&cpy, free);
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