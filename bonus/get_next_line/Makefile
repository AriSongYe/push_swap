# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 20:06:16 by yecsong           #+#    #+#              #
#    Updated: 2022/11/02 20:08:14 by yecsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := get_next_line.a

SRCS := get_next_line.c\
		get_next_line_utils.c\

OBJS = $(SRCS:%.c=%.o)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

all : $(NAME)

re :
	make fclean
	make all

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

.PHONY : all clean fclean bonus re
