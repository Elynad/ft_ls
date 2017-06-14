/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 10:49:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/14 17:21:28 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>			// Delete before last push
# include <stdio.h>			// Delete before last push
# include <pwd.h>
# include <grp.h>

typedef struct			s_lst
{
	char				*name;
	char				*path;
	struct stat			sb;
	int					error;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_flags
{
	int					f_l;
	int					f_a;
	int					f_R;
	int					f_r;
	int					f_t;
}						t_flags;

typedef struct			s_fold
{
	DIR					*rep;
	struct dirent		*readfile;
}						t_fold;

typedef struct			s_info
{
	char				*name;
	char				*group;
}						t_info;

/*
**			INIT
*/

void					init_flags_struct(t_flags *flags);
void					init_fold_struct(t_fold *fold);

/*
**			PARSING
*/

t_lst					*parsing(char **argv, t_flags *flags);
void					get_flags(char *str, t_flags *flags);
void					first_elem(char *name, t_lst *list);
void					add_elem(char *name, t_lst *list);

/*
**			CORE
*/

void					submain(t_lst *fargs, t_flags flags);
void					core(char *path, t_flags flags);
t_lst					*open_directory(char *path, t_flags flags);
void					first(t_lst *content, char *name, char *path, int *tmp);
void					next(t_lst *content, char *name, char *path);
char					*set_path(char *name, char *path);
void					recursive_func(t_lst *content, t_flags flags);

/*
**			PRINT
*/

void					print_test(t_lst *list);		// PROVISOIRE

void					my_printf(t_lst *list, t_flags flags);
void					print_l_flag(t_lst *list, t_flags flags);

void					print_type(char *path);

void					print_rights(char *path);
void					print_usr_rights(struct stat sb);
void					print_grp_rights(struct stat sb);
void					print_oth_rights(struct stat sb);

/*
**			ERRORS
*/

void					error(int a, char *str);

/*
**			OTHER
*/

char					*get_name(char *path);
long					get_highest_deps(t_lst *list, long dep);

/*
**			
*/


#endif
