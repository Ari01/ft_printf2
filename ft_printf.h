#ifndef TYPES_H
# define TYPES_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

# define SPECIFIER_CHARSET "cspdiuxX%"

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

/*
 ** FORMAT
*/
int			get_format(char *s, t_format *format, va_list ap);
t_format	get_flag(t_format format, char **s);
t_format	get_width(t_format format, char **s, va_list ap);
t_format	get_precision(t_format format, char **s, va_list ap);

/*
 ** PRINT
*/
void		ft_printf(const char *format, ...) __attribute__ ((format(printf, 1, 2)));

#endif
