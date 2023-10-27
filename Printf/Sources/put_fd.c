//#include "ft_printf.h"
#include <unistd.h>

int ft_putchar_fd(int fd, char c)
{
    return write(fd, &c, 1);
}

int ft_putstr_fd(int fd, char *msg)
{
    int count = 0;
    
    while (*msg)
        count += ft_putchar_fd(fd, *msg++);
    return count;
}
int ft_putnbr_base_fd(int fd, int nbr)
{
    int     flag;
    long    result;

    while ()
    {}
}