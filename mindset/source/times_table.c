//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mindset/source/times_table.c                                            ***//
//***     Path: /media/danielle/Stuff/Programs/mindset                                                                     ***//
//***     Created Date: Saturday, August 3rd 2024, 3:50:55 pm                                                              ***//
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

#include "../includes/mindset_instructions.h"

void init_struct(t_md *md)
{
	int	i;

	i = 1;
	md->set_list = malloc(sizeof(char *) * (QRANGE + 1));
	
	md->set_list[_A]   = strdup("_A");		   
	md->set_list[_B]   = strdup("_B");		
	md->set_list[_C]   = strdup("_C");		
	md->set_list[_D]   = strdup("_D");		
	md->set_list[_E]   = strdup("_E");		
	md->set_list[_F]   = strdup("_F");		
	md->set_list[_G]   = strdup("_G");		
	md->set_list[_H]   = strdup("_H");		
	md->set_list[_I]   = strdup("_I");		
	md->set_list[_J]   = strdup("_J");		
	md->set_list[_K]   = strdup("_K");		
	md->set_list[_L]   = strdup("_L");		
	md->set_list[_M]   = strdup("_M");		
	md->set_list[_N]   = strdup("_N");		
	md->set_list[_O]   = strdup("_O");		
	md->set_list[_P]   = strdup("_P");		
	md->set_list[A_]   = strdup("A_");		
	md->set_list[B_]   = strdup("B_");		
	md->set_list[C_]   = strdup("C_");		
	md->set_list[D_]   = strdup("D_");		
	md->set_list[E_]   = strdup("E_");		
	md->set_list[F_]   = strdup("F_");		
	md->set_list[G_]   = strdup("G_");		
	md->set_list[H_]   = strdup("H_");		
	md->set_list[I_]   = strdup("I_");		
	md->set_list[J_]   = strdup("J_");		
	md->set_list[K_]   = strdup("K_");		
	md->set_list[L_]   = strdup("L_");		
	md->set_list[M_]   = strdup("M_");		
	md->set_list[N_]   = strdup("N_");		
	md->set_list[O_]   = strdup("O_");		
	md->set_list[P_]   = strdup("P_");		
}

int main (void)
{
	t_md *md = malloc(sizeof(t_md));

	*md = (t_md){0};
	init_struct(md);

	int q;
	int i;
	int x;
	int y;
	int result;

	q = 1;

	x = 1;
	y = 1;
	result = 0;
	while (q <= 32)
	{
		i = 1;
		y = 1;
		printf("____________________________________%d_Times Tables_________________________________________________________________________________________________________________________________________", q);
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		while (i <= 32)
		{
			result = x * y;
			printf("|%d*%s=%4d|", q, md->set_list[i], result);
			y += 1;
			i++;
			if (i == 17)
				printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		}
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		x += 1;
		q++;
	}

	i = 0;
	while (i < P_)
	{
		free(md->set_list[i]);
		i++;
	}
	free(md);
	return (0);
}