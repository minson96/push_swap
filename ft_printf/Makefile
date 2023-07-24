NAME = libftprintf.a

SRCS =	ft_printf.c ft_printf_utils_1.c ft_printf_utils_2.c

OBJS	= $(SRCS:%.c=%.o)

FLAGS	= -Wall -Wextra -Werror

OBJ_FILES = $(OBJS)

all	:	$(NAME)

$(NAME)	:	$(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(CC)	:
	cc

%.o	: %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re