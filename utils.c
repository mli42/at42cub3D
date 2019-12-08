/***************************************************************\
|                                              # #    ###       |
|     Author: L                                # #      #       |
|     Mail:                                    ###    ###       |
|     Creation date: 2019/12/08 20:24:55         #    #         |
|                                                #    ###       |
\***************************************************************/

#include "cub3D.h"

void	*ft_memalloc(int size)
{
	void *result;

	if (!(result = malloc(size)))
		return (NULL);
	ft_memset(result, 0, size);
	return (result);
}
