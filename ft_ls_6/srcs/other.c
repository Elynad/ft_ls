/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:50:26 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/20 17:54:36 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

// If the folder is empty => return 0 | else => return 1

int			check_if_empty(char *path, t_flags flags)
{
	t_fold		fold;
	int			tmp;

	tmp = 0;
	if (flags.f_a == 1)
		return (1);
	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) == NULL)
		error_1(4, "other.c - line 26");
	while ((fold.readfile = readdir(fold.rep)) != NULL)
		tmp++;
	if (closedir(fold.rep) == -1)
		error_1(5, "other.c - line 30");
	if (tmp == 2)
		return (0);
	else
		return (1);
}
