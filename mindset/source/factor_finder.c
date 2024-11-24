/*
 * ________________________________________________________________________________
 * |  File: factor_finder.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/mindset_instructions.h"

none factor_finder(int d)
{
	if (d < (int)md_val("P_1024") && d >= -(int)md_val("P_1024"))
	{
		char *out;
		float modifier;
		
		modifier = 0;
		i_P i;

		i = 1;
		while (i <= 32)
		{
			if (d % i == 0)
			{
				modifier = (d / i);
				printf(" %d * %f = %d \n", i, modifier, d);
			}
			i++;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *string = dc_strdup(argv[1]);
		int	number = atoi(string);
		factor_finder(number);	
		free(string);	
	}
	return (0);
}