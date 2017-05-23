/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:44:55 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/23 16:41:27 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>

typedef struct		s_flags
{
	signed char		l;
	signed char		f_R;
	signed char		a;
	signed char		r;
	signed char		t;
}					t_flags;

typedef struct		s_lst
{
	char			*name;
	char			*path;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_fold
{
	DIR				*rep;
	struct dirent	*readfile;
}					t_fold;

/*
**		PARSING
*/

t_lst				*parsing(char **str, t_flags *flags);
void				get_flags(t_flags *flags, char *str);
t_lst				*get_fargs(char **str, int index, t_lst *fargs);

/*
**		CORE
*/

void				rec_main(t_lst *content, t_flags flags);
void				core_func(char *path, t_flags flags);
t_lst				*open_dir(char *path, t_flags flags);

/*
**		LINKED LISTS
*/

void				first_elem(t_lst *content, char *name, char *path, int *i);
void				new_elem(t_lst *content, char *name, char *path);

/*
**		ERROR
*/

void				error(int a, char *str);

/*
**		TEST			=> TO DELETE
*/

void				print_test(t_lst *fargs);

#endif
