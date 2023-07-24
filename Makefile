NAME = push_swap

CC = cc

LIB = libpush_swap.a

LIBNAME = push_swap

SUBLIB = libftprintf.a

SUBLIBNAME = ftprintf

AR = ar

AFLAGS = -rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	error_free.c \
	greedy_sort.c \
	greedy_sort_utils.c \
	operation.c \
	push_pop_action.c \
	quick_sort.c \
	push_swap_utils.c \
	./libft/ft_split.c \
	./libft/ft_atoi.c \
	./libft/ft_strlcpy.c \
	./libft/ft_strlen.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^ -I./ 

$(LIB) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(NAME) : $(LIB)
	make -C ./ft_printf all
	$(CC) $(CFLAGS) -l$(SUBLIBNAME) -L./ft_printf -l$(LIBNAME) -L. -o $@

clean :
	make -C ./ft_printf clean
	rm -rf $(OBJS)

fclean : clean
	make -C ./ft_printf fclean
	rm -rf $(LIB) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re