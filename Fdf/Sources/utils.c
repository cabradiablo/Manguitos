#include "Fdh.h"
#include "test.h"

char    *strjoin(char *head, char *tail)
{
    int     i;
    int     j;
    char    *result;
    
    i = -1;
    j = -1;
    while (*head && head[++i])
        ;
    while (*tail && tail[++j])
        ;
    if (i == -1 || j == -1)
        return (NULL);
    result = (char *)malloc(i + j + 1);
    if (!result)
        return (NULL);
    result[i + j] = '\0';
    while (--j >= 0)
        result[j + i] = tail[j];
    while (--i >= 0)
        result[i] = head[i];
    return (result);
}

void    open_map(char *av, int *fd)
{
    char    *file;

    file = strjoin("maps/", av);
    if (!file)
        return (NULL);
    *fd = open(file, O_RDONLY);
    if (*fd == -1)
        return (NULL);
    free(file);
}