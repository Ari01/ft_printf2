/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:42:36 by dchheang          #+#    #+#             */
/*   Updated: 2021/06/05 12:26:20 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nblen(unsigned int n, int baselen)
{
	int	i;

	i = 1;
	while ((n = n / baselen))
		i++;
	return (i);
}

char		*convert_base(unsigned int n, char *base)
{
	char	*conversion;
	int		len;
	int		baselen;

	baselen = ft_strlen(base);
	len = nblen(n, baselen);
	conversion = malloc(sizeof(len) + 1);
	conversion[len] = 0;
	while (--len >= 0)
	{
		conversion[len] = base[n % baselen];
		n = n / baselen;
	}
	return (conversion);
}
