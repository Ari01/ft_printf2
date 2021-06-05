# VARS
NAME = libftprintf.a

SRCS = convert_base.c \
convert_u.c \
ft_printf.c \
get_format.c \
get_options.c \
main.c \
print_format.c

OBJS = ${SRCS:.c=.o}
LIBFTOBJS = libft/*.o
CC = clang
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L libft -lft
LIB = -L. -lftprintf
INCLUDE = libft

# RULES
all:		$(NAME)

$(NAME):	$(OBJS)
			cd libft && $(MAKE) $(BONUS)
			ar cr $@ $(LIBFTOBJS) $(OBJS)

test:		$(NAME)
			$(CC) $(CFLAGS) main.c -o $@ $(LIB)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			rm -rf $(OBJS) && cd libft && $(MAKE) clean

fclean:		clean
			rm -rf $(NAME) && cd libft && $(MAKE) fclean

re:			fclean all

.PHONY:		all clean fclean re
