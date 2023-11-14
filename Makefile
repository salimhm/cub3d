CC						=	cc

CFLAGS					=	-I./ -Wall -Wextra -Werror #-fsanitize=address -g

SRCS					=	$(SRCS_PARSING_MAND)\
							$(SRCS_RENDERING_MAND)\
							$(GNL_SRCS)

SRCS_BNS				=	$(SRCS_PARSING_BNS)\
							$(SRCS_RENDERING_BNS)\
							$(GNL_SRCS)

SRCS_PARSING_BNS		=	$(addprefix ./bonus/parsing/, utils_bonus.c utils2_bonus.c check_elements_bonus.c rgb_bonus.c check_map_bonus.c\
							check_map2_bonus.c check_map3_bonus.c norm_utils_bonus.c norm_utils2_bonus.c)

SRCS_RENDERING_BNS		=	cub3d.c\
							$(addprefix ./bonus/rendering/, print_map_scrin_bonus.c mlx_pixel_put_bonus.c move_player_bonus.c\
							draw_player_bonus.c draw_dda_line_bonus.c init_data_bonus.c\
							close_dis_bonus.c draw_background_bonus.c draw_fov_bonus.c fix_face_angledraw_ray_bonus.c draw_textures_bonus.c\
							clear_bonus.c run_bonus.c textures_bonus.c)


SRCS_PARSING_MAND		=	$(addprefix ./mandatory/parsing/, utils.c utils2.c check_elements.c rgb.c check_map.c check_map2.c check_map3.c norm_utils.c norm_utils2.c)

SRCS_RENDERING_MAND		=	cub3d.c\
							$(addprefix ./mandatory/rendering/, print_map_scrin.c mlx_pixel_put.c move_player.c draw_player.c draw_dda_line.c init_data.c\
							close_dis.c draw_background.c draw_fov.c fix_face_angledraw_ray.c draw_textures.c clear.c run.c textures.c)

LIBFT					=	make -C ./libft

GNL_SRCS				=	./gnl/get_next_line.c \
							./gnl/get_next_line_utils.c

OBJS					=	$(SRCS:%.c=%.o)

OBJS_BNS				=	$(SRCS_BNS:%.c=%.o)

NAME					=	cub3D

NAME_BNS				=	cub3D_bonus

all						: 	$(NAME)

bonus					:	$(NAME_BNS)

$(NAME_BNS)				: 	$(OBJS_BNS)
							$(LIBFT)
							$(CC) $(OBJS_BNS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -I./ ./libft/libft.a -o $(NAME_BNS)

$(NAME)					: 	$(OBJS)
							$(LIBFT)
							$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o $(NAME)

clean					:
							rm -rf $(OBJS)
							rm -rf $(OBJS_BNS)
							make fclean -C ./libft

fclean					:	clean
							make fclean -C ./libft
							rm -rf $(NAME)
							rm -rf $(NAME_BNS)
re						:	fclean all

rb						:	fclean bonus