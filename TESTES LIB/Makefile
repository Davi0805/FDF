NAME = FDF
CC = cc
LIBFTNAME = libftprintf.a
LIBFTDIR = ./Libft
FLAGS = -Wall -Wextra -Werror -Lminilibx-linux -lmlx_Linux -lX11 -lXext

SRCS = fdf.c fdf_utils.c ./Libft/get_next_line/get_next_line.c ./Libft/get_next_line/get_next_line_utils.c

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

makelibft:
		make -C $(LIBFTDIR)
		cp $(LIBFTDIR)/$(LIBFTNAME) .

$(NAME): makelibft
		$(CC) -o $(NAME) $(SRCS) $(FLAGS) $(LIBFTNAME)

clean:
	cd $(LIBFTDIR) && make clean

fclean: clean
	rm -rf $(NAME)
	cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
