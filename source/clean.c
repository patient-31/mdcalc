//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mindset/mdcalc/source/clean.c                                           ***//
//***     Path: /media/danielle/Stuff/Programs/mindset/mdcalc                                                              ***//
//***     Created Date: Thursday, August 8th 2024, 6:54:18 pm                                                              ***//
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



t_cleanup_function	cleanup(t_calculate *c)
{
	free_strings(c);
	free_textures(c);
	free_numbers(c);
	free_rectangles(c);
	
	TTF_CloseFont(c->font);
	SDL_DestroyRenderer(c->renderer);	
	SDL_DestroyWindow(c->window);
	SDL_Quit();
	if (c)
		free(c);
}

none free_strings(t_calculate *c)
{
	if (c->title)
		free(c->title);
	if (c->md_pd)
		dc_free_2d_i_H(c->md_pd, 34);
	if (c->op_text)
		free(c->op_text);
	if (c->result_text)
		free(c->result_text);
	if (c->digitstr)
		dc_free_2d_i_H(c->digitstr, 25);
	if (c->indexer_and_ops)
		dc_free_3d_i_H(c->indexer_and_ops, 5, 5);
	if (c->tokens)
		dc_free_2d_i_H(c->tokens, 16);
}

none free_textures(t_calculate *c)
{
	if (c->pd_l_fnt_txtr)
		free_1d_SDL_textures_surfaces(c->pd_l_fnt_txtr, c->pd_l_fnt_surf, 16);
	if (c->pd_r_fnt_txtr)
		free_1d_SDL_textures_surfaces(c->pd_r_fnt_txtr, c->pd_r_fnt_surf, 16);
	if (c->digit_fnt_txtr)
		free_1d_SDL_textures_surfaces(c->digit_fnt_txtr, c->digit_fnt_surf, 25);	
	if (c->op_fnt_txtr)
	{
		SDL_FreeSurface(c->op_fnt_surf);
		SDL_DestroyTexture(c->op_fnt_txtr);
	}
	if (c->result_fnt_txtr)
	{
		SDL_FreeSurface(c->result_fnt_surf);
		SDL_DestroyTexture(c->result_fnt_txtr);
	}
}

none free_numbers(t_calculate *c)
{
	if (c->flag_hover_for_pd)
		free(c->flag_hover_for_pd);
	if (c->flag_hover_for_digit_box)
		dc_free_2d_i_P(c->flag_hover_for_digit_box, 5);
}

none free_rectangles(t_calculate *c)
{
	if (c->pd_l_box)
		free_1d_SDL_Rect(c->pd_l_box, 16);
	if (c->pd_r_box)
		free_1d_SDL_Rect(c->pd_r_box, 16);
	if (c->op_box)
		free(c->op_box);
	if (c->digit_box)
		free_2d_SDL_Rect(c->digit_box, 5, 5);
	if (c->result_box)
		free(c->result_box);
}