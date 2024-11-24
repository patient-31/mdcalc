//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mdcalc/source/main.c                                                    ***//
//***     Path: /media/danielle/Stuff/Programs/mdcalc                                                                      ***//
//***     Created Date: Thursday, August 8th 2024, 6:35:51 pm                                                              ***//
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

int main(none)
{
	t_calculate *c;

	c = malloc(sizeof(t_calculate));
	*c = (t_calculate){0};

	init_mdcalc(c, "mdcalc");

	while (_A)
	{
		while (SDL_PollEvent(&c->event))
		{
			if (c->event.type == SDL_QUIT)
			{
				cleanup(c);
				return (0);
			}
			else if (c->event.type == SDL_KEYDOWN)
			{
				switch (c->in = c->event.key.keysym.sym)
				{
					case (SDLK_ESCAPE):
						cleanup(c);
						return (0);
						break;
				}
			}
			else if (c->event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (c->event.button.button == SDL_BUTTON_LEFT)
				{
					check_click_status(c);
				}
			}
			else if (c->event.type == SDL_MOUSEMOTION)
			{
				c->mouseX = c->event.motion.x;
				c->mouseY = c->event.motion.y;
				check_hover_status(c);
			}
		}
		render_logic(c);
		sleepbee(50);
	}
}