/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:23:28 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 15:10:02 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	**sorting_fargs(char **fargs)
{
	int		i;
	int		*tab;

	i = 0;
	while (fargs[i])
		i++;
	if (!(tab = (int *)malloc(sizeof(int) * i)))
		error(2, "");
	i = 0;
	while (fargs[i])
	{
		tab[i] = i;
		i++;
	}
	ft_putchar('a');
	return (sort_2(fargs, tab));
}

char	**sort_2(char **fargs, int *tab)
{
	int		i;
	char	**sorted;

	i = 0;
	if (!(sorted = (char **)malloc(sizeof(char *) * 2)))
		error(2, "");
	while (check_sorted(fargs, tab) == 0)
	{
		ft_putchar('a');
		clear_double_string(&sorted);
		while (fargs[i] && fargs[i + 1])
		{
			ft_putstr(fargs[i]);
			if (ft_strcmp(fargs[i], fargs[i + 1]) > 0)
				swap(&tab[i], &tab[i + 1]);
			i++;
		}
		sorted = sort_3(fargs, tab);
	}
	return (sorted);
}

char	**sort_3(char **fargs, int *tab)
{
	char	**str;
	int		i;

	i = 0;
	while (fargs[i])
		i++;
	if (!(str = (char **)malloc(sizeof(char *) * (i + 1))))
		error(2, "");
	i = 0;
	while (str[i])
	{
		str[i] = ft_strdup(fargs[tab[i]]);
		i++;
	}
	return (str);
}

void	swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

int		check_sorted(char **str, int *tab)
{
	int		i;

	i = 0;
	while (str[tab[i]] && str[tab[i + 1]])
	{
		ft_putchar('e');
		if (ft_strcmp(str[i], str[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void	clear_double_string(char ***str)
{
	int		i;

	i = 0;
	while (*str[i])
	{
		free(*str[i]);
		i++;
	}
}
