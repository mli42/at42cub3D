/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:53:02 by mli               #+#    #+#             */
/*   Updated: 2019/12/06 16:55:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int a = 2147483647;

	char *b = (char *)&a;
	int i = 0;
	(void)i;
//	while (i < 4)
//		b[i++] = 0;
//	b[3] = 0;
//	b[2] = 0;
	printf("%d\n", a);
	printf("%d\n", (int)sizeof(int));
	printf("%d\n", (int)sizeof(char));
	printf("%d\n", (int)b[0]);
	printf("%d\n", (int)b[1]);
	printf("%d\n", (int)b[2]);
	printf("%d\n", (int)b[3]);
}
