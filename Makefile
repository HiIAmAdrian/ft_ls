# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 17:58:43 by adstan            #+#    #+#              #
#    Updated: 2018/02/11 18:15:11 by adstan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = afis.c \
	  date_l_opt.c \
	  help_afis.c \
	  parsing_opt.c \
	  reading.c \
	  recursive.c \
	  size.c \
	  sorting.c \
	  util.c

OBJ	= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

$(NAME):
	@make -C libft/
	@gcc $(CFLAGS) -c $(SRC)
	@gcc $(OBJ) -o $(NAME) -L ./libft -lft

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all



