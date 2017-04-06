/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:17:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/06 13:41:33 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	**parsing(t_flags *flags, char **arguments)
{
	int		i;
	char	**str;

	i = 1;
	while (arguments[i] && arguments[i][0] == '-')
	{
		check_flags(flags, arguments[i]);
		i++;
	}
	return (get_files_param(arguments, i));
}

void	check_flags(t_flags *flags, char *str)
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
			break ;
		i++;
	}
	if (i != ft_strlen(str))
		flag_error(str[i]);
}

void	flag_error(char flag)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putstr("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1]");
	ft_putstr(" [file ...]\n");
	error(4);
}

char	**get_files_param(char **arguments, int index)
{
	char	**str;
	int		i;

	i = index;
	while (arguments[i])
		i++;
	if (!(str = (char **)malloc(sizeof(char *) * (i - index + 1))))
		error(1);
	i = 0;
	while (arguments[index])
	{
		if (!(str[i] = (char *)malloc(sizeof(char) *
						(ft_strlen(arguments[index]) + 1))))
			error(1);
		str[i] = ft_strcpy(str[i], arguments[index]);
		index++;
		i++;
	}
	str[i] = NULL;
	return (str);
}
