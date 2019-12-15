# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dsaripap <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/27 14:38:43 by dsaripap      #+#    #+#                  #
#    Updated: 2019/10/31 11:59:54 by dsaripap      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
LIBFTPRINTF = ../ft_printf_ORIGINAL/libftprintf.a
CC = gcc

GREEN=\033[0;32m
RED=\033[0;31m
CYAN=\033[0;36m

SRC =	\
		$(wildcard *.c) \

OBJ = $(SRC:%.c=%.o)

INCL = -I../ft_printf_ORIGINAL/includes/ft_printf.h -I../ft_printf_ORIGINAL/libft/includes/ -I. test_header.h

all: $(NAME)

# $(LIBFTPRINTF):
# 	@MAKE -C ../

$(NAME): $(OBJ) $(LIBFTPRINTF)
	@echo "${GREEN}Making ft_printf${NC}"
	$(CC) -o $(NAME) $(SRC) $(LIBFTPRINTF)

%.o: %.c $(INCL)
	$(CC) -o $@ -c $< 

.PHONY: clean

clean:
	@echo "${RED}Cleaning all object test files${NC}"
	rm -f $(OBJ)

fclean: clean
	@echo "${RED}Deleting the executable printf${NC}"
	rm -f $(NAME)

re: fclean all

