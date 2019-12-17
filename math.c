/***************************************************************\
|                                              # #    ###       |
|     Author: L                                # #      #       |
|     Mail:                                    ###    ###       |
|     Creation date: 2019/12/16 17:40:37         #    #         |
|                                                #    ###       |
\***************************************************************/

#include <math.h>
#include <stdio.h>

int	main(void)
{
	double angle = 180/M_PI;

	printf("%lf\n", M_PI);

	angle *= atan2(1, 0); 
	printf("%lf\n", angle);

	return (0);
}
