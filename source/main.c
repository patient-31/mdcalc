/*
 * ________________________________________________________________________________
 * |  File: main.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

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