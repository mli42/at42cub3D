/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:38:42 by mli               #+#    #+#             */
/*   Updated: 2019/12/12 14:00:16 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_ls(void)
{
	printf("Typed ls\n");
}

void	ft_cd(void)
{
	printf("Typed cd\n");
}

void	ft_cat(void)
{
	printf("Typed cat\n");
}

int		main(int argc, char **argv)
{
	void (*fct[3])();
	char *cmd[3];

	if (argc != 2)
	{
		printf("Not good\n");
		return (0);
	}
	fct[0] = ft_ls;
	fct[1] = ft_cd;
	fct[2] = ft_cat;

	cmd[0] = "ls";
	cmd[1] = "cd";
	cmd[2] = "cat";
	int i = -1;
	while (++i < 3)
		if (!strcmp(argv[1], cmd[i]))
			fct[i]();
	return (0);
}
