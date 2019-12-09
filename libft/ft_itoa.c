/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:35:23 by mli               #+#    #+#             */
/*   Updated: 2019/10/14 11:19:45 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_is_0(void)
{
	char		*result;

	if (!(result = ft_calloc(2, sizeof(char))))
		return (NULL);
	result[0] = '0';
	return (result);
}

static int	ft_nlen(long int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long int	nb;
	int			size;
	char		*result;

	if (n == 0)
		return (ft_is_0());
	size = 1;
	nb = (long int)n;
	if (nb < 0)
	{
		size++;
		nb *= (-1);
	}
	size += ft_nlen(nb);
	if (!(result = (char *)ft_calloc(size--, sizeof(char))))
		return (NULL);
	if (n < 0)
		result[0] = '-';
	while (nb > 0)
	{
		result[--size] = (nb % 10) + 48;
		nb /= 10;
	}
	return (result);
}
