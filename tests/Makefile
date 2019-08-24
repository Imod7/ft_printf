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
LIBFTPRINTF = ../libftprintf.a
CC = gcc -Wall -Wextra -Werror -g
SRC =	\
		$(wildcard *.c) \

OBJ = $(SRC:%.c=%.o)

INCL = -I../ft_printf.h -I../libft/includes/

all: $(NAME)

$(LIBFTPRINTF):
	@$(MAKE) -C libftprintf

$(NAME): $(OBJ) $(LIBFTPRINTF) 
	@$(CC) -o $(NAME) -I$(INCL) -L.. -lftprintf $(OBJ)

%.o: %.c $(INCL)
	@$(CC) -o $@ -c $< 

.PHONY: clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

lldb: re
	gcc -g main.c -L. -lftprintf

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
