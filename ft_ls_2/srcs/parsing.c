/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:17:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/04 18:39:08 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	parsing(t_flags *flags, char **arguments)
{
	char	*str;

	fusion(arguments, &str);
	if (ft_strchr(str, 'l') != NULL)
		flags->f_l = 1;
	if (ft_strchr(str, 'R') != NULL)
		flags->f_R = 1;
	if (ft_strchr(str, 'a') != NULL)
		flags->f_a = 1;
	if (ft_strchr(str, 'r') != NULL)
		flags->f_r = 1;
	if (ft_strchr(str, 't') != NULL)
		flags->f_t = 1;
}
