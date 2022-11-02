# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:24:01 by yecsong           #+#    #+#              #
#    Updated: 2022/11/02 20:03:24 by yecsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := checker

SRCS :=	check_valid_num_bonus.c\
		op1_bonus.c\
		op2_bonus.c\
		op3_bonus.c\
		op4_bonus.c\
		parsing_bonus.c\
		util_bonus.c\
		checker.c

CC := cc

CFLAGS := -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	$(MAKE) -C ../libft/ all
	$(MAKE) -C ./get_next_line/ all
	$(CC) $(CFLAGS) $(SRCS) ./get_next_line/get_next_line.a ../libft/libft.a -o checker

re : fclean all

clean :
	rm -f *.o
	rm -f ../libft/*.o
	rm -f ./get_next_line/*.o

fclean : clean
	rm -f $(NAME)
	rm -f ../libft/libft.a
	rm -f ./get_next_line/get_next_line.a

.PHONY : all clean fclean bonus re
