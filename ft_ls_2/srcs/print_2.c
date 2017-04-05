/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:10:34 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/05 19:43:28 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_dependencies(char *str, struct stat sb)
{
	int					dep;
	DIR					*rep;
	struct dirent		*readfile;

	rep = NULL;
	readfile = NULL;
	dep = 0;
	if (S_ISDIR(sb.st_mode))
	{
		if ((rep = opendir(str)) == NULL)
			error(0);
		while ((readfile = readdir(rep)) != NULL)
			dep++;
	}
	else if (S_ISREG(sb.st_mode))
		dep = 1;
	ft_putnbr(dep);
	ft_putchar('\t');
}

void		print_author(char *str, struct stat sb)
{
	struct passwd		*info;

	info = getpwuid(sb.st_uid);
	ft_putstr(info->pw_name);
	ft_putchar('\t');
}

void		print_group(char *str, struct stat sb)
{
	struct group		*info;

	info = getgrgid(sb.st_gid);
	ft_putstr(info->gr_name);
	ft_putchar('\t');
}

void		print_time(char *str, struct stat sb)
{
	char		*s1;
	int			i;

	i = 3;
	if (!(s1 = (char *)malloc(sizeof(char) * (ft_strlen(ctime(&sb.st_mtime))))))
		exit(1);
	s1 = ft_strcpy(s1, (ctime(&sb.st_mtime)));
	while (i <= 15)
	{
		ft_putchar(s1[i]);
		i++;
	}
	ft_putchar('\t');
	free(s1);
}

void		print_type(char *str, struct stat sb)
{
	if (S_ISDIR(sb.st_mode))
		ft_putchar('d');
	else
		ft_putchar('-');
}
