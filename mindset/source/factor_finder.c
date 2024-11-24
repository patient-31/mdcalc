//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mindset/source/factor_finder.c                                          ***//
//***     Path: /media/danielle/Stuff/Programs/mindset                                                                     ***//
//***     Created Date: Wednesday, August 7th 2024, 6:22:33 am                                                             ***//
//***     Author: Daniel Haddington [Danielle]                                                                             ***//
//***                                                                                                                      ***//
//***     Copyright (c) 2024 [Daniel Haddington]. All rights reserved.                                                     ***//
//**________________________________________________________________________________________________________________________**//
//*__________________________________________________________________________________________________________________________*//

//*--------------------------------------------------------------------------------------------------------------------------*//

 /* Proof Of Creation 
 Please provide Private Key (1 Attempt) 
 [15bhks-145dfk-25bkrt-6GLbik-125bcd-57afmt] 
 */

//-----------------------------------------------------------------------------------------------------------------------------

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