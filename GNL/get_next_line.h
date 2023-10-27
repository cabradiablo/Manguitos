#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    *get_next_line(int fd);

//GET_NEXT_LINE_UTILS   GET_NEXT_LINE_UTILS.c

#endif