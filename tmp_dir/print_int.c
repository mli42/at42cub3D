/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 23:23:42 by mli               #+#    #+#             */
/*   Updated: 2020/03/10 00:08:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_int(int nbr)
{
	char *str = (char *)&nbr;

	// Print the entire int
	printf("%d\n", nbr); 

	// Print bytes
	int k = 4;
	while (--k > -1)
	{
		printf("%d", str[k]);
		if (k)
			printf("\t");
	}
	printf("\n");

	// Print all bits
	int tmp;
	int octect;

	int l = 4;
	while (--l > -1)
	{
		k = 8;
		octect = str[l];
		while (--k != -1)
		{
			tmp = (octect >> k) & 1;
			printf("%d", tmp);
		}
		if (l)
			printf(" ");
	}
	printf("\n");
}

int		main(void)
{
	ft_print_int(0x7FFFFFFF);
	printf("\n");
	ft_print_int(0x00FF0000);
	printf("\n");
	ft_print_int(0x0000FF00);
	printf("\n");
	ft_print_int(0x000000FF);
	return (0);
}
