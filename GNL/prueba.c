#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

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
    return (free(*line), *line = dup_line, 0);
}
int main (int ac, char **av)
{
    if (ac == 3 || ac == 4)
    {
        int j;
        if (ac == 4)
            j = atoi(av[3]);
        else
            j = BUFFER_SIZE + 1;

        char Buffer[j];
        char *line = av[2];
        int i = 0;
        strcpy(Buffer, av[1]);

        while (Buffer[i] != '\n' && Buffer[i] != '\0')
            i++;
        if (Buffer[i] != '\n')
            i++;
        
        
        dispenser(&line, &Buffer, strlen(line), i);
        printf("%s\n%s\n", line, Buffer);
    }
    return (0);
}