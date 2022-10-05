NAME = push_swap

SRCS = push_swap.c utils_1.c error.c

LIBFT = ./ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS)
	@make -C ./ft_printf
	@echo "\033[33mCreating push_swap...\x1b[0m"
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "\033[32mpush_swap created...\x1b[0m"

test:
	@echo "\033[33mCompiling true digits...\n"
	@make $(all)
	@./push_swap 5 4 2 1 6 8 7 3 123 85

test2:
	@echo "\033[31mCompiling wrong digits...\n"
	@./push_swap 1 2 3 4 5 6 7 8 9 10 A C

clean:
	@printf '\033[31m Files deleted. !\n'
	@make fclean -C ./ft_printf

fclean:
	@printf '\033[31m Files deleted. !\n'
	@make fclean -C ./ft_printf
	@rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re