/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:34:16 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/18 18:36:18 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		recursive_func(char **farg, int index, int a)
{
	while (farg[index])		// First while => write folder content
	{
		ft_putstr(farg[index]);
		ft_putchar('\n');
		index++;
	}
	if (!farg[index])
		index = 0;
	while (farg[index])		// Second while => goes into the folders recursively
	{
		ft_putstr(farg[index]);
		index++;
	}
	if (!farg[index])
		a = 1;
	if (a == 0)
		recursive_func(farg, index, a);
	return (0);
}

int		simply_dir(char **farg, t_flags flags)
{
	int		i;

	i = 0;
	while (farg[i])
	{
		my_printf((open_directory(farg[i], flags)), flags);
		i++;
	}
	return (0);
}

char	**open_directory(char *path, t_flags flags)	// GETS ALL THE CONTENT OF A DIR INTO A **CHAR
{
	t_fold			fold;

	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) == NULL)
		error(1);
	while ((fold.readfile = readdir(fold.rep)) != NULL)
		fold.index++;
	if (!(fold.names = (char **)malloc(sizeof(char *) * (fold.index + 1))))
		error(0);
	if (closedir(fold.rep) == -1)
		error(2);
	init_fold_struct(&fold);
	if ((fold.rep = opendir(path)) == NULL)
		error(1);
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		if (!(fold.names[fold.index] = (char *)malloc(sizeof(char *) * \
						(ft_strlen(fold.readfile->d_name) + 1))))
			error(0);
		fold.names[fold.index] = ft_strcpy(fold.names[fold.index], \
				fold.readfile->d_name);
		fold.names[fold.index][ft_strlen(fold.readfile->d_name)] = '\0';
		fold.index++;
	}
	fold.names[fold.index] = NULL;
	fold.index = 0;

	return (fold.names);
}
