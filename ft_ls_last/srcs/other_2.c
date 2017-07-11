/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 12:07:06 by mameyer           #+#    #+#             */
/*   Updated: 2017/07/08 19:46:56 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char		*get_name(char *path)
{
	char		*str;
	int			i;
	int			k;

	k = 0;
	i = ft_strlen(path);
	while (i > 0 && path[i] != '/')
		i--;
	i++;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(path) - i))))
		perror(path);
	while (path[i + k])
	{
		str[k] = path[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

void		get_today_date(int *today_date)
{
	struct stat		sb;

	if (stat(EXEC_NAME, &sb) == -1 && lstat(EXEC_NAME, &sb) == -1)
		perror(EXEC_NAME);
	*today_date = sb.st_mtime;
}

void		free_lst(t_lst *content)
{
	t_lst		*tmp;

	tmp = NULL;
	if (content->next)
		tmp = content->next;
	if (content->name)
		free(content->name);
	free(content);
	if (tmp)
		free_lst(tmp);
}

void		error(char *str)
{
	perror(str);
	exit(-1);
}

void		usage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-lraRt] [file ...]\n");
	exit(-1);
}
