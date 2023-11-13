CC				=		cc

CFLAGS			=		#-fsanitize=address -g

SRCS			=		$(SRCS_PARSING)\
						$(SRCS_RENDERING)\
						$(GNL_SRCS)

SRCS_PARSING	=		./parsing/utils.c \
						./parsing/check_elements.c \
						./parsing/rgb.c\
						./parsing/check_map.c\
						./parsing/check_map2.c\
						./parsing/check_map3.c\
						./parsing/norm_utils.c\
						./parsing/norm_utils2.c\

SRCS_RENDERING	=		cub3d.c\
						./rendering/print_map_scrin.c\
						./rendering/mlx_pixel_put.c\
						./rendering/move_player.c\
						./rendering/draw_player.c\
						./rendering/draw_dda_line.c\
						./rendering/init_data.c\
						./rendering/close_dis.c\
						./rendering/draw_background.c\
						./rendering/draw_fov.c\
						./rendering/fix_face_angledraw_ray.c\
						./rendering/draw_textures.c\
						./rendering/clear.c\
						./rendering/run.c\
						./rendering/textures.c\


LIBFT			=		make -C ./libft

GNL_SRCS		=		./gnl/get_next_line.c \
						./gnl/get_next_line_utils.c

OBJS			=		$(SRCS:%.c=%.o)

NAME			=		cub3D

all				: 		$(NAME)

$(NAME)			: 		$(OBJS)
						$(LIBFT)
						$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o ./libft/libft.a -o $(NAME)

clean			:
						rm -rf $(OBJS)
						make fclean -C ./libft

fclean			:		clean
						make fclean -C ./libft
						rm -rf $(NAME)

re				:		fclean all