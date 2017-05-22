/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:13:45 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/22 17:38:00 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

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
}						t_fold;

typedef struct			s_lst
{
	char				*name;
	char				*path;
	struct s_lst		*next;
}						t_lst;

/*
**		INIT
*/

void					init_flags_struct(t_flags *flags);
void					init_fargs_struct(t_lst *fargs);
void					init_fold_struct(t_fold *fold);

/*
**		PARSING
*/

t_lst					*parsing(char **str, t_flags *flags, t_lst *fargs, int *i);
t_lst					*get_f(char **str, int i, t_lst *fargs);
void					get_flags(t_flags *flags, char *str);

/*
**		ERRORS
*/

void					error_1(int a, char *str);
void					error_2(int a, char *str);

/*
**		FREE
*/

/*
**		CORE
*/

void					submain(t_lst *fargs, t_flags flags, int type);
void					core_func(char *path, t_flags flags, int type);
t_lst					*open_directory(char *path, t_flags flags, int type);
void					recursive_func(t_lst *content, t_flags flags);

/*
**		LINKED LISTS
*/

void					first_elem(t_lst *list, char *name, char *path, int *i);
void					new_elem(t_lst *list, char *name, char *path);
char					*set_path(char *path, char *name);

/*
**		PRINT
*/

void					my_printf(t_lst *list, t_flags flags);
void					print(t_lst *list, t_flags flags);
void					print_l(t_lst *list, t_flags flags);
void					print_l2(char *name, char *path, struct stat sb);

void					print_type(struct stat sb);
void					print_rights(struct stat sb);
void					print_usr_rights(struct stat sb);
void					print_grp_rights(struct stat sb);
void					print_oth_rights(struct stat sb);
void					print_dependencies(char *path, struct stat sb);
void					print_author(struct stat sb);
void					print_group(struct stat sb);
void					print_time(struct stat sb);

/*
**		OTHER
*/

int						check_if_empty(char *path, t_flags flags);
int						check_two_first_rep(char *path);

/*
**		TEST - NEED TO BE DEL
*/

void					print_test(t_lst *fargs);
void					print_flags_test(t_flags flags);

#endif
