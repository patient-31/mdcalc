//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mdcalc/source/set_textures.c                                            ***//
//***     Path: /media/danielle/Stuff/Programs/mdcalc                                                                      ***//
//***     Created Date: Thursday, August 8th 2024, 8:57:15 pm                                                              ***//
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

# include "../includes/mdcalc.h"

none	set_textures(t_calculate *c)
{
	set_font(c);
	set_pd_l_box_texture(c);
	set_pd_r_box_texture(c);
	set_digit_box_texture(c);
	set_op_box_texture(c);
	set_result_box_texture(c);
}

none	set_pd_l_box_texture(t_calculate *c)
{
	u_P i;

	i = 0;
	c->pd_l_fnt_surf = malloc(sizeof(SDL_Surface *) * _P);
	if (!c->pd_l_fnt_surf)
		dc_ERROR_MEM(c, "c->pd_l_fnt_surf");
	c->pd_l_fnt_txtr = malloc(sizeof(SDL_Texture *) * _P);
	if (!c->pd_l_fnt_txtr)
		dc_ERROR_MEM(c, "c->pd_l_fnt_txtr");
	while (i < _P)
	{
		c->pd_l_fnt_surf[i] = TTF_RenderText_Solid(c->font, c->md_pd[i + 1] , c->font_colour);
		if (!c->pd_l_fnt_surf[i])
			dc_ERROR_MEM_index(c, "c->pd_l_fnt_surf[i]", i, -1, -1);
		c->pd_l_fnt_txtr[i] = SDL_CreateTextureFromSurface(c->renderer, c->pd_l_fnt_surf[i]);
		if (!c->pd_l_fnt_txtr[i])
			dc_ERROR_MEM_index(c, "c->pd_l_fnt_txtr[i]", i, -1, -1);
		i++;
	}
}

none	set_pd_r_box_texture(t_calculate *c)
{
	u_P i;


	i = 0;
	c->pd_r_fnt_surf = malloc(sizeof(SDL_Surface *) * _P);
	if (!c->pd_r_fnt_surf)
		dc_ERROR_MEM(c, "c->pd_r_fnt_surf");
	c->pd_r_fnt_txtr = malloc(sizeof(SDL_Texture *) * _P);
	if (!c->pd_r_fnt_txtr)
		dc_ERROR_MEM(c, "c->pd_r_fnt_txtr");
	while (i < _P)
	{
		c->pd_r_fnt_surf[i] = TTF_RenderText_Solid(c->font, c->md_pd[i + 17] , c->font_colour);
		if (!c->pd_r_fnt_surf[i])
			dc_ERROR_MEM_index(c, "c->pd_r_fnt_surf[i]", i, -1, -1);
		c->pd_r_fnt_txtr[i] = SDL_CreateTextureFromSurface(c->renderer, c->pd_r_fnt_surf[i]);
		if (!c->pd_r_fnt_txtr[i])
			dc_ERROR_MEM_index(c, "c->pd_r_fnt_txtr[i]", i, -1, -1);
		i++;
	}
}

none	set_digit_box_texture(t_calculate *c)
{
	u_P i;


	i = 0;
	c->digit_fnt_surf = malloc(sizeof(SDL_Surface *) * I_);
	if (!c->digit_fnt_surf)
		dc_ERROR_MEM(c, "c->digit_fnt_surf");
	c->digit_fnt_txtr = malloc(sizeof(SDL_Texture *) * I_);
	if (!c->digit_fnt_txtr)
		dc_ERROR_MEM(c, "c->digit_fnt_txtr");
	while (i < I_)
	{
		c->digit_fnt_surf[i] = TTF_RenderText_Solid(c->font, c->digitstr[i] , c->font_colour);
		if (!c->digit_fnt_surf[i])
			dc_ERROR_MEM_index(c, "c->digit_fnt_surf[i]", i, -1, -1);
		c->digit_fnt_txtr[i] = SDL_CreateTextureFromSurface(c->renderer, c->digit_fnt_surf[i]);
		if (!c->digit_fnt_txtr[i])
			dc_ERROR_MEM_index(c, "c->digit_fnt_txtr[i]", i, -1, -1);
		i++;
	}
}

none	set_op_box_texture(t_calculate *c)
{
	if (c->op_fnt_surf)
		SDL_FreeSurface(c->op_fnt_surf);
	c->op_fnt_surf = TTF_RenderText_Solid_Wrapped(c->font, c->op_text, c->font_colour, 200);
	if (!c->op_fnt_surf)
		dc_ERROR_MEM(c, "c->op_fnt_surf");
	if (c->op_fnt_txtr)
		SDL_DestroyTexture(c->op_fnt_txtr);
	c->op_fnt_txtr = SDL_CreateTextureFromSurface(c->renderer, c->op_fnt_surf);
	if (!c->op_fnt_txtr)
		dc_ERROR_MEM(c, "c->op_fnt_txtr");
}

none	set_result_box_texture(t_calculate *c)
{
	i_H* start = dc_strdup(" ");
	if (c->result_fnt_surf)
		SDL_FreeSurface(c->result_fnt_surf);
	if (c->result_text[0] == 0)
		c->result_fnt_surf = TTF_RenderText_Solid_Wrapped(c->font, start, c->font_colour2, 200);
	else 
		c->result_fnt_surf = TTF_RenderText_Solid_Wrapped(c->font, c->result_text, c->font_colour2, 200);
	if (!c->result_fnt_surf)
		dc_ERROR_MEM(c, "c->result_fnt_surf");
	if (c->result_fnt_txtr)
		SDL_DestroyTexture(c->result_fnt_txtr);
	c->result_fnt_txtr = SDL_CreateTextureFromSurface(c->renderer, c->result_fnt_surf);
	if (!c->result_fnt_txtr)
		dc_ERROR_MEM(c, "c->result_fnt_txtr");
	free(start);
}