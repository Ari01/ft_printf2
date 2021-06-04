/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:38:49 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/04 17:16:34 by dchheang         ###   ########.fr       */
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
	f.precision = -1;
	f.specifier = '\0';
	return (f);
}

int			is_in_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int			get_format(char **s, t_format *format, va_list ap)
{
	*format = init_format();
	while (is_in_charset(**s, FLAG_CHARSET))
		*format = get_flag(*format, s);
	*format = get_width(*format, s, ap);
	*format = get_precision(*format, s, ap);
	if (!is_in_charset(**s, SPECIFIER_CHARSET))
		return (0);
	format->specifier = **s;
	*s += 1;
	return (1);
}
