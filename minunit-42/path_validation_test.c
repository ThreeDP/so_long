#include "../srcs/utils.h"
#include "../srcs/so_long.h"
#include "../srcs/get_next_line/get_next_line.h"
#include "../srcs/libft/srcs/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include "minunit.h"

void	unset_aux(t_data *data[])
{
	int	i;

	i = 0;
	while (i < 4)
		free(data[i++]);
}

void    unset(t_info *info)
{
    int i;

    i = 0;
    unset_aux(info->collec);
    unset_aux(info->exit);
    unset_aux(info->wall);
    while (i < 4)
        unset_aux(info->player[i++]);
    free(info->floor);
    clear_map(&info->map, free);
    free(info);
}

MU_TEST_SUITE(test)
{
    //ARRANGE
    t_info      *info           = ft_newinfo();
    int         result;
    char        err             = 'A';
    int         expected        = 0;
    int         fd              = open("maps_test/valid_map.ber", O_RDONLY);

    //ACT
    info->map = get_map(fd);
    close(fd);
    result = path_validation(info->map, info);

    //ASSERTS
    mu_assert_int_eq(expected, result);
    mu_assert_int_eq(err, info->err);
    unset(info);
}

MU_TEST_SUITE(test1)
{
    //ARRANGE
    t_info      *info           = ft_newinfo();
    char        err             = 'F';
    int         result;
    int         expected        = 1;
    int         fd              = open("maps_test/close_collecs.ber", O_RDONLY);

    //ACT
    info->map = get_map(fd);
    close(fd);
    result = path_validation(info->map, info);

    //ASSERTS
    mu_assert_int_eq(expected, result);
    mu_assert_int_eq(err, info->err);
    unset(info);
}

MU_TEST_SUITE(test2)
{
    //ARRANGE
    t_info      *info           = ft_newinfo();
    char        err             = 'F';
    int         result;
    int         expected        = 1;
    int         fd              = open("maps_test/exit_close.ber", O_RDONLY);

    //ACT
    info->map = get_map(fd);
    close(fd);
    result = path_validation(info->map, info);

    //ASSERTS
    mu_assert_int_eq(expected, result);
    mu_assert_int_eq(err, info->err);
    unset(info);
}


MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test);
    MU_RUN_TEST(test1);
    MU_RUN_TEST(test2);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}