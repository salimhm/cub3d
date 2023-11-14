/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmimi <shmimi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:28:47 by shmimi            #+#    #+#             */
/*   Updated: 2023/11/14 21:43:08 by shmimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 3
# define HEIGHT 3
# define MOVESPEED 1.2
# define ROTATION 0.0698132
# define WIDTH_SCREEN 2550
# define HEIGHT_SCREEN 1000

typedef struct s_parse_map
{
	char			**map;
	char			**dummy_map;
	char			**duplicates;
	int				count;
	int				player_x;
	int				player_y;
	int				flag;

}					t_parse_map;

typedef struct s_arg
{
	char			**elements;
	float			x;
	float			y;
	float			px;
	float			py;
	int				i;
	int				j;
	float			finalx;
	float			finaly;
	int				k;
	float			new_px;
	float			new_py;
	float			new_x;
	float			new_y;
	float			retation_angle;
	char			**map;
	float			r_angle;
	int				x_mouse;

}					t_map;

typedef struct s_data
{
	void			*img;
	char			*addr;
	void			*win;
	void			*mlx;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				is_up;
	int				is_down;
	int				is_left;
	int				is_right;
	double			new_x;
	double			new_y;
	double			xstep;
	double			ystep;
	double			incrmentx;
	double			incrmenty;
	double			hitwallx;
	double			hitwally;
	int				v_hit;
	int				h_hit;
	double			v;
	double			h;
	double			x;
	double			y;
	double			dis;
	double			fov;
	double			j;
	int				i;
	double			y_start;
	double			dis_hit_wall;
	double			y_end;
	double			point;
	double			newx;
	double			newy;
	double			verticalx;
	double			verticaly;
	double			horizontalx;
	double			horizontaly;
	t_map			*call;
	t_parse_map		*temp_essentials;
}					t_data;

typedef struct s_texture_north
{
	char			*img_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_texture_north;

typedef struct s_texture_south
{
	char			*img_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_texture_south;

typedef struct s_texture_west
{
	char			*img_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_texture_west;

typedef struct s_texture_east
{
	char			*img_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;
}					t_texture_east;

typedef struct s_texture_data
{
	char			*img_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_width;
	int				img_height;

	t_texture_north	north;
	t_texture_north	south;
	t_texture_north	west;
	t_texture_north	east;
}					t_texture_data;

typedef struct s_texture_fc
{
	unsigned int	r_f;
	unsigned int	g_f;
	unsigned int	b_f;
	unsigned int	r_c;
	unsigned int	g_c;
	unsigned int	b_c;
}					t_texture_fc;

// Utils
int					ft_strlen_2d(char **str2d);
int					get_num_lines(t_parse_map essentials);

void				init_pointers(t_parse_map *essentials);
// Check map
int					check_map(int fd, char *map);
void				check_map3(t_parse_map essentials);
void				check_valid_path(t_parse_map *essentials);
int					check_valid_path1(t_parse_map *essentials, int i,
						int *count);
void				check_valid_path2(int i, int j, t_parse_map essentials,
						char starting_pos);
void				check_valid_path3(t_parse_map essentials, int count,
						char starting_pos);
void				check_empty_lines(t_parse_map essentials, char *file);
void				get_player_pos(t_parse_map essentials);
void				check_route(t_parse_map essentials, int x, int y);
char				get_starting_pos(t_parse_map essentials);
int					is_element_exist(t_parse_map *essentials);
int					check_corners(t_parse_map essentials);
int					check_first_n_last(t_parse_map essentials);
// Check map elements
void				check_elements_order(t_parse_map *essentials);
int					check_elements(t_parse_map essentials);
int					is_coord(char *coord);
int					is_rgb(char *rgb);
void				rgb_check(char *rgbs, char **element,
						t_parse_map essentials);
void				rgb_check2(char **rgb, char **element,
						t_parse_map essentials);
void				rgb_check3(char **rgb, t_parse_map *essentials,
						char **element);
void				rgb_check4(char *rgbs, char **element,
						t_parse_map *essentials, char **rgb);
void				check_duplicates(t_parse_map *essentials);
int					check_elements_existance(char *element);
void				check_player_duplicates(t_parse_map essentials);
void				check_duplicates4(t_parse_map *essentials);
void				check_weird_chars(t_parse_map essentials);

// Rendering
void				draw_player(t_data *data, double x, double y);
void				print_round(t_data *data);
void				draw_fov_line(t_data *data);
int					move(int keycode, void *par);
void				print_map(t_data *data);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				move_player(t_data *data, int keycode);
void				draw_player(t_data *data, double x, double y);
void				line(t_data *data, float new_x, float new_y, int color);
void				data_init(t_data *data);
double				close_dis(t_data *data, double h_x, double h_y);
void				draw_fov_line(t_data *data);
void				print_player(t_data *data, int x);
void				print_rays(t_data *data);
void				face_angel(t_data *data);
void				fix_r_angle(t_data *data);
float				horizontal_or_vertical(t_data *data);
int					mouse_move(int x, int y, void *param);
void				draw_textures(t_texture_data *textures, t_data *data);
unsigned int		get_color(t_texture_data *textures, int x, int y,
						char direction);
int					get_color_check(t_texture_data *textures, int x, int y);
int					create_trgb(int t, int r, int g, int b);
char				**get_elements(t_parse_map essentials, char *map);
char				*remove_spaces(char *str);
void				load_textures(t_texture_data *textures, t_data *data);
int					check_textures(t_texture_data textures);
//Clearing
void				free2d(char **arg);
int					close_win(t_data *data);
void				free_n_destroy(t_data *data);
void				init_game(t_parse_map *essentials, char *file);
void				render_textures(t_data *data, t_texture_data *textures,
						int *x_offset, int *y_offset);
void				get_offsets(t_data *data, t_texture_data *textures,
						int *x_offset);
int					close_window(int keycode, t_data *data);
#endif