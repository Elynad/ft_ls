#include "../inc/ft_ls.h"

void		first_elem(t_lst *list, char *name, char *path)
{
	struct stat		sb;

	list->name = ft_strdup(name);
	list->path = set_path(path, name);
	if (stat(list->path, &sb) == -1)
	{
		if (lstat(list->path, &sb) == -1)
			error(3, "linked_lists - line 9");
	}
	list->time = (long)&sb.st_mtime;
	list->next = NULL;
}

void		new_elem(t_lst *list, char *name, char *path)
{
	struct stat		sb;

//	ft_putchar('\n');
//	ft_putstr("name : ");				// TEST
//	ft_putstr(name);
//	ft_putchar('\t');
//	ft_putstr("path : ");
//	ft_putstr(path);
//	ft_putchar('\t');
//	ft_putstr("Final path : ");
//	ft_putstr(set_path(path, name));
//	ft_putchar('\n');					// END TEST
	if (name && path)
	{
		if (list->next != NULL)
			new_elem(list->next, name, path);
		else
		{
			if (!(list->next = malloc(sizeof(t_lst))))
				error(2, "");
			list->next->name = ft_strdup(name);
			list->next->path = set_path(path, name);
			if (stat(list->next->path, &sb) == -1)
			{
				if (lstat(list->next->path, &sb) == -1)
					error(3, "linked_lists - line 27");
			}
			list->next->time = (long)&sb.st_mtime;
			list->next->next = NULL;
		}
	}
}

char		*set_path(char *path, char *name)
{
	size_t		size;
	char		*str;
	int			i;

	i = 0;
	size = ft_strlen(path) + ft_strlen(name) + 2;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		error(2, "");
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	str = ft_strcpy(str, path);
	if (path[ft_strlen(path) - 1] != '/')
		str[ft_strlen(path)] = '/';
	str = ft_strcat(str, name);
	str[ft_strlen(str)] = '\0';
	return (str);
}
