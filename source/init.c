//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mdcalc/source/init.c                                                    ***//
//***     Path: /media/danielle/Stuff/Programs/mdcalc                                                                      ***//
//***     Created Date: Thursday, August 8th 2024, 7:08:30 pm                                                              ***//
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

#include "../includes/mdcalc.h"

none	init_mdcalc(t_calculate *c, i_H * title)
{
	c->number_flag = 0;
	if(!dc_alloc_2D_i_H(&c->tokens, TOKENMAX, MDMAX))
		dc_ERROR_MEM(c, "c->tokens allocation");
	int i = 0;
	while (i < TOKENMAX)
	{
		memset(c->tokens[i], '\0', sizeof(i_H) * MDMAX);
		i++;
	}
	c->tokencount = 0;
	set_strings(c, title);
	initialise_library_utilities(c);
	set_window_and_renderer(c);
	set_rectangular_placements(c); // SRP_C
	set_textures(c);
	c->flag_hover_for_pd = calloc(sizeof(i_P), 32);
	c->flag_hover_for_digit_box = malloc(sizeof(i_P *) * 5);
	i_P b;

	b = 0;
	while (b < 5)
	{
		c->flag_hover_for_digit_box[b] = calloc(sizeof(i_P), 5);
		b++;
	}

}


none	set_font(t_calculate *c)
{
	c->font = TTF_OpenFont("./fonts/FreePixel.ttf", 16);
	if (!c->font)
		dc_ERROR_MEM(c, "FreePixel.ttf FONT NOT FOUND");

	c->font_colour.b = 0;
	c->font_colour.g = 0;
	c->font_colour.r = 0;
	c->font_colour.a = 255;

	c->font_colour2.b = 196;
	c->font_colour2.g = 55;
	c->font_colour2.r = 196;
	c->font_colour2.a = 255;
}

none	set_digitstr(t_calculate *c)
{
	c->digitstr			= malloc(sizeof(char *) * 25);
	if (!c->digitstr)
		dc_ERROR_MEM(c, "c->digitstr");

	c->digitstr[_A - 1]		= dc_strdup("8");   
	c->digitstr[_B - 1]		= dc_strdup("9");
	c->digitstr[_C - 1]		= dc_strdup(" ");
	c->digitstr[_D - 1]		= dc_strdup(" ");
	c->digitstr[_E - 1]		= dc_strdup("BS");

	c->digitstr[_F - 1]		= dc_strdup("6");
	c->digitstr[_G - 1]		= dc_strdup("7");
	c->digitstr[_H - 1]		= dc_strdup(" ");
	c->digitstr[_I - 1]		= dc_strdup(" ");
	c->digitstr[_J - 1]		= dc_strdup("/");

	c->digitstr[_K - 1]		= dc_strdup("4");
	c->digitstr[_L - 1]		= dc_strdup("5");
	c->digitstr[_M - 1]		= dc_strdup(" ");
	c->digitstr[_N - 1]		= dc_strdup(" ");
	c->digitstr[_O - 1]		= dc_strdup("-");

	c->digitstr[_P - 1]		= dc_strdup("2");
	c->digitstr[A_ - 1]		= dc_strdup("3");
	c->digitstr[B_ - 1]		= dc_strdup(" ");
	c->digitstr[C_ - 1]		= dc_strdup(" ");
	c->digitstr[D_ - 1]		= dc_strdup("*");

	c->digitstr[E_ - 1]		= dc_strdup("0");
	c->digitstr[F_ - 1]		= dc_strdup("1");
	c->digitstr[G_ - 1]		= dc_strdup("=");
	c->digitstr[H_ - 1]		= dc_strdup(" ");
	c->digitstr[I_ - 1]		= dc_strdup("+");

	c->indexer_and_ops = malloc(sizeof(i_H **) * 5);
	
	c->indexer_and_ops[0] = malloc(sizeof(i_H *) * 5);
	c->indexer_and_ops[0][0]		= dc_strdup("8");   
	c->indexer_and_ops[0][1]		= dc_strdup("9");
	c->indexer_and_ops[0][2]		= dc_strdup(" ");
	c->indexer_and_ops[0][3]		= dc_strdup(" ");
	c->indexer_and_ops[0][4]		= dc_strdup("BS");

	c->indexer_and_ops[1] = malloc(sizeof(i_H *) * 5);
	c->indexer_and_ops[1][0]		= dc_strdup("6");   
	c->indexer_and_ops[1][1]		= dc_strdup("7");
	c->indexer_and_ops[1][2]		= dc_strdup(" ");
	c->indexer_and_ops[1][3]		= dc_strdup(" ");
	c->indexer_and_ops[1][4]		= dc_strdup("/");

	c->indexer_and_ops[2] = malloc(sizeof(i_H *) * 5);
	c->indexer_and_ops[2][0]		= dc_strdup("4");   
	c->indexer_and_ops[2][1]		= dc_strdup("5");
	c->indexer_and_ops[2][2]		= dc_strdup(" ");
	c->indexer_and_ops[2][3]		= dc_strdup(" ");
	c->indexer_and_ops[2][4]		= dc_strdup("-");
	
	c->indexer_and_ops[3] = malloc(sizeof(i_H *) * 5);
	c->indexer_and_ops[3][0]		= dc_strdup("2");   
	c->indexer_and_ops[3][1]		= dc_strdup("3");
	c->indexer_and_ops[3][2]		= dc_strdup(" ");
	c->indexer_and_ops[3][3]		= dc_strdup(" ");
	c->indexer_and_ops[3][4]		= dc_strdup("*");
	
	c->indexer_and_ops[4] = malloc(sizeof(i_H *) * 5);
	c->indexer_and_ops[4][0]		= dc_strdup("0");   
	c->indexer_and_ops[4][1]		= dc_strdup("1");
	c->indexer_and_ops[4][2]		= dc_strdup("=");
	c->indexer_and_ops[4][3]		= dc_strdup(" ");
	c->indexer_and_ops[4][4]		= dc_strdup("+");


	i_P i = 0;

	while (i < 25)
	{
		if (!c->digitstr[i])
			dc_ERROR_MEM_index(c, "o->digitstr[i]", i, -1, -1);
		i++;
	}
}

