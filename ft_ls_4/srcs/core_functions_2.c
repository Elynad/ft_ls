/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:17:48 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/24 18:05:35 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*set_newpath(char *oldpath, char *newpath)
{
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * \
					(ft_strlen(oldpath) + ft_strlen(newpath) + 3))))
		error(2, "");
	str = ft_strcpy(str, oldpath);
	str = ft_strcat(str, "/");
	str = ft_strcat(str, newpath);
	return (str);
}
