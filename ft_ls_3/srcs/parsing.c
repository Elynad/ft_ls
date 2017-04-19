/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:34:49 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/19 12:24:38 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		**parsing(char **arguments, t_flags *flags)
{
	int		i;

	i = 1;
	while (arguments[i] && arguments[i][0] == '-')
	{
		check_flags(flags, arguments[i]);
		i++;
	}
	return (get_fargs(arguments, i));
}

void		check_flags(t_flags *flags, char *str)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
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
			break;
		i++;
	}
	if (i != ft_strlen(str))
		ft_putchar('z');
}

char		**get_fargs(char **arguments, int index)
{
	char		**str;
	int			i;

	i = index;
	if (!arguments[index])
		return (no_args());
	while (arguments[i])
		i++;
	if (!(str = (char **)malloc(sizeof(char *) * (i - index + 1))))
		error(0);
	i = 0;
	while (arguments[index])
	{
		if (!(str[i] = (char *)malloc(sizeof(char) *
						(ft_strlen(arguments[index]) + 1))))
			error(0);
		str[i] = ft_strcpy(str[i], arguments[index]);
		str[i][ft_strlen(str[i])] = '\0';
		index++;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char		**no_args(void)
{
	char	**str;

	if (!(str = (char **)malloc(sizeof(char *) * 2)))
		error(0);
	str[0] = "./";
	str[1] = NULL;
	return (str);
}
