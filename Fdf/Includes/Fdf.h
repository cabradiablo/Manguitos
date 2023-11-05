typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_dim 
{
    int		height;
    int		*width;
}				t_dim;

typedef struct s_map
{
    t_dim   *dim;
	int 	**data[2];
	int		interval_x[2];
	int		interval_y[2];
	int		interval_z[2];
    int     hole;
}	t_map;
