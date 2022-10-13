NAME = push_swap

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB= libft/libft.a
PRINT= ft_printf/libftprintf.a

INC_FT = libft
INC_FT_PRINTF = ft_printf

all: $(LIB) $(PRINT) $(NAME)

$(LIB):
	@make -C libft
	@echo "\x1b[33mlibft compilation success\x1b[0m"

$(PRINT):
	@make -C ft_printf
	@echo "\x1b[33mprintf compilation success\x1b[0m"

$(NAME): ${OBJS}
	@$(CC) $(OBJS) -o $(NAME) $(LIB) $(PRINT)
	@echo "\x1b[33mpush_swap ready to start\x1b[0m"

.c.o:
	@$(CC) $(CFLAGS) -I $(INC_FT) -I $(INC_FT_PRINTF) -c $< -o $@

clean:
	@rm $(OBJS)
	@echo "\x1b[32mClean success\x1b[0m"

fclean: clean
	@rm $(NAME)

ffclean: fclean
	@make fclean -C libft
	@make fclean -C ft_printf

norm:
	@norminette $(SRC) push_swap.h

re: fclean all

.PHONY: all re clean fclean ffclean
