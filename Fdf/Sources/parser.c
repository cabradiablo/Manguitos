#include "Fdh.h"
#include "test.h"

void    realloc_map(int **data[2], char *line, int row)
{
    
}
int procces_line(int **data, char *line, int row)
{
    int     width;

    width = -1;
    while (*line >= '0' && *line <= '9' || *line[*i] == '*')
    {
            width++;
            realloc_map(data, line, row); //revisar que no se pase del int en el atoi de dentro
             //meter lo de abajo en esa funcion
            //map->data[row][width][0] = ft_atoi(line);
            //map->data[row][width][1] = ft_atoi_color(line); //line perfecta para realloc
            //(line[i] == '*')
            while (*line == ' ')
                *i++;
    }
    map->dim->width[row] = width;
}
void    parser(t_map **map, char *av)
{
    char    *line;
    int     fd;
    int     row;

    open_map(av, &fd);
    if (fd == -1)
        return (-1);
    row = -1;
    while (1)
    {
        line = get_next_line(fd);
        if (*line && procces_line(&map->data, line, ++row))
            free(line);
        else
            break ;
    }
    map->dim->height = row;
}