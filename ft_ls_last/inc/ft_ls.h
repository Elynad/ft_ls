/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 10:49:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/08 21:44:24 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define EXEC_NAME "ft_ls"
# define DIFFERENCE 15736732

typedef struct			s_lst
{
	char				*name;
	char				*path;
	struct stat			sb;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_flags
{
	int					f_l;
	int					f_a;
	int					f_rec;
	int					f_r;
	int					f_t;
	int					one;
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

typedef struct			s_print
{
	int					today_date;
	int					highest_dep;
	int					longer_author_name;
	int					longer_group_name;
	int					highest_size;
}						t_print;

/*
**			INIT
*/

void					init_flags_struct(t_flags *flags);
void					init_fold_struct(t_fold *fold);
void					init_print_struct(t_print *print);

/*
**			PARSING
*/

t_lst					*parsing(char **argv, t_flags *flags);
void					get_flags(char *str, t_flags *flags);
void					first_elem(char *name, t_lst *list);
void					add_elem(char *name, t_lst *list);
void					sub_parsing(t_lst **fargs, char **str, int index);

/*
**			CORE
*/

void					submain(t_lst *fargs, t_flags flags);
void					core(char *path, t_flags flags);
t_lst					*open_directory(char *path, t_flags flags);
void					first(t_lst *content, char *name, char *path, int *tmp);
void					next(t_lst *content, char *name, char *path);
void					next_reverse(t_lst *content, char *name, char *path);

char					*set_path(char *name, char *path);
void					recursive_func(t_lst *content, t_flags flags);

void					sub_open_dir(t_fold *fold, t_lst *list, t_flags flags,
						char *path);
void					sub_core_isdir(t_lst **lst, struct stat sb, char *path,
						t_flags flags);

void					sub_next_1(t_lst *elem, char *name, char *path);
void					sub_set_path(char **str, int index, char *s2);

/*
**			PRINT
*/

void					print_test(t_lst *list);

void					my_printf(t_lst *list, t_flags flags, int one);
void					print_l_flag(t_lst *list, t_flags flags, t_print print);
void					sub_print_l(t_print *infos, t_lst *list);

void					print_type(char *path);

void					print_rights(char *path);
void					print_usr_rights(struct stat sb);
void					print_grp_rights(struct stat sb);
void					print_oth_rights(struct stat sb);

int						get_total(t_lst *list);
void					get_total_2(t_lst *list, int *total);

void					print_dependencies(t_lst *list, t_print *infos);
void					print_author(struct stat sb, t_print *infos);
void					print_group(struct stat sb, t_print *infos);
void					print_size(struct stat sb, t_print *infos);
void					print_time(struct stat sb, t_print *infos);
void					sub_print_time(char *str);

/*
**			OTHER
*/

char					*get_name(char *path);
void					rec_high(t_lst *list, int *max);
void					rec_longer_author_name(t_lst *list, int *max);
void					rec_longer_group_name(t_lst *list, int *max);
void					rec_highest_size(t_lst *list, int *max);
void					get_today_date(int *today_date);
void					free_lst(t_lst *list);
void					free_lst2(t_lst *list);
void					error(char *path);
void					usage(char c);

/*
**			SORTING
*/

t_lst					*sort_reverse(t_lst *list);
t_lst					*get_elem(t_lst *list, int index, int i);
void					get_size(t_lst *list, int *size);

void					next_conditions(t_lst *list, char *name, char *path,
						t_flags flags);
void					ft_putsec(t_lst **content, t_lst *new_elem);
void					ft_addbetween(t_lst **content, t_lst *new_elem,
						t_lst *begin, t_lst *previous);
void					put_front(t_lst **content, t_lst *new_elem,
						t_lst *begin, t_lst *previous);
void					put_nsec(t_lst **content, t_lst *new_elem,
						t_lst *begin, t_lst *previous);
void					ascii(t_lst **content, t_lst *new_elem, t_lst *begin,
						t_lst *previous);
void					ft_timestamp(t_lst *new_elem);
void					ft_addhead(t_lst **content, t_lst *new_elem);

void					next_time_sort(t_lst *begin, t_lst *content, char *name,
						char *path);
void					next_nano_sort(t_lst *begin, t_lst *content, char *name,
						char *path);
void					next_ascii_sort(t_lst *begin, t_lst *content,
						char *name, char *path);
int						sub_time_sort_conditions(t_lst *content, char *name,
						char *path);
void					sub_time_sort_2(t_lst *content, char *name, char *path);
int						sub_nsrtconds(t_lst *content, struct stat sb);
void					sub_nano_sort_2(t_lst *list, char *name, char *path,
						struct stat sb);
void					sub_nano_sort_1(t_lst *content, char *name, char *path,
						struct stat *sb);
void					sub_nano_sort_mallocs(t_lst *new_elem, t_lst *tmp);
int						sub_asciisrtconds(t_lst *list, struct stat sb,
						char *name);
void					sub_ascii_sort_1(t_lst *list, char *name, char *path,
						struct stat sb);
void					next_reverse_time_sort(t_lst *begin, t_lst *content,
						char *name, char *path);
int						sub_reverse_time_sort_conditions(t_lst *content,
						char *name, char *path);
void					sub_reverse_time_sort_2(t_lst *content, char *name,
						char *path);
void					next_reverse_nano_sort(t_lst *begin, t_lst *content,
						char *name, char *path);
void					sub_reverse_nano_sort_1(t_lst *content, char *name,
						char *path, struct stat *sb);
int						sub_rnsrtcnds(t_lst *content, struct stat sb);
void					sub_reverse_nano_sort_mallocs(t_lst *new_elem,
						t_lst *tmp);
void					sub_reverse_nano_sort_2(t_lst *list, char *name,
						char *path, struct stat sb);
void					next_reverse_ascii_sort(t_lst *begin, t_lst *content,
						char *name, char *path);
int						sub_rev_ascii_conds(t_lst *list, struct stat sb,
						char *name);
void					sub_reverse_ascii_sort_1(t_lst *lst, char *name,
						char *path, struct stat sb);

#endif
