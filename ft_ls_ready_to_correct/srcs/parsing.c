/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:08:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/11 17:27:47 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_lst			*parsing(char **argv, t_flags *flags)
{
	t_lst		*fargs;
	int			i;

	if (!(fargs = malloc(sizeof(t_lst))))
		perror("malloc fargs");
	fargs->next = NULL;
	i = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1])
	{
		get_flags(argv[i], flags);
		i++;
	}
	if (!argv[i])
	{
		fargs->name = ft_strdup("./");
		fargs->next = NULL;
	}
	else
		sub_parsing(&fargs, argv, i);
	return (fargs);
}

void			sub_parsing(t_lst **fargs, char **str, int index)
{
	first_elem(str[index], *fargs);
	index++;
	while (str[index])
	{
		add_elem(str[index], *fargs);
		index++;
	}
}

void			first_elem(char *name, t_lst *list)
{
	list->next = NULL;
	list->name = ft_strdup(name);
}

void			add_elem(char *name, t_lst *list)
{
	if (list->next)
		add_elem(name, list->next);
	else
	{
		if (!(list->next = malloc(sizeof(t_lst))))
			perror(name);
		list->next->name = ft_strdup(name);
		list->next->next = NULL;
	}
}

void			get_flags(char *str, t_flags *flags)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'A')
		{
			flags->f_amaj = 1;
			flags->f_a = 1;
		}
		else if (str[i] == 'a')
		{
			flags->f_a = 1;
			flags->f_amaj = 0;
		}
		else if (str[i] == 'l' || str[i] == 'r' || str[i] == 'R'
				|| str[i] == 't' || str[i] == 'f' || str[i] == 'F'
				|| str[i] == 'g' || str[i] == 'p')
			sub_get_flags(str[i], flags);
		else if (str[i] == '-')
			break ;
		else
			usage(str[i]);
		i++;
	}
}
