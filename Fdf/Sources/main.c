#include "Fdh.h"

int main(int ac, char **av)
{
    t_img   *img;
    t_map   *map;

    if (ac == 2)
    {
        init_map(&map);
        parser(&map, av[1]);
        init_mlx(&img);
        draw(&img, &map);
        free_fdf(&img, &map);
    }
    return (0)
}