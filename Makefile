CC			=	cc

CFLAGS		=	#-fsanitize=address -g

SRCS		=	cub3d.c print_map_scrin.c mlx_pixel_put.c move_player.c draw_player.c draw_dda_line.c init_data.c close_dis.c draw_background.c draw_fov.c fix_face_angledraw_ray.c\
				draw_textures.c\
				clear.c\
				run.c\
				$(SRCS_PARSING)\
				$(GNL_SRCS)

SRCS_PARSING	=	./parsing/utils.c \
				./parsing/check_elements.c \
				./parsing/rgb.c\
				./parsing/check_map.c\
				./parsing/check_map2.c\
				./parsing/check_map3.c\
				./parsing/norm_utils.c\
				./parsing/norm_utils2.c\

LIBFT		=	make -C ./libft

GNL_SRCS	=	./gnl/get_next_line.c \
				./gnl/get_next_line_utils.c

OBJS		=	$(SRCS:%.c=%.o)

NAME		=	cub3D

all: $(NAME)

$(NAME): 	$(OBJS)
			$(LIBFT)
			$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS)
	make fclean -C ./libft

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all