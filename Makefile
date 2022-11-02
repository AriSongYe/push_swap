# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:24:01 by yecsong           #+#    #+#              #
#    Updated: 2022/11/02 15:55:25 by yecsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRCS :=	mandatory/main.c\
		mandatory/check_valid_num.c\
		mandatory/parsing.c\
		mandatory/util.c\
		mandatory/op1.c\
		mandatory/op2.c\
		mandatory/op3.c\
		mandatory/op4.c\

CC := cc

CFLAGS := -Wall -Werror -Wextra

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
