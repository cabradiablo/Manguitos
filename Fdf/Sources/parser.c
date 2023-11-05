


void    ft_validinput(char  c, char next, int *datadim_width) //mirar return dentro de los ifs
{
    if ((c >= '0' && c <= '9') || c == '*' || c == '-' || c == '+')
    {
        if (!next || next == ' ' || next == ',')
            datadim_width++;
        return ;
    }
    if ((c >= '0' && c <= '9') || c == '*' || c == '-' || c == '+')
    {
        if (!next || next == ' ' || next == ',')
            datadim_width++;
        return ;
    }
    if ((c >= '0' && c <= '9') || c == '*' || c == '-' || c == '+')
    {
        if (!next || next == ' ' || next == ',')
            datadim_width++;
        return ;
    }
    ft_error();
}


char *get_height(char *line, int *nbr)
{
    int neg = 1;
    int num = 0;

    while (*line == ' ' || *line == '\n' || *line == '\t' || *line == '\v'
            || *line == '\f' || *line == '\r')
        *line++;
    if (*line == '-' || *line == '+')
    {
        if (*line == '-')
            neg *= -1;
        *line++;
    }
    while (*line >= '0' && *line <= '9')
    {
        num = num * 10 + (*line - '0');
        *line++;
    }
    *nbr = num;
    return (line);
}


int get_color(char *line)
{
    if (*line == ',' && *line + 1 == '0' && *line + 2 == 'x')
        *line += 3;
    else

}

void    process_line(int **data[3], int *datadim_width, int row,  char *line)
{
    int colum;

    colum = -1;
    if (*line == '*')
        set_hole(line, data[row][++colum][0])
    else
    {
        get_height(line, data[row][++colum][1]);
        get_color(line, data[row][colum][2]);
    }
    while (line == ' ')
        *line++;
}

void    realloc_matrix(int **data[3], int *datadim_width, int row,  char *line)
{
    int **temp[3];
    int     i;
    
    temp[3] = (int **)malloc(sizeof(int *) * row);
    if (free_data(data) && !temp)
        return (NULL);
    data = temp;
    i = -1;
    while (line[++i])
        ft_validinput(line[i], line[line[i + 1]], *datadim_width);
    data[row] = (int *)malloc(sizeof(int) * (*datadim_width));
    if (!data[row])
        return ;
    while (*line)
        procces_line(data[row], datadim_width, line);
}

void    parser(t_map **map, char *filename)
{
    char    *line;
    int     fd;
    int     row;

    open_map(filename, &fd);
    if (fd == -1)
        return ;
    row = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        realloc_data((*map)->data, (*map)->dim->width[row], row, line);
        free(line);
        row++;
    }
    (*map)->dim->height = row;
}
