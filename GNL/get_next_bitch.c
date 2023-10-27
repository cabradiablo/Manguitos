#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int   dispenser(char **line, char *Buffer, int  *len, int size)
{
    char	*dup;
    
    while (Buffer[size] != '\n' && Buffer[size] != '\0')
        size++;
    if (Buffer[size] == '\n')
        size++;
    dup = malloc(sizeof(char) * (++size + *len));
    if (!dup)
    	return (free(line) , 1);
    dup[*len + size - 1] = '\0';
    while (--size - 1 >= 0)
        dup[*len + size - 1] = Buffer[size - 1];
    while (--(*len) >= 0 && *line)
    	dup[*len] = (*line)[*len];
    return (free(*line), *line = dup, 0);
}

char    *get_next_line(int fd)
{
    char    static Buffer[BUFFER_SIZE + 1];
    char    tmp[BUFFER_SIZE + 1];
    char    *line;
    int     bytes;

    line = NULL;
    bytes = 1;
    while (1)
    {
        if (bytes)
            dispenser(&line, Buffer, &bytes, 0);
        bytes = read(fd, tmp, BUFFER_SIZE);
        if (bytes <= 0)
            return (free(line), NULL);
        bytes = 0;
        while (line && line[bytes] != '\0')
            bytes++;
        if (dispenser(&line, Buffer, &bytes, 0) == 1)
            return (NULL);   
        if (line[bytes] == '\n')
            break;
    }
    return (line);
}
int main(int ac, char **av)
{ 
    int fd = open("hola", O_RDONLY);
    //close(fd);
    printf("---%s\n", get_next_line(fd));
    printf("---%s\n", get_next_line(fd));
    printf("---%s\n", get_next_line(fd));
   
    // if (ac == 1)
    // {
        // (void)av;
        // int fd = open("hola", O_RDONLY);
        // char *line;
        // while (1)
        // {
            // line = get_next_line(fd);
            // printf("%s\n", line);
            // free(line);
            // if (!line)
                // break ;
        // }
    // }
    // return (0);
}
