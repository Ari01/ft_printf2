/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:16:10 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/03 17:33:02 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *s, ...)
{
	va_list		ap;
	t_format	format;

	va_start(ap, s);
	get_format((char *)s, &format, ap);
	printf("zero = %d\n", format.zero);
	printf("minus = %d\n", format.minus);
	printf("width = %d\n", format.width);
	printf("precision = %d\n", format.precision);
	printf("specifier = %c\n", format.specifier);
}
