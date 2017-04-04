/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:24:38 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/04 18:45:46 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		fusion(char **double_char, char **str)
{
	int		i;
	int		j;
	size_t	size;

	i = 0;
	size = 0;
	while (double_char[i])
	{
		j = 0;
		while (double_char[i][j])
		{
			j++;
			size++;
		}
		i++;
	}
	if (!(*str = (char *)malloc(sizeof(char) * (size + 1))))
		exit(-1);
	j = 1;
	if (double_char[j])
		ft_strcpy(*str, double_char[j]);
	while (double_char[++j])
		ft_strcat(*str, double_char[j]);
	*str[i] = '\0';
}

void		init_flags_struct(t_flags *flags)
{
	flags->f_l = 0;
	flags->f_R = 0;
	flags->f_a = 0;
	flags->f_r = 0;
	flags->f_t = 0;
}

void		init_folders_struct(t_folders *folders)
{
	folders->rep = NULL;
	folders->readfile = NULL;
	folders->index = 0;
	folders->next = NULL;
}

void		error(int a)
{
	if (a == 0)
		ft_putstr("The opening failed.\n");
	exit(-1);
}
