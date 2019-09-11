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
CC = gcc -Wall -Wextra -Werror

GREEN=\033[0;32m
RED=\033[0;31m
CYAN=\033[0;36m

SRC =	\
		$(wildcard *.c) \

OBJ = $(SRC:%.c=%.o)

INCL = -I../ft_printf.h -I../libft/includes/

all: $(NAME)

$(LIBFTPRINTF):
	@MAKE -C ../

$(NAME): $(OBJ) $(LIBFTPRINTF)
	@echo "${GREEN}Making ft_printf${NC}"
	$(CC) -o $(NAME) -I$(INCL) -L.. -lftprintf $(OBJ)

%.o: %.c $(INCL)
	@$(CC) -o $@ -c $< 

.PHONY: clean

clean:
	@echo "${RED}Cleaning all object test files${NC}"
	@rm -f $(OBJ)

fclean: clean
	@echo "${RED}Deleting the executable printf${NC}"
	@rm -f $(NAME)
	@echo "${CYAN}Calling fclean of printf${NC}"	
	@$(MAKE) fclean -C ../

re: fclean all

lldb: re
	$(CC) -g -o $(NAME) -I$(INCL) -L.. -lftprintf $(OBJ)

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
