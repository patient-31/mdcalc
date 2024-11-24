/*
 * ________________________________________________________________________________
 * |  File: render.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/mdcalc.h"

none render_logic(t_calculate *c)
{
	render_background_and_borders(c);

	SDL_RenderPresent(c->renderer);
}

none render_background_and_borders(t_calculate *c)
{
	SDL_SetRenderDrawColor(c->renderer, 0, 0, 0, 96);
	SDL_RenderClear(c->renderer);

	SDL_SetRenderDrawBlendMode(c->renderer, SDL_BLENDMODE_BLEND);

	render_pd_l_box(c);
	render_pd_r_box(c);
	render_digit_box(c);
	render_op_box(c);
	render_result_box(c);
}

none	render_pd_l_box(t_calculate *c)
{
	i_P i;

	i = 0;
	while(i < _P)
	{
		if (c->flag_hover_for_pd[i] == 1)
			SDL_SetRenderDrawColor(c->renderer, 0, 255, 0, 200);
		else if (c->flag_hover_for_pd[i] == 0)
			SDL_SetRenderDrawColor(c->renderer, 0, 200, 0, 200);
		SDL_RenderFillRect(c->renderer, c->pd_l_box[i]);
		SDL_SetRenderDrawColor(c->renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(c->renderer, c->pd_l_box[i]);
		SDL_RenderCopy(c->renderer, c->pd_l_fnt_txtr[i], NULL, c->pd_l_box[i]);
		i++;
	}
}

none	render_pd_r_box(t_calculate *c)
{
	i_P i;

	i = 0;
	while(i < _P)
	{
		if (c->flag_hover_for_pd[i + 16] == 1)
			SDL_SetRenderDrawColor(c->renderer, 0, 255, 0, 200);
		else if (c->flag_hover_for_pd[i + 16] == 0)
			SDL_SetRenderDrawColor(c->renderer, 0, 200, 0, 200);
		SDL_RenderFillRect(c->renderer, c->pd_r_box[i]);
		SDL_SetRenderDrawColor(c->renderer, 0, 0, 0, 255);
		SDL_RenderDrawRect(c->renderer, c->pd_r_box[i]);
		SDL_RenderCopy(c->renderer, c->pd_r_fnt_txtr[i], NULL, c->pd_r_box[i]);
		i++;
	}
}

none	render_digit_box(t_calculate *c)
{
	int i;
	int q;
	int k;

	i = 0;
	q = 0;
	k = 0;
	while (i < _E)
	{
		q = 0;
		while (q < _E)
		{
			if (c->flag_hover_for_digit_box[i][q] == 1)
				SDL_SetRenderDrawColor(c->renderer, 255, 0, 255, 200);
			else if (c->flag_hover_for_digit_box[i][q] == 0)
				SDL_SetRenderDrawColor(c->renderer, 200, 0, 200, 200);
			SDL_RenderFillRect(c->renderer, c->digit_box[i][q]);
			SDL_SetRenderDrawColor(c->renderer, 0, 0, 0, 255);
			SDL_RenderDrawRect(c->renderer, c->digit_box[i][q]);
			SDL_RenderCopy(c->renderer, c->digit_fnt_txtr[k], NULL, c->digit_box[i][q]);
			q++;
			k++;
		}
		i++;
	}
}

none render_op_box(t_calculate *c)
{

	SDL_SetRenderDrawColor(c->renderer, 255, 255, 255, 200);
	SDL_RenderFillRect(c->renderer, c->op_box);
	SDL_SetRenderDrawColor(c->renderer, 0, 0, 0, 255);
	SDL_RenderDrawRect(c->renderer, c->op_box);
	SDL_RenderCopy(c->renderer, c->op_fnt_txtr, NULL, c->op_box);	
}

none render_result_box(t_calculate *c)
{

	SDL_SetRenderDrawColor(c->renderer, 0, 0, 0, 200);
	SDL_RenderFillRect(c->renderer, c->result_box);
	SDL_SetRenderDrawColor(c->renderer, 196, 0, 196, 255);
	SDL_RenderDrawRect(c->renderer, c->result_box);
	SDL_RenderCopy(c->renderer, c->result_fnt_txtr, NULL, c->result_box);	
}