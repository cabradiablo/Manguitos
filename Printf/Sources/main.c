#include "ft_printf.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int count = ft_putstr_fd(0, av[1]);
    }
    return 0;
}
