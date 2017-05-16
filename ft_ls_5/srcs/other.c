/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 16:53:41 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/16 16:58:11 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

// If the folder is empty : return 0
// Else : return 1

int			check_if_empty(char *path, t_flags flags)
{
	t_fold		fold;
	int			tmp;

	tmp = 0;
	if (flags.f_a == 1)
		return (0);
	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) == NULL)
		error(4, "other.c - line 22");
	while ((fold.readfile = readdir(fold.rep)) != NULL)
		tmp++;
	if (closedir(fold.rep) == -1)
		error(5, "");
	if (tmp == 2)
		return (0);
	else
		return (1);
}
