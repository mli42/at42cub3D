/***************************************************************\
|                                              # #    ###       |
|     Author: L                                # #      #       |
|     Mail:                                    ###    ###       |
|     Creation date: 2019/12/18 23:54:16         #    #         |
|                                                #    ###       |
\***************************************************************/

#include "cub3d.h"

int		main(void)
{
	printf("%lf\n", atan2(-1, 0) * (180/M_PI));
	printf("%lf\n", atan2(-1, 0));
	printf("%lf\n", atan2(sin(5 * M_PI/4), cos(5 * M_PI / 4)) * (180/M_PI));
	printf("%lf\n", atan2(sin(5 * M_PI/4), cos(5 * M_PI / 4)));
}
