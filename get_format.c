/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:38:49 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/03 17:43:34 by dchheang         ###   ########.fr       */
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

int			is_specifier(char c)
{
	char *spec;

	spec = SPECIFIER_CHARSET;
	while (*spec)
	{
		if (c == *spec)
			return (1);
		spec += 1;
	}
	return (0);
}

int			get_format(char *s, t_format *format, va_list ap)
{
	*format = init_format();
	while (*s && *s != '%')
		s += 1;
	if (*s == '%')
	{
		s += 1;
		while (is_flag(*s))
			*format = get_flag(*format, &s);
		*format = get_width(*format, &s, ap);
		*format = get_precision(*format, &s, ap);
		if (!is_specifier(*s))
			return (0);
		format->specifier = *s;
	}
	return (1);
}
