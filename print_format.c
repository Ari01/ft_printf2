/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:06:40 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/05 13:45:29 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_value(t_format format, va_list ap)
{
	char	*value;
	char	*tmp;

	if (format.specifier == 'd' || format.specifier == 'i')
		value = ft_itoa(va_arg(ap, int));
	if (format.specifier == 'u')
		value = convert_u(va_arg(ap, unsigned int));
	if (format.specifier == 'x')
		value = convert_base(va_arg(ap, unsigned int), "0123456789abcdef");
	if (format.specifier == 'X')
		value = convert_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	if (format.specifier == 'c')
	{
		value = malloc(sizeof(char) * 2);
		value[0] = (unsigned char)va_arg(ap, int);
		value[1] = 0;
	}
	if (format.specifier == 's')
		value = ft_strdup(va_arg(ap, char *));
	if (format.specifier == 'p')
	{
		tmp = convert_base(va_arg(ap, unsigned long), "0123456789abcdef");
		value = ft_strjoin("0x", tmp);
		free(tmp);
	}
	return (value);
}

int		print_zero(t_format format, int len)
{
	char	*zero;
	int		nzero;

	nzero = 0;
	if (format.zero || format.precision > 0)
	{
		if (format.precision > len)
			nzero = format.precision - len;
		else if (format.width > len)
			nzero = format.width - len;
		if (nzero)
		{
			zero = malloc(sizeof(char) * (nzero + 1));
			ft_memset(zero, '0', nzero);
			zero[nzero] = 0;
			ft_putstr_fd(zero, STDOUT_FILENO);
			free(zero);
		}
	}
	return (nzero);
}

int		print_spaces(t_format format, int len)
{
	char	*spaces;
	int		nspaces;

	nspaces = 0;
	if (format.width > len)
	{
		nspaces = format.width - len;
		if (nspaces)
		{
			spaces = malloc(sizeof(char) * (nspaces + 1));
			ft_memset(spaces, ' ', nspaces);
			spaces[nspaces] = 0;
			ft_putstr_fd(spaces, STDOUT_FILENO);
			free(spaces);
		}
	}
	return (nspaces);
}

int		print_format(t_format format, va_list ap)
{
	char	*value;
	int		len;
	int		bytes_written;

	value = get_value(format, ap);
	len = ft_strlen(value);
	bytes_written = print_zero(format, len);
	if (!format.minus)
		bytes_written += print_spaces(format, bytes_written + len);
	ft_putstr_fd(value, STDOUT_FILENO);
	free(value);
	bytes_written += len;
	if (format.minus)
		bytes_written += print_spaces(format, bytes_written);
	return (bytes_written);
}
