/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:49:05 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/05 23:02:07 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ft_swap_str(char **s1, char **s2)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * strlen(*s1))))
		exit(-1);
	tmp = strcpy(tmp, *s1);
	if (!(*s1 = (char *)malloc(sizeof(char) * strlen(*s2))))
		exit(-1);
	*s1 = strcpy(*s1, *s2);
	if (!(*s2 = (char *)malloc(sizeof(char) * strlen(tmp))))
		exit(-1);
	*s2 = strcpy(*s2, tmp);
}

int		ft_check_str(char **str)
{
	int		i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (ft_strcmp(str[i], str[i + 1]) > 0)
			return (1);
		i++;
	}
	return (0);
}

char	**alpha_sorting(char **str)
{
	int		i;

	while (ft_check_str(str) != 0)
	{
		i = 0;
		while (str[i] && str[i + 1])
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
				ft_swap_str(&str[i], &str[i + 1]);
			i++;
		}
	}
	return (str);
}

void		revalpha_sorting(char **str)
{
	int		i;

	while (ft_check_str(str) != 0)
	{
		i = 0;
		while (str[i] && str[i + 1])
		{
			if (ft_strcmp(str[i], str[i + 1]) < 0)
				ft_swap_str(&str[i], &str[i + 1]);
			i++;
		}
	}
	i = 0;
	while (str[i])
	{
		ft_putstr(str[i]);
		ft_putchar('\t');
		i++;
	}
	ft_putchar('\n');
}
