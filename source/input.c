/*
 * ________________________________________________________________________________
 * |  File: input.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:47 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/mdcalc.h"

none	find_result(t_calculate *c)
{
	dP_2 result = 0.0;
	switch (c->tokencount)
	{
		case 0:
			result = md_val(c->tokens[c->tokencount]);
			break ;
		case 2:
			result = dc_find_result_mdcalc(c->tokencount, c->tokens[0], c->tokens[1], c->tokens[2]);
			break ;
		case 4:
			result = dc_find_result_mdcalc(c->tokencount, c->tokens[0], c->tokens[1], c->tokens[2], c->tokens[3], c->tokens[4]);
			break ;
		case 6:
			result = dc_find_result_mdcalc(c->tokencount, c->tokens[0], c->tokens[1], c->tokens[2], c->tokens[3], c->tokens[4], c->tokens[5], c->tokens[6]);
			break ;
		case 8:
			result = dc_find_result_mdcalc(c->tokencount, c->tokens[0], c->tokens[1], c->tokens[2], c->tokens[3], c->tokens[4], c->tokens[5], c->tokens[6], c->tokens[7], c->tokens[8]);
			break ;
		case 10:
			result = dc_find_result_mdcalc(c->tokencount, c->tokens[0], c->tokens[1], c->tokens[2], c->tokens[3], c->tokens[4], c->tokens[5], c->tokens[6], c->tokens[7], c->tokens[8], c->tokens[9], c->tokens[10]);
			break ;
		case 12:
			result = dc_find_result_mdcalc(c->tokencount, c->tokens[0], c->tokens[1], c->tokens[2], c->tokens[3], c->tokens[4], c->tokens[5], c->tokens[6], c->tokens[7], c->tokens[8], c->tokens[9], c->tokens[10], c->tokens[11], c->tokens[12]);
			break ;
		case 14:
			result = dc_find_result_mdcalc(c->tokencount, c->tokens[0], c->tokens[1], c->tokens[2], c->tokens[3], c->tokens[4], c->tokens[5], c->tokens[6], c->tokens[7], c->tokens[8], c->tokens[9], c->tokens[10], c->tokens[11], c->tokens[12], c->tokens[13], c->tokens[14]);
			break ;
		default:
			result = 0.0;
			break ;
	}
	
	sprintf(c->result_text, "%f", result);
	drop_float_tail(c->result_text, 3);
	set_result_box_texture(c);
}

none	reset_tokens(t_calculate *c)
{
	int i = 0;
	while (i < TOKENMAX)
	{
		memset(c->tokens[i], '\0', sizeof(i_H) * MDMAX);
		i++;
	}
	c->tokencount = 0;
	c->digitcount = 0;
}

none	input_lexer(t_calculate *c, i_H *input)
{
	if (strcmp(input, "=") == 0)
		return ;
	if (c->number_flag == 1)
		strcat(c->tokens[c->tokencount], input);
	if (c->number_flag == 2)
		strcat(c->tokens[c->tokencount], input);
	if (c->number_flag == 0)
	{
		c->tokencount += 1;
		strcat(c->tokens[c->tokencount], input);
		c->tokencount += 1;
	}
}

none	receive_input(t_calculate *c, i_H *input)
{	
	if (c->tokencount == TOKENMAX)
		goto here;
	input_lexer(c, input);
	i_H *temp = dc_strdup(c->op_text);
	if (c->op_text)
		free(c->op_text);
	c->op_text = dc_strjoin_e(2, temp, input);
	free(temp);
	set_op_box_texture(c);
	if (strcmp(input, "=") == 0)
	{
		find_result(c);
		dc_print_list_2d_size(c->tokens, c->tokencount + 1);
		reset_tokens(c);
		free(c->op_text);
		c->op_text = dc_strdup(" ");
	}
	if (strcmp(input, "BS") == 0)
	{
	here:
		reset_tokens(c);
		free(c->op_text);
		c->op_text = dc_strdup(" ");
		set_op_box_texture(c);
	}
}