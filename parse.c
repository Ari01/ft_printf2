/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:45:56 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/03 16:41:21 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	init_format()
{
	t_format f;

	f.hash = 0;
	f.zero = 0;
	f.minus = 0;
	f.space = 0;
	f.plus = 0;
	f.width = 0;
	f.precision = 0;
	f.specifier = '\0';
	return (f);
}

int			is_flag(char c)
{
	return (c == '0' || c == '-');
}

t_format	get_flag(t_format format, char **s)
{
	if (**s == '0')
	{
		format.zero = 1;
		*s += 1;
	}
	if (**s == '-')
	{
		format.minus = 1;
		*s += 1;
	}
	if (format.minus == 1)
		format.zero = 0;
	return (format);
}

t_format	get_width(t_format format, char **s, va_list ap)
{
	if (ft_isdigit(**s))
	{
		format.width = ft_atoi(*s);
		while (ft_isdigit(**s))
			*s += 1;
	}
	else if (**s == '*')
	{
		format.width = va_arg(ap, int);
		if (format.width < 0)
		{
			format.minus = 1;
			format.zero = 0;
			format.width *= -1;
		}
		*s += 1;
	}
	return (format);
}

t_format	get_precision(t_format format, char **s, va_list ap)
{
	if (**s == '.')
	{
		*s += 1;
		if (ft_isdigit(**s))
		{
			format.precision = ft_atoi(*s);
			while (ft_isdigit(**s))
				*s += 1;
		}
		else if (**s == '*')
		{
			format.precision = va_arg(ap, int);
			if (format.precision < 0)
				format.precision = 0;
			*s += 1;
		}
	}
	return (format);
}

t_format	get_format(char *s, va_list ap)
{
	t_format	format;
	int			is_format;

	format = init_format();
	is_format = 0;
	while (*s && *s != '%')
		s += 1;
	if (*s == '%')
	{
		s += 1;
		while (is_flag(*s))
			format = get_flag(format, &s);
		format = get_width(format, &s, ap);
		format = get_precision(format, &s, ap);
		format.specifier = *s;
	}
	return (format);
}
