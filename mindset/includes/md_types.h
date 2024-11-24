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



typedef struct s_md
{
	char	**set_list;
	int		c;
	int		d;
	u64		a;
	int		Qset;
	int		MdSet;
	long	find;		
	double	value;
	int		value_c;
	char	*drop_tail;
	char	*drop_tail__floor;
	char	*l;
	char	*r;
	int		floored;
	double	_floor;
	double	modifier;
	int		pattern_descriptor;
	bool	check;
}	t_md;



// typedef struct s_program
// {

// } t_program;


// typedef	void		(*p_cleanup_function)(t_program *);

#endif