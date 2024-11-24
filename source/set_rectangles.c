/*
 * ________________________________________________________________________________
 * |  File: set_rectangles.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/mdcalc.h"

none	set_rectangular_placements(t_calculate *c)
{
	set_pd_l_box(c);
	set_pd_r_box(c);
	set_digit_box(c);
	set_op_box(c);
	set_result_box(c);
}

none	set_pd_l_box(t_calculate *c)
{
	u_P	i;
	
	uP_1 x;
	uP_1 y;
	uP_1 w;
	uP_1 h;

	x = _B;
	y = 0;
	w = md_val("O_3");
	h = md_val("O_3");

	i = 0;
	c->pd_l_box = malloc(sizeof(SDL_Rect *) * _P);
	if (!c->pd_l_box)
		dc_ERROR_MEM(c, "pd_l_box");
	while (i < _P)
	{
		c->pd_l_box[i] = malloc(sizeof(SDL_Rect));
		if (!c->pd_l_box[i])
			dc_ERROR_MEM_index(c, "pd_l_box[i]", i, -1, -1);
		c->pd_l_box[i]->x = x;
		c->pd_l_box[i]->y = y;
		c->pd_l_box[i]->w = w;
		c->pd_l_box[i]->h = h;
		i++;
		y += h + _B;
		if (i == 8)
		{
			x = md_val("P_3") + _B;
			y = 0;
		}
	}
}

none	set_pd_r_box(t_calculate *c)
{
	u_P	i;
	
	uP_1 x;
	uP_1 y;
	uP_1 w;
	uP_1 h;

	w = md_val("O_3");
	x = md_val("O_21");
	y = 0;
	h = md_val("O_3");;

	i = 0;
	c->pd_r_box = malloc(sizeof(SDL_Rect *) * _P);
	if (!c->pd_r_box)
		dc_ERROR_MEM(c, "pd_r_box");
	while (i < _P)
	{
		c->pd_r_box[i] = malloc(sizeof(SDL_Rect));
		if (!c->pd_r_box[i])
			dc_ERROR_MEM_index(c, "pd_r_box[i]", i, -1, -1);
		c->pd_r_box[i]->x = x;
		c->pd_r_box[i]->y = y;
		c->pd_r_box[i]->w = w;
		c->pd_r_box[i]->h = h;
		i++;
		y += h + _B;
		if (i == 8)
		{
			x = md_val("O_24") + _B;
			y = 0;
		}
	}
}

none	set_digit_box(t_calculate *c)
{
	u_P	i;
	u_P	q;
	
	u_P x;
	u_P y;
	u_P w;
	u_P h;

	x = md_val("P_6") + 3;
	y = md_val("P_9") + 3;
	w = md_val("O_3");
	h = md_val("O_3");

	i = STARTSET;
	c->digit_box = malloc(sizeof(SDL_Rect **) * _E);
	while (i < _E)
	{
		q = STARTSET;
		c->digit_box[i] = malloc(sizeof(SDL_Rect *) * _E);
		while(q < _E)
		{
			c->digit_box[i][q] = malloc(sizeof(SDL_Rect));
			c->digit_box[i][q]->x = x;
			c->digit_box[i][q]->y = y;
			c->digit_box[i][q]->w = w;
			c->digit_box[i][q]->h = h;
			q++;
			x += w;
		}
		x = md_val("P_6") + 3;
		i++;
		y += h + _B;
	}
}

none	set_op_box(t_calculate *c)
{
	c->op_box = malloc(sizeof(SDL_Rect));
	c->op_box->x = md_val("P_6") + 3;
	c->op_box->y = md_val("P_5") + 3;
	c->op_box->w = md_val("K_15");
	c->op_box->h = md_val("O_4");
}

none	set_result_box(t_calculate *c)
{
	c->result_box = malloc(sizeof(SDL_Rect));
	c->result_box->x = md_val("P_6") + 3;
	c->result_box->y = _B;
	c->result_box->w = md_val("K_15");
	c->result_box->h = md_val("P_5");
}