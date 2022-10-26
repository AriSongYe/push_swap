# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:24:01 by yecsong           #+#    #+#              #
#    Updated: 2022/10/26 17:55:09 by yecsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRCS :=	main.c

CC := cc

CFLAGS := -Werror -Wextra -Wall 

all : $(NAME)

$(NAME) :
	$(MAKE) -C ./libft/ all
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o push_swap

re : fclean all

clean :
	rm -f *.o
	rm -f libft/*.o

fclean : clean
	rm -f $(NAME)
	rm -f libft/libft.a

.PHONY : all clean fclean bonus re
