/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:31:14 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/04 16:35:18 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nblen(unsigned int n)
{
	int	i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}


char		*convert_u(unsigned long n)
{
	char	*conversion;
	int		len;

	len = nblen(n);
	conversion = malloc(sizeof(len + 1));
	conversion[len] = 0;
	while (--len >= 0)
	{
		conversion[len] = n % 10 + '0';
		n = n / 10;
	}
	return (conversion);
}
