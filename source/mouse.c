/*
 * ________________________________________________________________________________
 * |  File: mouse.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/mdcalc.h"

witch is_mouse_over_rect(t_calculate *c, SDL_Rect *rect)
{
	return (c->mouseX >= rect->x && c->mouseX <= rect->x + rect->w && c->mouseY >= rect->y && c->mouseY <= rect->y + rect->h);
}

none check_click_status(t_calculate *c)
{
	i_P i;
	i_P q;

	i = 0;
	while (i < _P)
	{
		if (is_mouse_over_rect(c, c->pd_l_box[i]))
		{
			if (c->number_flag == 0)
			{
				c->number_flag = 1;
				c->digitcount = 0;
				receive_input(c, c->md_pd[i + 1]);
			}	
		}
		i++;
	}

	i = 0;
	while (i < _P)
	{
		if (is_mouse_over_rect(c, c->pd_r_box[i]))
		{
			if (c->number_flag == 0)
			{
				c->number_flag = 1;
				c->digitcount = 0;
				receive_input(c, c->md_pd[i + 17]);
			}
		}
		i++;
	}

	i = 0;
	while (i < _E)
	{
		q = 0;
		while (q < _E)
		{
			if ((c->number_flag == 1 || c->number_flag == 2) && q < 2)
			{
				if (is_mouse_over_rect(c, c->digit_box[i][q]))
				{
					c->number_flag = 2;
					if (c->digitcount == DIGITMAX)
						break ;
					c->digitcount += 1;
					receive_input(c, c->indexer_and_ops[i][q]);
				}	
			}
			else if (c->number_flag == 2 && q == 4)
			{
				if (is_mouse_over_rect(c, c->digit_box[i][q]))
				{
					c->number_flag = 0;
					receive_input(c, c->indexer_and_ops[i][q]);
				}		
			}
			else if (c->number_flag == 2 && q == 2 && i == 4)
			{
				if (is_mouse_over_rect(c, c->digit_box[i][q]))
				{
					c->number_flag = 0;
					receive_input(c, c->indexer_and_ops[i][q]);
				}					
			}	
			q++;
		}
		i++;
	}
}

none check_hover_status(t_calculate *c)
{
	memset(c->flag_hover_for_pd, 0, 32 * sizeof(i_P));

	i_P b;

	b = 0;
	while (b < 5)
	{
		memset(c->flag_hover_for_digit_box[b], 0, 5 * sizeof(i_P));
		b++;
	}

	i_P i;
	i_P q;

	i = 0;
	while (i < _P)
	{
		if (is_mouse_over_rect(c, c->pd_l_box[i]))
		{
			c->flag_hover_for_pd[i] = 1;
		}
			
		i++;
	}

	i = 0;
	while (i < _P)
	{
		if (is_mouse_over_rect(c, c->pd_r_box[i]))
			c->flag_hover_for_pd[i + 16] = 1;

		i++;
	}

	i = 0;
	while (i < _E)
	{
		q = 0;
		while (q < _E)
		{
			if (is_mouse_over_rect(c, c->digit_box[i][q]))
				c->flag_hover_for_digit_box[i][q] = 1;		
			q++;
		}
		i++;
	}
}