NAME1 = server
NAME2 = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLEAN = rm -rf

all :
		@make -C ./ft_printf
		@make -C ./libft_42
		@$(CC) $(CFLAGS) $(NAME1).c ./ft_printf/libftprintf.a ./libft_42/libft.a -o $(NAME1)
		@$(CC) $(CFLAGS) $(NAME2).c ./ft_printf/libftprintf.a ./libft_42/libft.a -o $(NAME2)

bonus :
		@make -C ./ft_printf
		@make -C ./libft_42
		@$(CC) $(CFLAGS) $(NAME1)_bonus.c ./ft_printf/libftprintf.a ./libft_42/libft.a -o $(NAME1)_bonus
		@$(CC) $(CFLAGS) $(NAME2)_bonus.c ./ft_printf/libftprintf.a ./libft_42/libft.a -o $(NAME2)_bonus
clean :
		@make clean -C ./ft_printf
		@make clean -C ./libft_42
		@$(CLEAN) $(NAME1).o $(NAME2).o

fclean : clean
		@make fclean -C ./ft_printf
		@make fclean -C ./libft_42
		@$(CLEAN) $(NAME1) $(NAME2)
		@$(CLEAN) $(NAME1)_bonus $(NAME2)_bonus

re : fclean all

.PHONY : all fclean clean
