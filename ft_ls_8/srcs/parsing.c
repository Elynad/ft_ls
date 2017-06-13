/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:08:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/13 17:18:48 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_lst			*parsing(char **argv, t_flags *flags)
{
	t_lst		*fargs;
	int			i;

	if (!(fargs = malloc(sizeof(t_lst))))
		error(0, "parsing.c, parsing func");
	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		get_flags(argv[i], flags);
		i++;
	}
	if (!argv[i])
	{
		fargs->name = ft_strdup("./");
		fargs->error = 0;
		fargs->next = NULL;
	}
	else
	{
		first_elem(argv[i], fargs);
		i++;
	}
	while (argv[i])
	{
		add_elem(argv[i], fargs);
		i++;
	}
	return (fargs);
}

void			first_elem(char *name, t_lst *list)
{
	list->error = 0;
	list->next = NULL;
	list->name = ft_strdup(name);
	if (stat(list->name, &(list->sb)) == -1)
	{
		if (lstat(list->name, &(list->sb)) == -1)
			list->error = 1;
	}
}

void			add_elem(char *name, t_lst *list)
{
	if (list->next)
		add_elem(name, list->next);
	else
	{
		if (!(list->next = malloc(sizeof(t_lst))))
			error(0, "parsing.c, add_elem func");
		list->next->error = 0;
		list->next->name = ft_strdup(name);
		list->next->next = NULL;
		if (stat(list->name, &(list->sb)) == -1)
		{
			if (lstat(list->name, &(list->sb)) == -1)
				list->next->error = 1;
		}
	}
}

void			get_flags(char *str, t_flags *flags)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			flags->f_l = 1;
		else if (str[i] == 'r')
			flags->f_r = 1;
		else if (str[i] == 'a')
			flags->f_a = 1;
		else if (str[i] == 'R')
			flags->f_R = 1;
		else if (str[i] == 't')
			flags->f_t = 1;
		else
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(str[i]);
			ft_putstr("\nusage: ft_ls [-lraRt] [file ...]\n");
		}
		i++;
	}
}
