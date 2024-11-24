//____________________________________________________________________________________________________________________________//
//*__________________________________________________________________________________________________________________________*//
//**________________________________________________________________________________________________________________________**//
//***     Filename: /media/danielle/Stuff/Programs/mindset/includes/md_function.h                                          ***//
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

# ifndef MD_FUNCTION_H
# define MD_FUNCTION_H

// t_cleanup_function	cleanup(t_program *o);


int		lstlen(char **list);
void	error_exit(char *mess, int error_type, t_md *md);
void	exit_program(int error_type, t_md *md);
void	free_2d_char(char **f, int len);
void	init_struct(t_md *md);
void	drop_float_tail(char *dropee, int drop_size);
void	printset_modifiers(t_md *md);
void	Operation(t_md *md);
void	Check_Op(t_md *md);
int		isInteger(char *c);

// DANC_C
char				*dc_get_next_line(int fd);						// Gets the next line of a function up to the '\n' character, on each subsequent call
uP_2				md_val(char *_x_);								// Converts md-number to unsigned long int
i_H					*itomd(iP_2 d);
i_H					*dc_strjoin_e(uP_2 c, ...);						// variable number string joiner
i_H					*dc_itoa(iP_2 n);								// integer to ascii
uP_2				dc_strlen(i_H *c); 								// counts string
i_H					*dc_strdup(i_H *s1); 							// creates pointer and replicates the reference
i_H					**dc_tdup(i_H **t1);							// creates pointer to pointer array and replicates all references
uP_2				dc_lstlen(i_H **list);							// returns length of 2d list
witch				dc_witch(i_H *s);								// checks if witch returns false -> returns true
i_H					*dc_substr(i_H *s, uP_2 start, uP_2 len);		// grabs a section of a string from start to (start + len)
i_H					*dc_strndup(i_H *s, uP_2 n);					// creates a pointer and replicates the reference up to size n
uP_2				dc_wordcount(i_H *s, i_H c);					// for dc_split, counts words.
i_H					**dc_split(i_H *s, i_H c);						// takes string as input and splits into tokens based on delimiter c
i_P					dc_strncmp(i_H *s1, i_H *s2, iP_2 n);			// compares two strings up to n and returns comparison.															
i_P					longlongcheck(i_H *input);
i_H					*dc_strchr(const i_H *s, i_P c);				// finds a character in a string, left to right, returns a pointer to the string at the characters position
// none				dc_error_exit(i_H *mess, 						// Assign verbose message for clear error determination
// 						iP_1 error_type,							// Assign error code for terminal output on error
// 							t_program *strct, 						// Assign custom cleanup for strct {o - in this program} with type 
// 								p_cleanup_function cleanup);		// t_cleanup_function (none) for technical presentation and debugging
// error				dc_ERROR_MEM(t_program *o, i_H *mess);			// calls dc_error_exit with memory allocation specific message, assigns the error to error.txt in project root
// error				dc_ERROR_MEM_index(t_program *o,				// same as above, assigns index specific variables or any chosen numbers ro later review to error.txt 
// 						i_H *mess,											
// 							iP_1 v1,
// 								iP_1 v2,
// 									iP_1 v3);

i_P					dc_alloc_2D_i_H(i_H ***object,
						u_P strings,
							u_P characters);						// allocates sizes for 2d i_H array, parameter must use reference '&object'
none				dc_free_2d_i_H(i_H **f, uP_2 len);				// frees 2d i_H array

uP_2				get_time(void);
none				sleepbee(u_P time);

#endif