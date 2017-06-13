/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:59:17 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/28 19:19:54 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		core_func(char *path, t_flags flags)
{
	struct stat		sb;
	t_lst			*content;

	if (stat(path, &sb) == -1 || stat(path, &sb) == -1)
		error(2, path);
	else if (S_ISDIR(sb.st_mode))
	{
		content = open_dir(path, flags);
		ft_putstr("Opening ");
		ft_putstr(path);
		ft_putchar('\n');
		print_test(content);
	}
	else
	{
		
	}
}

t_lst		*open_dir(char *path, t_flags flags)
{
	t_fold			fold;
	t_lst			*content;
	int				i;

	i = 0;
	fold.rep = NULL;
	fold.readfile = NULL;
	if (!(content = malloc(sizeof(t_lst))))
		error(1, "core.c");
	content->name = NULL;
	content->next = NULL;
	if ((fold.rep = opendir(path)) == NULL)
		error(3, "core.c");
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		if ((fold.readfile->d_name[0] != '.' && flags.a == 0) || flags.a == 1)
		{
			if (i == 0)
				first_elem(content, fold.readfile->d_name, path, &i);
			else
				new_elem(content, fold.readfile->d_name, path);
		}
	}
	if (closedir(fold.rep) == -1)
		error(4, "core.c");
	return (content);
}
