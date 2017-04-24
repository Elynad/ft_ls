/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:24:33 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 19:27:24 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>

typedef struct				s_flags
{
	int						f_l;
	int						f_R;
	int						f_a;
	int						f_r;
	int						f_t;
}							t_flags;

typedef struct				s_fold
{
	DIR						*rep;
	struct dirent			*readfile;
	struct stat				*info;
	int						index;
	char					**names;
}							t_fold;

/*
**		INIT FUNCTIONS
*/

void						init_flags_struct(t_flags *flags);
void						init_fold_struct(t_fold *folf);

/*
**		PARSING FUNCTIONS
*/

char						**parsing(char **arguments, t_flags *flags);
void						check_flags(t_flags *flags, char *str);
char						**get_fargs(char **arguments, int index);
char						**no_args(void);

/*
**		CORE FUNCTIONS
*/

int							recursive_func(char *path, int index, t_flags flags);
char						**open_directory(char *path, t_flags flags);
char						*set_newpath(char *oldpath, char *newpath);

/*
**		PRINTING FUNCTIONS
*/

void						my_printf(char **str, t_flags flags);
void						print_1(char **str, t_flags flags);

/*
**		SORTING FUNCTIONS
*/

char						**sorting_fargs(char **fargs);
char						**sort_2(char **fargs, int *tab);
char						**sort_3(char **fargs, int *tab);
void						swap(int *a, int *b);
int							check_sorted(char **str, int *tab);
void						clear_double_string(char ***str);

/*
**		ERRORS FUNCTIONS
*/

void						error(int a, char *str);

#endif
