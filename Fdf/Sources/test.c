#include "test.h"


int main(int ac , char **av)
{
    if (ac == 3)
    {
        char *head = av[1];
        char *tail = av[2];

        char * result = strjoin(head, tail);
        printf("%p\n", result);
    }
    return (0);
}