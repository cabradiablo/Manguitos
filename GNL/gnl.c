#ifndef BUFFER_SIZE
# define BUFFER_SIZE 6
#endif

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int dispenser(char **line, char **Buffer, int  len, int size)
{
    char	*dup_line;
    char    *dup_Buffer;
    int     count;

    dup_Buffer = *Buffer;
    dup_line = malloc(sizeof(char) * (size + len + 1));
    if (!dup_line)
    	return (free(line) , 1);
    dup_line[len + size] = '\0';
    count = -1;
    while (++count + size < BUFFER_SIZE)    
        dup_Buffer[count] = *Buffer[size + count];
    while (++count <= BUFFER_SIZE)    
        dup_Buffer[count] = *Buffer[size + count]; 
    count = -1;
    while (++count < len)
    	dup_line[count] = *line[count];
    while (count <= size + len)
        dup_line[count] = *Buffer[count - len - 1];
    *Buffer = dup_Buffer;
    return (free(*line), free(dup_line), *line = dup_line, 0);
}

char    *get_next_line(int fd)
{
    char    static Buffer[BUFFER_SIZE + 1];
    char    *line;
    int     len;
    int     size;
    
    line = NULL;
    len = 42;
    size = 0;
    while (1)
    {   
        while (Buffer[size] != '\0' && ++len && Buffer[size] != '\n')
            size++;
        if (Buffer[size] == '\n')
            size++;
        if (size < BUFFER_SIZE || len == 42) 
            len = read(fd, Buffer, BUFFER_SIZE);
        if (len == -1)
            return (NULL);
        len = 0;
        while (line[len] != '\0')
            len++;
        if (dispenser(&line, &Buffer, 0, size) == 7)
            break ;
    }
    return (line);
}
int main(int ac, char **av)
{ 
   
    if (ac == 1)
    {
        (void)av;
        int fd = open("hola", O_RDONLY);
        char *line;
        while (1)
        {
            line = get_next_line(fd);
            printf("%s", line);
            if (!line)
                break ;
            free(line);
        }
    }
    return (0);
}
