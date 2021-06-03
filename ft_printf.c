/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:16:10 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/03 18:06:43 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	format;
	int			i;
	int			ret;
	char		*string;

	va_start(ap, s);
	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	string = ft_substr(s, 0, i);
	ft_putstr_fd(string, STDOUT_FILENO);
	free(string);
	ret = get_format((char *)&s[i], &format, ap);
	if (ret != -1)
		print_format(format, ap);
	return (ret);
}
