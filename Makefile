# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkristie <kukinpower@ya.ru>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 20:12:37 by mkristie          #+#    #+#              #
#    Updated: 2020/09/24 03:38:05 by mkristie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =		./ft_strlen.s \
			./ft_strcpy.s \
			./ft_strcmp.s \
			./ft_strdup.s \
			./ft_write.s \
			./ft_read.s \

OBJ =		$(SRC:%.s=%.o)

NAME =		libasm.a

%.o: %.s
	@nasm -f macho64 $<

all:		$(NAME)

$(NAME):	$(OBJ)
			@ar -rc $(NAME) $(OBJ)
			@ranlib $(NAME)

main:		all
			@gcc main.c libasm.a
			@./a.out

clean:
			@rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re