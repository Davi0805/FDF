MAKEFLAGS += -s

NAME = libft.a
CC = cc
LIBFTNAME = libftprintf.a
LIBFTDIR = ../Libft
GNLUTILS = ../Libft/get_next_line/get_next_line_utils.c
GNL = ../Libft/get_next_line/get_next_line.c
FLAGS = -Wall -Wextra -Werror -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm
OBJS = $(SRCS:.c=.o)
SRCS = main.c init.c Error.c parse.c draw_logic.c fdf_utils.c

GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m

all: fdf

$(NAME): $(LIBFTDIR)/$(LIBFTNAME)
	@cp $(LIBFTDIR)/$(LIBFTNAME) $(NAME)

$(LIBFTDIR)/$(LIBFTNAME):
	@make -C $(LIBFTDIR)

fdf: $(NAME) $(OBJS)
	@echo "# $(GREEN)Building project...$(NC)"
	@$(CC) -o fdf $(OBJS) $(NAME) $(GNL) $(GNLUTILS) $(FLAGS) && echo "$(GREEN)Done!$(NC)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@cd $(LIBFTDIR) && make clean
	@echo "# $(YELLOW)Cleaning...$(NC)"

fclean: clean
	@rm -rf $(NAME)
	@rm -f push_swap
	@cd $(LIBFTDIR) && make fclean
	@echo "# $(RED)Fully Cleaned!$(NC)"

re: fclean all

.PHONY: all clean fclean re
