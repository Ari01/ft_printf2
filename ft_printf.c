/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:16:10 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/04 15:19:53 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(const char *s, int start, char *ite)
{
	char	*string;

	string = ft_substr(s, start, ite - &s[start]);
	ft_putstr_fd(string, STDOUT_FILENO);
	free(string);
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	format;
	int			start;
	char		*ite;

	va_start(ap, s);
	ite = (char *)s;
	start = 0;
	while (*ite)
	{
		while (*ite && *ite != '%')
			ite++;
		print_string(s, start, ite);
		if (*ite == '%')
			ite++;
		if (!get_format(&ite, &format, ap))
			return (-1);
		print_format(format, ap);
		start = ite - s;
		//return (print_format(format, ap));
	}
	return (1);
}
