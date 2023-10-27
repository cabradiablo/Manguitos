typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_point {
    int		height;
    int		*width;
}				t_point;

typedef struct s_map {
    t_point    *dim;
	int		**data[2];
    
}				t_map;
