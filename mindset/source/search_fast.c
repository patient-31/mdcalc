/*
 * ________________________________________________________________________________
 * |  File: search_fast.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/mindset_instructions.h"

int main(int argc, char **argv)
{
	if (argc)
	{
		{
			i_H *number = dc_strdup(argv[1]);
			uP_2 output = md_val(number);
			printf("%lu\n", output);
			free(number);
		}
	}
}