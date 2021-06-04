/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:40:02 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/04 12:59:44 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			*s += 1;
		}
		else
			format.precision = 0;
	}
	return (format);
}
