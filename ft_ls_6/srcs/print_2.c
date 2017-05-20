/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 18:08:38 by mameyer           #+#    #+#             */
/*   Updated: 2017/05/20 18:34:03 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_type(struct stat sb)
{
	if (S_ISDIR(sb.st_mode))
		ft_putchar('d');
	else
		ft_putchar('-');
}

void		print_dependencies(char *path, struct stat sb)
{
	int		dependencies;
	t_fold	fold;

	init_fold_struct(&fold);
	dependencies = 0;
	if (S_ISDIR(sb.st_mode))
	{
		if ((fold.rep = opendir(path)) == NULL)
			error_1(4, "print_2.c - line 32");
		while ((fold.readfile = readdir(fold.rep)) != NULL)
			dependencies++;
		if (closedir(fold.rep) == -1)
			error_1(5, "print_2.c - line 36");
	}
	else if (S_ISREG(sb.st_mode))
		dependencies = 1;
	ft_putnbr(dependencies);
	ft_putchar('\t');
}

void		print_author(struct stat sb)
{
	struct passwd		*info;

	info = getpwuid(sb.st_uid);
	ft_putstr(info->pw_name);
	ft_putchar('\t');
}

void		print_group(struct stat sb)
{
	struct group		*info;

	info = getgrgid(sb.st_gid);
	ft_putstr(info->gr_name);
	ft_putchar('\t');
}

void		print_time(struct stat sb)
{
	char		*s1;
	int			i;

	i = 3;
	if (!(s1 = (char *)malloc(sizeof(char) * (ft_strlen(ctime(&sb.st_mtime))))))
		error_1(2, "print_2.c - line 69");
	s1 = ft_strcpy(s1, (ctime(&sb.st_mtime)));
	while (i <= 15)
	{
		ft_putchar(s1[i]);
		i++;
	}
	ft_putchar('\t');
	free(s1);
}
