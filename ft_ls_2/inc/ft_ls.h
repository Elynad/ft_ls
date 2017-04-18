/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:03:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/18 10:36:45 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

#include "../libft/libft.h"
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>		// DELETE BEFORE LAST PUSH

typedef struct		s_folders
{
	DIR					*rep;
	struct dirent		*readfile;
	struct stat			*info;
	char				**names;
	int					index;
	struct s_folders	*next;
}					t_folders;

typedef struct		s_flags
{
	int				f_l;
	int				f_R;
	int				f_a;
	int				f_r;
	int				f_t;
}					t_flags;

typedef struct		s_box
{
	DIR				*rep;
	struct dirent	*readfile;
	struct stat		*info;
}					t_box;

typedef struct		s_flist
{
	char			*folder;
	struct s_flist	*next;
}					t_flist;

int					recursive_test(t_flags flags);
int					test_1(t_flags flags, char **arguments); // NEED TO RENAME
int					test_2(t_flags flags, char **arguments, int index);

/*
**		SORTING
*/

void				ft_swap_str(char **s1, char **s2);
int					ft_check_str(char **str);
char				**alpha_sorting(char **str);

/*
**		PRINTING
*/

void				my_printf(char **str, t_flags flags);
void				print_no_flags(char **str, t_flags flags);
void				print_l_flag(char **str, t_flags flags);
void				lprint_2(char *str, struct stat sb);

/*
**		PRINTING WITHIN
*/

void				print_type(char *str, struct stat sb);
void				print_dependencies(char *str, struct stat sb);
void				print_author(char *str, struct stat sb);
void				print_group(char *str, struct stat sb);
void				print_time(char *str, struct stat sb);

/*
**		PRINTING RIGHTS
*/

void				print_rights(char *str, struct stat sb);
void				print_usr_rights(char *str, struct stat sb);
void				print_grp_rights(char *str, struct stat sb);
void				print_oth_rights(char *str, struct stat sb);

/*
**		PARSING
*/

char				**parsing(t_flags *flags, char **arguments);
void				check_flags(t_flags *flags, char *str);
void				flag_error(char flag);
char				**get_files_param(char **arguments, int index);

/*
**		OTHER
*/

void				fusion(char **double_char, char **str);
void				init_flags_struct(t_flags *flags);
void				init_folders_struct(t_folders *folders);
void				error(int a);
int					find_index(t_flags flags);

#endif
