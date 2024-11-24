//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mindset/source/16column.c                                               ***//
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

void	iterate(t_md *md)
{
	md->c = (md->c + 1);
}

void	print(t_md *md, int c)
{
	md->c = 1;
	md->d = 1;
	md->a = 1;
	int	nl = 0;
	printf("_______________________________________________________________________________________________________________________________________________________\n");
	printf("|%8d         ||%8d         ||%8d         ||%8d         ||%8d         ||%8d         ||%8d         ||%8d         |\n", 1 ,2, 3, 4, 5, 6, 7, 8);
	printf("⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌  \n"); 
	while (md->d <= c)
	{
		printf("| %5s%2d = 0%4llx |", md->set_list[md->c], md->d, md->a);
		md->c += 1;
		nl++;
		if (nl == 8)
		{
			printf("\n");
			nl = 0;
		}	
		if (md->c == 32)
		{
			md->c = 1;
			md->d++;

		}
		md->a++;
	}
	printf("⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌ ⎿________________⏌  \n"); 

}

int main(void)
{
	t_md *md;

	md = malloc(sizeof(t_md));
	init_struct(md);
	print(md, 64);
	return (0);
}

