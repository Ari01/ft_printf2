#ifndef TYPES_H
# define TYPES_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define SPECIFIER_CHARSET "cspdiuxX%"
# define NUMERIC_CHARSET "diouxX"
# define FLAG_CHARSET "0-"

typedef struct	s_format
{
	int hash;
	int zero;
	int minus;
	int space;
	int plus;
	int width;
	int precision;
	char specifier;
}				t_format;

/*
 ** FORMAT
*/
int			get_format(char **s, t_format *format, va_list ap);
t_format	get_flag(t_format format, char **s);
t_format	get_width(t_format format, char **s, va_list ap);
t_format	get_precision(t_format format, char **s, va_list ap);
int			is_in_charset(char c, const char *charset);

/*
 ** PRINT
*/
int			ft_printf(const char *format, ...) __attribute__ ((format(printf, 1, 2)));
char		*get_value(t_format format, va_list ap);
int			print_format(t_format format, va_list ap);
char		*convert_u(unsigned int n);
char		*convert_base(unsigned int n, char *base);
char		*convert_p(void *adr);

#endif
