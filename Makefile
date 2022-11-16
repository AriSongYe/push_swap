# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:24:01 by yecsong           #+#    #+#              #
#    Updated: 2022/11/16 14:28:26 by yecsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRCS :=	mandatory/main.c\
		mandatory/check_valid_num.c\
		mandatory/parsing.c\
		mandatory/util.c\
		mandatory/util_2.c\
		mandatory/op1.c\
		mandatory/op2.c\
		mandatory/op3.c\
		mandatory/a_few_num.c

SRCS_BONUS := bonus/check_valid_num_bonus.c\
		bonus/op1_bonus.c\
		bonus/op2_bonus.c\
		bonus/op3_bonus.c\
		bonus/op4_bonus.c\
		bonus/parsing_bonus.c\
		bonus/util_bonus.c\
		bonus/checker.c

CC := cc

CFLAGS := -Wall -Werror -Wextra

all : $(NAME)

BONUS_NAME := checker

bonus : $(BONUS_NAME)

$(BONUS_NAME) :
	$(MAKE) -C libft/ all
	$(MAKE) -C bonus/get_next_line/ all
	@$(CC) $(CFLAGS) $(SRCS_BONUS) bonus/get_next_line/get_next_line.a ../libft/libft.a -o checker

$(NAME) :
	$(MAKE) -C ./libft/ all
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o push_swap

re : fclean all

clean :
	rm -f *.o
	rm -f libft/*.o
	rm -f bonus/get_next_line/*.o

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f libft/libft.a
	rm -f bonus/get_next_line/get_next_line.a

.PHONY : all clean fclean bonus re