none	set_pattern_descriptors(t_calculate *c)
{
	c->md_pd			= malloc(sizeof(char *) * 34);
	if (!c->md_pd)
		dc_ERROR_MEM(c, "c->md_pd");

	c->md_pd[STARTSET]	= dc_strdup("STARTSET");
	c->md_pd[_A]		= dc_strdup("_A");   
	c->md_pd[_B]		= dc_strdup("_B");
	c->md_pd[_C]		= dc_strdup("_C");
	c->md_pd[_D]		= dc_strdup("_D");
	c->md_pd[_E]		= dc_strdup("_E");
	c->md_pd[_F]		= dc_strdup("_F");
	c->md_pd[_G]		= dc_strdup("_G");
	c->md_pd[_H]		= dc_strdup("_H");
	c->md_pd[_I]		= dc_strdup("_I");
	c->md_pd[_J]		= dc_strdup("_J");
	c->md_pd[_K]		= dc_strdup("_K");
	c->md_pd[_L]		= dc_strdup("_L");
	c->md_pd[_M]		= dc_strdup("_M");
	c->md_pd[_N]		= dc_strdup("_N");
	c->md_pd[_O]		= dc_strdup("_O");
	c->md_pd[_P]		= dc_strdup("_P");
	c->md_pd[A_]		= dc_strdup("A_");
	c->md_pd[B_]		= dc_strdup("B_");
	c->md_pd[C_]		= dc_strdup("C_");
	c->md_pd[D_]		= dc_strdup("D_");
	c->md_pd[E_]		= dc_strdup("E_");
	c->md_pd[F_]		= dc_strdup("F_");
	c->md_pd[G_]		= dc_strdup("G_");
	c->md_pd[H_]		= dc_strdup("H_");
	c->md_pd[I_]		= dc_strdup("I_");
	c->md_pd[J_]		= dc_strdup("J_");
	c->md_pd[K_]		= dc_strdup("K_");
	c->md_pd[L_]		= dc_strdup("L_");
	c->md_pd[M_]		= dc_strdup("M_");
	c->md_pd[N_]		= dc_strdup("N_");
	c->md_pd[O_]		= dc_strdup("O_");
	c->md_pd[P_]		= dc_strdup("P_");
	c->md_pd[ENDSET]	= dc_strdup("ENDSET");

	i_P i = STARTSET;

	while (i < ENDSET)
	{
		if (!c->md_pd[i])
			dc_ERROR_MEM_index(c, "o->md_pd[i]", i, -1, -1);
		i++;
	}
}

none	initialise_library_utilities(t_calculate *c)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		dc_ERROR_MEM(c, "SDL_Init");
	if (TTF_Init() == -1)
		dc_ERROR_MEM(c, "TTF_Init");
}

none	set_strings(t_calculate *c, i_H *title)
{
	c->title = dc_strdup(title);
	c->op_text = dc_strdup(" ");
	c->result_text = malloc(sizeof(i_H *) * 32);
	c->result_text[0] = 0;
	set_pattern_descriptors(c);
	set_digitstr(c);
	
}

none	set_window_and_renderer(t_calculate *c)
{
	c->window = SDL_CreateWindow  ( c->title, 
    								SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
    								WIN_WIDTH, WIN_HEIGHT, 
    								SDL_WINDOW_SHOWN	);
    if (!c->window)
	{
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		dc_ERROR_MEM(c, "c->window");
    }


	c->renderer = SDL_CreateRenderer(c->window, -1, 0);
	if (!c->renderer)
	{
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        dc_ERROR_MEM(c, "c->render");
    }
}