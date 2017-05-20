/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:33:00 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/20 16:56:11 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

t_lst		*parsing(char **str, t_flags *flags, t_lst *fargs)
{
	int		i;

	i = 1;
	if (!(fargs = malloc(sizeof(t_lst))))
		error_1(2, "parsing.c - line 20");
	fargs->next = NULL;
	while (str[i] && str[i][0] == '-' && str[i][1])
	{
		get_flags(flags, str[i]);
		i++;
	}
	while (str[i] && str[i][0] == '-' && !str[i][1])
	{
		error_1(0, str[i]);
		i++;
	}
	if (str[i])
		fargs = get_f(str, i, fargs);
	else
	{
		fargs->name = ft_strdup("./");
		fargs->next = NULL;
	}
	return (fargs);
}

t_lst		*get_f(char **str, int i, t_lst *fargs)
{
	int		j;

	j = 0;
	if (!(fargs->name = (char *)malloc(sizeof(char) * (ft_strlen(str[i]) + 2))))
		error_1(2, "line 45");
	while (fargs->name[i])
	{
		fargs->name[i] = '\0';
		i++;
	}
	fargs->name = ft_strcpy(fargs->name, "./");
	fargs->name = ft_strcat(fargs->name, str[i]);
	fargs->next = NULL;
	if (str[i + 1])
	{
		if (!(fargs->next = malloc(sizeof(t_lst))))
			error_1(2, "parsing.c - line 41");
		fargs->next->name = NULL;
		fargs->next->next = NULL;
		get_f(str, i + 1, fargs->next);
	}
	return (fargs);
}

void		get_flags(t_flags *flags, char *str)
{
	int		i;

	i = 1;
	while (str[i] && ft_is_space(str[i]) == 0)
	{
		if (str[i] == 'l')
			flags->f_l = 1;
		else if (str[i] == 'R')
			flags->f_R = 1;
		else if (str[i] == 'a')
			flags->f_a = 1;
		else if (str[i] == 'r')
			flags->f_r = 1;
		else if (str[i] == 't')
			flags->f_t = 1;
		else
			error_1(1, &str[i]);
		i++;
	}
}
