CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address -g

SRCS		=	cub3d.c \
				$(SRCS_PARSING)\
				$(GNL_SRCS)

SRCS_PARSING	=	./parsing/utils.c \
				./parsing/check_elements.c \
				./parsing/rgb.c\
				./parsing/check_map.c\
				./parsing/check_map2.c\
				./parsing/check_map3.c\

LIBFT		=	make -C ./libft

GNL_SRCS	=	./gnl/get_next_line.c \
				./gnl/get_next_line_utils.c

OBJS		=	$(SRCS:%.c=%.o)

NAME		=	cub3d

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) ./libft/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C ./libft

fclean: clean
	make clean -C ./libft
	rm -rf $(NAME)

re: fclean all