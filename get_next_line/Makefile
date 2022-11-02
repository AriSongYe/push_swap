NAME := get_next_line.a

SRCS := get_next_line.c\
		get_next_line_utils.c\

SRCS_BONUS = get_next_line_bonus.c\
			get_next_line_utils_bonus.c

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

AR := ar

ARFLAGS := src

CC := cc

CFLAGS := -Werror -Wextra -Wall -D BUFFER_SIZE=$(BUFF)

ifdef BONUS_CHECK
OBJS_FILES = $(OBJS_BONUS)
else
OBJS_FILES = $(OBJS)
endif

all : $(NAME)
	$(CC) $(CFLAGS) $(NAME) main.c

bonus :
	make BONUS_CHECK=1 all

$(NAME) : $(OBJS_FILES)
	$(AR) $(ARFLAGS) $@ $?

re :
	make fclean
	make all

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)
.PHONY : all clean fclean bonus re
