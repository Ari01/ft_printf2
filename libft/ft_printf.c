/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:16:10 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/03 16:34:05 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	f;

	va_start(ap, format);
	f = get_format((char *)format, ap);
	printf("zero = %d\n", f.zero);
	printf("minus = %d\n", f.minus);
	printf("width = %d\n", f.width);
	printf("precision = %d\n", f.precision);
	printf("specifier = %c\n", f.specifier);
}
