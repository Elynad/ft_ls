/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:36:58 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/21 12:11:32 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		print_type(char *path)
{
	struct stat		sb;

	if (stat(path, &sb) == -1 && lstat(path, &sb) == -1)
		perror(get_name(path));
	else
	{
		if (S_ISDIR(sb.st_mode))
			ft_putchar('d');
		else if (S_ISCHR(sb.st_mode))
			ft_putchar('c');
		else if (S_ISBLK(sb.st_mode))
			ft_putchar('b');
		else if (S_ISLNK(sb.st_mode))
			ft_putchar('l');
		else if (S_ISFIFO(sb.st_mode))
			ft_putchar('p');
		else if (S_ISSOCK(sb.st_mode))
			ft_putchar('s');
		else
			ft_putchar('-');
	}
}

void		print_rights(char *path)
{
	struct stat		sb;

	if (stat(path, &sb) == -1 && lstat(path, &sb) == -1)
		perror(path);
	else
	{
		print_usr_rights(sb);
		print_grp_rights(sb);
		print_oth_rights(sb);
	}
}

void		print_usr_rights(struct stat sb)
{
	char	str[4];

	str[0] = (S_IRUSR & sb.st_mode) ? 'r' : '-';
	str[1] = (S_IWUSR & sb.st_mode) ? 'w' : '-';
	str[2] = (S_IXUSR & sb.st_mode) ? 'x' : '-';
	str[3] = '\0';
	ft_putstr(str);
}

void		print_grp_rights(struct stat sb)
{
	char	str[4];

	str[0] = (S_IRGRP & sb.st_mode) ? 'r' : '-';
	str[1] = (S_IWGRP & sb.st_mode) ? 'w' : '-';
	str[2] = (S_IXGRP & sb.st_mode) ? 'x' : '-';
	str[3] = '\0';
	ft_putstr(str);
}

void		print_oth_rights(struct stat sb)
{
	char	str[4];

	str[0] = (S_IROTH & sb.st_mode) ? 'r' : '-';
	str[1] = (S_IWOTH & sb.st_mode) ? 'w' : '-';
	str[2] = (S_IXOTH & sb.st_mode) ? 'x' : '-';
	str[3] = '\0';
	ft_putstr(str);
}
