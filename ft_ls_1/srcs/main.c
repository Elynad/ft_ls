/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 15:35:17 by mameyer           #+#    #+#             */
/*   Updated: 2017/04/05 15:35:19 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	DIR					*rep;
	struct	dirent		*readfile;
	unsigned int		nbr_files;
	char				**files_name;
	int					i;

	// files_name = parsing();

	rep = opendir("./");
	readfile = NULL;
	i = 0;

	if (rep == NULL)
		open_close_error(0);
	else
		printf("Opening - SUCCESS\n");
	while ((readfile = readdir(rep)) != NULL)
		nbr_files++;
	files_name = (char **)malloc(sizeof(char *) * nbr_files);
	if (files_name == NULL)
		return (-1);

	if (closedir(rep) == -1)
		open_close_error(1);
	else
		printf("Closing - SUCCESS\n");
	files_name = get_files_name(files_name);

	write(1, "\n", 1);
	return (0);
}
/*
void	print_func(char c, char *str)
{
	if (c == 0 && str != "." && str != "..")
		printf("%s\n", str);
}
*/
char	**get_files_name(char **str)
{
	DIR					*rep;
	struct dirent		*readfile;
	int					i;

	rep = NULL;
	rep = opendir("./");
	i = 0;
	readfile = NULL;
	while ((readfile = readdir(rep)) != NULL)
	{
		str[i] = (char *)malloc(sizeof(char) * (strlen(readfile->d_name) + 1 ));
		i++;
	}
	i = 0;
	readfile = NULL;
	if (closedir(rep) == -1)
		open_close_error(1);
	rep = NULL;
	rep = opendir("./");
	if (rep == NULL)
		open_close_error(0);
	while ((readfile = readdir(rep)) != NULL)
	{
		str[i] = strcpy(str[i], readfile->d_name);
		str[i][strlen(readfile->d_name)] = '\0';
		i++;
	}
	str[i] = NULL;
	// TEST
	i = 0;
	while (str[i])
	{
		printf("\n%s", str[i]);
		i++;
	}
	return (str);
}
