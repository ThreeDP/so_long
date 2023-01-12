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
    t_map       *fmap;
    t_map       *cpy;
    t_map       *fcpy;
    int         fd              = open("maps_test/valid_map.ber", O_RDONLY);

    //ACT
    map = get_map(fd);
    fmap = map;
    cpy = cpy_map(map);
    fcpy = cpy;
    close(fd);

    //ASSERTS
    while (map)
    {
        mu_assert_string_eq(map->cols, cpy->cols);
        mu_assert_int_eq(map->line, cpy->line);
        mu_assert_int_eq(map->n_cols, cpy->n_cols);
        map = map->next;
        cpy = cpy->next;
    }
    clear_map(&fmap, free);
    clear_map(&fcpy, free);
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