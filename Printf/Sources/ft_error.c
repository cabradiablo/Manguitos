#include "ft_printf.h"

int ft_error(char *msg)
{
    ft_putstr_fd(2, msg);
    return (0);
}