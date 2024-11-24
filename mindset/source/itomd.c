/*
 * ________________________________________________________________________________
 * |  File: itomd.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/mindset_instructions.h"

int main(int argc, char **argv)
{
	if (argc == 2)
	{

		if (longlongcheck(argv[1]) == 1)
			return (-1);

		char *string = dc_strdup(argv[1]);
		int	base10 = atoi(string);
		char *md =  itomd(base10);
		printf("%s\n", md);
		printf("Converted Back: %ld", md_val(md));
		
		free(string);
		free(md);	
	}
	return 0;
}