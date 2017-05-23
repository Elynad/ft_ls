/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:04:30 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/23 15:59:11 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_lst			*parsing(char **str, t_flags *flags)
{
	int		i;
	t_lst	*fargs;

	i = 1;
	if (!(fargs = malloc(sizeof(t_lst))))
		error(1, "parsing.c");
	fargs->next = NULL;
	while (str[i] && str[i][0] == '-' && str[i][1])
	{
		get_flags(flags, str[i]);
		i++;
	}
	if (str[i] && str[i][0] == '-' && !str[i][1])
		error(2, str[i]);
	if (str[i])
		fargs = get_fargs(str, i, fargs);
	else
	{
		fargs->name = ft_strdup("./");
		fargs->path = ft_strdup("./");
	}
	return (fargs);
}

t_lst			*get_fargs(char **str, int index, t_lst *fargs)
{
	int		j;

	j = 0;
	fargs->name = ft_strdup(str[index]);
	if (!(fargs->path = (char *)malloc(sizeof(char) *
					(ft_strlen(fargs->name) + 3))))
		error(1, "parsing.c");
	while (fargs->path[j])
	{
		fargs->path[j] = '\0';
		j++;
	}
	fargs->path[0] = '.';
	fargs->path[1] = '/';
	fargs->path = ft_strcat(fargs->path, fargs->name);
	if (str[index + 1])
	{
		if (!(fargs->next = malloc(sizeof(t_lst))))
			error(1, "parsing.c");
		get_fargs(str, index + 1, fargs->next);
	}
	else
		fargs->next = NULL;
	return (fargs);
}

void			get_flags(t_flags *flags, char *str)
{
	int		i;

	i = 1;
	while (str[i] && ft_is_space(str[i]) == 0)
	{
		if (str[i] == 'l')
			flags->l = 1;
		else if (str[i] == 'R')
			flags->f_R = 1;
		else if (str[i] == 'a')
			flags->a = 1;
		else if (str[i] == 'r')
			flags->r = 1;
		else if (str[i] == 't')
			flags->t = 1;
		else
			error(0, &str[i]);
		i++;
	}
}
