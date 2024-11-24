//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mindset/source/search.c                                                 ***//
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

int isInteger(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= '0' && c[i] <= '9')
			i++;
		else 
			return (0);
	}
	return (1);
}

int	lstlen(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	return (i);
}

void	error_exit(char *mess, int error_type, t_md *md)
{
	printf("\e[1;31mError; Explicit: %s\n", mess);
	exit_program(error_type, md);
}

void	exit_program(int error_type, t_md *md)
{
	if (md->set_list)
		free_2d_char(md->set_list, lstlen(md->set_list));
	if (md->drop_tail)
		free(md->drop_tail);
	if (md->drop_tail__floor)
		free(md->drop_tail__floor);
	if (md->l)
		free(md->l);
	if (md->r)
		free(md->r);
	if (md)
		free(md);
	exit(error_type);
}

void	free_2d_char(char **f, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(f[i++]);
	free(f);
}

void	init_struct(t_md *md)
{
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
	md->set_list[NL]   = NULL;	
}

void	drop_float_tail(char *dropee, int drop_size)
{
	int i;

	i = 0;
	while (dropee[i])
	{
		i++;
		if (dropee[i] == '.')
		{
			while (drop_size-- + 1)
				i++;
			while(dropee[i])
			{
				dropee[i] = 0;
				i++;
			}
		}
	}
}

void	Operation(t_md *md)
{
	// Creation of Modifier //
	md->modifier = md->value / md->pattern_descriptor;
	sprintf(md->drop_tail, "%f", md->modifier);
	drop_float_tail(md->drop_tail, 3);
	md->modifier = strtod(md->drop_tail, NULL);
	
	// Creation of Near Integer //
	md->_floor = md->pattern_descriptor * md->modifier;
	sprintf(md->drop_tail__floor, "%f", md->_floor);
	drop_float_tail(md->drop_tail__floor, 3);
	md->_floor = strtod(md->drop_tail__floor, NULL);

}

void	Check_Op(t_md *md)
{
	if  (md->_floor > md->value)
	{
		md->l = strdup("\e[1;31m⎿\e[0;32m");
		md->r = strdup("\e[1;31m⏌\e[0;32m");
		md->floored = floorf(md->_floor);
		printf("\n\n\e[1;31mWhy did this happen at [%s = %f]\e[0;32m\n\n",
			md->set_list[md->pattern_descriptor], md->value);
		md->check = true;
	}
	else if (md->_floor < md->value)
	{
		md->floored = ceil(md->_floor);
		md->l = strdup("\e[1;33m⎾\e[0;32m");
		md->r = strdup("\e[1;33m⏋\e[0;32m");
	}
	else if (md->_floor == md->value)
	{
		md->l = strdup("\e[1;34m_\e[0;32m");
		md->floored = md->value;
		md->r = strdup("\e[1;34m_\e[0;32m");
	}
}

void	printset_modifiers(t_md *md)
{
	md->pattern_descriptor = 1;
	md->modifier = 0.0;
	md->_floor = 0.0;
	md->drop_tail__floor = malloc(sizeof(char) * 42);
	md->drop_tail = malloc(sizeof(char) * 42);
	if (!md->drop_tail__floor || !md->drop_tail)
		error_exit("Memory Allocation Failed", MEMORY_ALLOCATION_ERROR, md);
	md->floored = 0;
	
	if ((md->Qset - 1) % 16 == 0 && md->Qset != 1)
		md->MdSet++;
	printf("\n\n __________________________________________________________________________________________________\n");
	printf("|                       MdSet: %03d               Qset: %5d            |\n", md->MdSet, md->Qset);
	printf("⎿_________________________________________________________________________________________________⏌\n");

	while(md->pattern_descriptor <= 32)
	{
		Operation(md);
		Check_Op(md);

		printf("|%4s%02d = [%02d][x %8.3f] = %s%8.4f%s = %4d |",
			md->set_list[md->pattern_descriptor],
			md->Qset,
			md->pattern_descriptor,
			md->modifier,
			md->l,
			md->_floor,
			md->r,
			md->floored);

		if (md->floored != md->value)
			error_exit("md->value is out of target range", OOR, md);

		md->pattern_descriptor++;
		
		if (md->value_c == md->find)
		{
			if (md->check)
				printf("\n\e[1;31m⎿CHECK⏌\e[0;32m\n");
			exit_program(SUCCESS, md);
		}
		md->value++;
		md->value_c++;
		if (md->pattern_descriptor % 2 == 1 && md->pattern_descriptor != 1) 
			printf("\n");
	}
	printf("⎿________________________________________________________________________________________________________________⏌\n");
}



int main(int argc, char **argv)
{
	t_md *md;

	md = malloc(sizeof(t_md));
	init_struct(md);

	md->value_c = 1;
	md->check = false;
	md->value = 1.0;
	md->Qset = 1;
	md->MdSet = 1;
	if (argc == 2 && isInteger(argv[1]))
		md->find = atoi(argv[1]);
	else 
	{
		printf("Please Input The Integer To Be Found\n");
		printf("Usage: ./find 42");
		exit(1);
	}
	while (1)
	{
		printset_modifiers(md);	
		md->Qset++;
	}
}
