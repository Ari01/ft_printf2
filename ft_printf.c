/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:16:10 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/04 17:21:11 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(const char *s, int start, char *ite)
{
	char	*string;
	int		len;

	len = ite - &s[start];
	string = ft_substr(s, start, len);
	ft_putstr_fd(string, STDOUT_FILENO);
	free(string);
	return (len);
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	format;
	int			start;
	int			bytes_written;
	char		*ite;

	va_start(ap, s);
	ite = (char *)s;
	start = 0;
	bytes_written = 0;
	while (*ite)
	{
		while (*ite && *ite != '%')
			ite++;
		bytes_written += print_string(s, start, ite);
		if (*ite == '%')
		{
			ite++;
			if (!get_format(&ite, &format, ap))
				return (-1);
			bytes_written += print_format(format, ap);
		}
		start = ite - s;
	}
	return (bytes_written);
}
