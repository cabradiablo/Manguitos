#ifndef FT_PRINTF_H
# define FT_PRINTF_H



//ft_printf.c
int ft_args_chekcer(char const *format);
int ft_printf(char const *format, ...);

//put.c
int ft_putnbr_base_fd(int nbr, char *base);
int ft_puthex_base_fd(int nbr, char *base);
int ft_putptr_fd(int nbr, char *base);
int ft_putstr(int nbr, char *base);
int ft_putchar(int nbr, char *base);

//UTILS   utils.c
int ft_error(char *msg);

#endif