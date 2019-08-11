# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/27 14:38:43 by dsaripap      #+#    #+#                  #
#    Updated: 2019/06/18 17:35:05 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
LIBFT = libft/libft.a
CC = gcc -Wall -Wextra -Werror -g
SRC =	\
		ft_printf.c \
		ft_saveflags.c \
		ft_error_check.c \
		ft_printtypes.c \
		ft_printformat.c \
		main.c \
		tests.c \

OBJ = $(SRC:%.c=%.o)

INCL = libft/includes/

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) -I./$(INCL) -L./libft -lft $(OBJ)

%.o: %.c $(INCL)
	@$(CC) -o $@ -c $< 

.PHONY: clean

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

lldb: re
	gcc -g main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
