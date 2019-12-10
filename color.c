/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:53:02 by mli               #+#    #+#             */
/*   Updated: 2019/12/10 16:11:40 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

int		main(void)
{
	int i = 0;
	int a = 2147483647;
	char *b = (char *)&a;
	(void)i;

//	while (i < 4)
//		b[i++] = 0;
	b[3] = 0;
	b[2] = 0;
	b[1] = 0;
//	b[0] = 0;
	printf("NB: %d\n", a);
	printf("NB: %x\n", a);
	printf("int: %d\n", (int)sizeof(int));
	printf("char: %d\n", (int)sizeof(char));
	printf("%d\n", (int)b[0]);
	printf("%d\n", (int)b[1]);
	printf("%d\n", (int)b[2]);
	printf("%d\n", (int)b[3]);
}
