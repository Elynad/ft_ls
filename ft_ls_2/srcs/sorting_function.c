/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:49:05 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/06 10:55:00 by mameyer          ###   ########.fr       */
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
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i + 1])
	{
		if (ft_strcmp(str[i], str[i + 1]) < 0)
			j++;
		i++;
	}
	if (j == i)
		return (1);
	else
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
