/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:28:01 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/21 17:36:54 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <time.h>		// DELETE
# include <stdio.h>		// DELETE

typedef struct			s_flags
{
	int					f_l;
	int					f_R;
	int					f_a;
	int					f_r;
	int					f_t;
}						t_flags;

typedef struct			s_fold
{
	DIR					*rep;
	struct dirent		*readfile;
	struct stat			*info;
	int					index;
	char				**names;
}						t_fold;

/*
**		INIT FUNCTIONS
*/

void					init_flags_struct(t_flags *flags);
void					init_fold_struct(t_fold *fold);

/*
**		PARSING FUNCTIONS
*/

char					**parsing(char **arguments, t_flags *flags);
void					check_flags(t_flags *flags, char *str);
char					**get_fargs(char **arguments, int index);
char					**no_args(void);

/*
**		CORE FUNCTIONS
*/

int						recursive_func(char *path, int index, t_flags flags);
int						simply_dir(char **farg, t_flags flags);
char					**open_directory(char *path, t_flags flags);

/*
**		PRINT FUNCTIONS
*/

void					my_printf(char **str, t_flags flags);
void					print_no_flags(char **str, t_flags flags);
void					print_l_flag(char **str, t_flags flags);
void					lprint_2(char *str, struct stat sb);

void					print_rights(char *str, struct stat sb);
void					print_usr_rights(char *str, struct stat sb);
void					print_grp_rights(char *str, struct stat sb);
void					print_oth_rights(char *str, struct stat sb);

void					print_dependencies(char *str, struct stat sb);
void					print_author(char *str, struct stat sb);
void					print_group(char *str, struct stat sb);
void					print_time(char *str, struct stat sb);
void					print_type(char *str, struct stat sb);

/*
void					print_1(char **str, t_flags flags);
void					print_l_flag(char **str, t_flags flags);
*/

/*
**		ERRORS FUNCTIONS
*/

void					error(int a);
void					unknown_flags(char flag);
void					no_fildir(char *fildir);

/*
**		OTHER FUNCTIONS
*/

int						find_index(t_flags flags, char **str);
char					*clear_str(char *str);
char					*set_newpath(char *oldpath, char *newpath);
int						check_if_empty(char *path, t_flags flags);

#endif
