//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mindset/includes/md_types.h                                             ***//
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

#ifndef MD_TYPES_H
#define MD_TYPES_H

typedef unsigned long long u64;
typedef unsigned char			u_H;
typedef unsigned short			u_P;
typedef unsigned int			uP_1;
typedef unsigned long			uP_2;

typedef char					i_H;
typedef short					i_P;
typedef int						iP_1;
typedef long					iP_2;

typedef float					fP_1;
typedef double					dP_2;

typedef	void					t_cleanup_function;
typedef	void					error;
typedef void					none;
typedef bool					witch;



typedef struct s_calculate
{
	i_H				**tokens;
	uP_1			*number_tokens;
	i_P				*marker;
	i_P				digitcount;
	i_P				tokencount;
	SDL_Event 		event;
	iP_1			in;
	SDL_Window 		*window;
	SDL_Renderer 	*renderer;
	i_H				*title;
	i_H				**md_pd;
	i_H				**digitstr;
	TTF_Font		*font;
	SDL_Color		font_colour;
	SDL_Color		font_colour2;
	i_P				mouseX;
	i_P				mouseY;
	i_P				*flag_hover_for_pd;
	i_P				**flag_hover_for_digit_box;
	i_H				***indexer_and_ops;
	i_P				number_flag;

		// left_pane (patterndescriptors _A to _P)
		SDL_Rect 	**pd_l_box;
		SDL_Texture	**pd_l_fnt_txtr;
		SDL_Surface	**pd_l_fnt_surf;
		// right_pane (patterndescriptos A_ to P_)
		SDL_Rect 	**pd_r_box;
		SDL_Texture	**pd_r_fnt_txtr;
		SDL_Surface	**pd_r_fnt_surf;
		// middle_pane (base10 digits and operators)
		SDL_Rect 	***digit_box;
		SDL_Texture	**digit_fnt_txtr;
		SDL_Surface	**digit_fnt_surf;
		// operation_pane
		i_H			*op_text;
		SDL_Rect 	*op_box;
		SDL_Texture	*op_fnt_txtr;
		SDL_Surface	*op_fnt_surf;
		// content_pane
		i_H			*result;
		i_H			*result_text;
		SDL_Rect 	*result_box;
		SDL_Texture	*result_fnt_txtr;
		SDL_Surface	*result_fnt_surf;
		



} t_calculate;


typedef	void		(*p_cleanup_function)(t_calculate *);

#endif