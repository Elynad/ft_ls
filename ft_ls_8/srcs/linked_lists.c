/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 13:51:05 by mameyer           #+#    #+#             */
/*   Updated: 2017/06/20 15:30:28 by mameyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void		first(t_lst *content, char *name, char *path, int *tmp)
{
	content->name = ft_strdup(name);
	if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0
			&& ft_strcmp(name, "./") != 0 && ft_strcmp(name, "../") != 0)
		content->path = set_path(name, path);
	else
		content->path = ft_strdup(name);
	if (stat(content->path, &(content->sb)) == -1
			&& lstat(content->path, &(content->sb)) == -1)
		perror(get_name(content->path));
	*tmp = 1;
}

void		next(t_lst *content, char *name, char *path)
{
	t_lst		*new;
	t_lst		*tmp;

	new = NULL;
	if (ft_strcmp(content->name, name) > 0)
	{
		// Si content->name est apres name
		// tmp devient content; content devient new, tmp va apres new et
		// pointe vers content->next
		ft_putstr("Cas 1 : content->name = ");
		ft_putstr(content->name);
		ft_putstr("\tname = ");
		ft_putstr(name);
		ft_putchar('\n');

		if (!(tmp = malloc(sizeof(t_lst))))
			perror("");
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		tmp->name = ft_strdup(content->name);
		tmp->path = ft_strdup(content->path);
		tmp->next = content->next;
		free(content->name);
		content->name = ft_strdup(name);
		free(content->path);
		content->path = set_path(name, path);
		content->next = tmp;
	}
	else if (ft_strcmp(content->name, name) < 0 && content->next
			&& ft_strcmp(content->next->name, name) > 0)
	{
		// Si name est entre content->name et content->next->name
		ft_putstr("Cas 2 : content->name = ");
		ft_putstr(content->name);
		ft_putstr("\tname = ");
		ft_putstr(name);
		ft_putstr("\tcontent->next->name = ");
		ft_putstr(content->next->name);
		ft_putchar('\n');
		if (!(new = malloc(sizeof(t_lst))))
			perror("");
		new->next = content->next;
		content->next = new;
		new->name = ft_strdup(name);
		new->path = set_path(name, path);
	}
	else if (!content->next)
	{
		// Si il n'y a plus d'elements suivants, new devient le dernier element
		ft_putstr("Cas 3 : content->name = ");
		ft_putstr(content->name);
		ft_putstr("\tname = ");
		ft_putstr(name);
		ft_putchar('\n');
		if (!(content->next = malloc(sizeof(t_lst))))
			perror("");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		content->next->path = set_path(name, path);
	}
	else
		next(content->next, name, path);
}

/*
void		next(t_lst *content, char *name, char *path, t_flags flags)
{
	t_lst		*new;
	t_lst		*tmp;

	tmp = NULL;
	new = NULL;
	if (content->next && ft_strcmp(content->name, name) < 0
			&& ft_strcmp(content->next->name, name) > 0)
	{
		// Si content->name est avant name et content->next->name apres name
		// Insertion de new entre les deux
		if (!(new = malloc(sizeof(t_lst))))
			error(0, "");
		tmp = content->next;
		content->next = new;
		new->next = tmp;
		new->name = ft_strdup(name);
		if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0
				&& ft_strcmp(name, "./") != 0 && ft_strcmp(name, "../") != 0)
			new->path = set_path(name, path);
		else
			new->path = ft_strdup(name);
	}
	else if (content->next)
	{
		// Sinon si il y a un element ensuite, on recommence la fonction a
		// partir de l'element suivant
		next(content->next, name, path, flags);
	}
	else
	{
		// Si il n'y a plus d'elements, on en cree un
		if (!(content->next = malloc(sizeof(t_lst))))
			error(0, "linked_lists.c, next func");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0
				&& ft_strcmp(name, "./") != 0 && ft_strcmp(name, "../") != 0)
			content->next->path = set_path(name, path);
		else
			content->next->path = ft_strdup(name);
	}
}
*/

/*
void		next(t_lst *content, char *name, char *path)
{
	if (content->next)
		next(content->next, name, path);
	else
	{
		if (!(content->next = malloc(sizeof(t_lst))))
			error(0, "linked_lists.c, next func");
		content->next->next = NULL;
		content->next->name = ft_strdup(name);
		if (ft_strcmp(name, ".") != 0 && ft_strcmp(name, "..") != 0
				&& ft_strcmp(name, "./") != 0 && ft_strcmp(name, "../") != 0)
			content->next->path = set_path(name, path);
		else
			content->next->path = ft_strdup(name);
		if (stat(content->path, &(content->sb)) == -1
				&& lstat(content->path, &(content->sb)) == -1)
			perror(get_name(content->path));
	}
}
*/

char		*set_path(char *name, char *path)
{
	char	*newpath;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(newpath = (char *)malloc(sizeof(char) * (ft_strlen(name)
						+ ft_strlen(path) + 2))))
		error(0, "linked_lists.c, set_path func");
	while (path[i])
	{
		newpath[i] = path[i];
		i++;
	}
	if (newpath[i - 1] != '/')
	{
		newpath[i] = '/';
		i++;
	}
	while (name[j])
	{
		newpath[i + j] = name[j];
		j++;
	}
	while (newpath[i + j])
	{
		newpath[i + j] = '\0';
		j++;
	}
	return (newpath);
}
