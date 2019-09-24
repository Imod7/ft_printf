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

NAME = libftprintf.a
LIBFT = libft/libft.a
CC = gcc -Wall -Wextra -Werror -g

RED=\033[0;31m
GREEN=\033[0;32m
CYAN=\033[0;36m
NC=\033[0m # No Color

SRC =	\
		ft_printf.c \
		ft_printf_genericfunc.c \
		ft_save_flags.c \
		ft_print_signed.c \
		ft_print_unsigned.c \
		ft_print_other.c \
		ft_print_format.c \
		ft_putnbr_base.c \
		ft_print_float.c \
		ft_itoa_float.c \
		ft_addtobuffer.c \
		ft_bitwise.c \
		ft_common_func.c \
		ft_float.c \

OBJ = $(SRC:%.c=%.o)

INCL = libft/includes/

all: $(NAME)

$(LIBFT):
	@echo "${CYAN}Calling libft makefile${NC}"
	@$(MAKE) -C libft

$(NAME): $(OBJ) $(LIBFT)
	@echo "${GREEN}Making libftprintf.a${NC}"
	@cp libft/libft.a $(NAME)
	@ar crs $(NAME) $(OBJ)

%.o: %.c $(INCL)
	@$(CC) -o $@ -c $< 

.PHONY: clean

clean:
	@echo "${RED}Cleaning all object files of printf${NC}"
	@rm -f $(OBJ)
	@$(MAKE) clean -C libft

fclean: clean
	@rm -f $(NAME)
	@echo "${CYAN}Calling fclean of libft${NC}"	
	@$(MAKE) fclean -C libft

re: fclean all

lldb: re
	gcc -g main.c -L. -lft

norm:
	norminette $(SRC) $(INCL) | grep -e "Error" -e "Warning" -B 1
