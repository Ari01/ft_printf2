#ifndef TYPES_H
# define TYPES_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

typedef struct s_format{
	int hash;
	int zero;
	int minus;
	int space;
	int plus;
	int width;
	int precision;
	char specifier;
} t_format;

t_format	get_format(char *s, va_list ap);
void		ft_printf(const char *format, ...);

#endif
