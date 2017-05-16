#include "../inc/ft_ls.h"

void		core_func(char *path, t_flags flags)
{
	struct stat		sb;
	t_lst			*content;

	if (stat(path, &sb) == -1)
	{
		if (lstat(path, &sb) == -1)
			error(3, "core_func - line 9");
	}
	if (S_ISDIR(sb.st_mode))
	{
		content = open_directory(path, flags);
		if (flags.f_R == 1 && content->path)
			recursive_func(content, flags);
	}
	else if (S_ISREG(sb.st_mode))
	{
		ft_putstr(path);
		ft_putchar('\n');
	}
}

t_lst		*open_directory(char *path, t_flags flags)
{
	t_fold		fold;
	t_lst		*content;
	int			i;

	i = 0;
	init_fold_struct(&fold);
	if (!(content = malloc(sizeof(t_lst))))
		error(2, "");
	if ((fold.rep = opendir(path)) == NULL)
		error(4, "core_func - line 36");
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		if ((fold.readfile->d_name[0] != '.' && flags.f_a == 0)
				|| flags.f_a == 1)
			{
				if (i == 0)
				{
					first_elem(content, fold.readfile->d_name, path);
					i++;
				}
				else
				{
					new_elem(content, fold.readfile->d_name, path);
				}
			}
	}
	if (closedir(fold.rep) == -1)		// test
		error(5, "");
	if (i != 0)
	{
		my_printf(content, flags);
		ft_putchar('\n');
	}
	return (content);
}

// The following function is used only if the -R flag is activated.
// It will check each elem of the linked list and go through each
// folder to list what is inside it.

void		recursive_func(t_lst *content, t_flags flags)
{
	struct stat		sb;

	if (content->path)
	{
		ft_putstr("Path = ");
		ft_putstr(content->path);
		ft_putchar('\n');
		if (stat(content->path, &sb) == -1)
		{
			if (lstat(content->path, &sb) == -1)
				error(3, "core_func - line 64");
		}
		if (S_ISDIR(sb.st_mode) && check_if_empty(content->path, flags) == 0)
		{
			ft_putstr(content->path);
			ft_putstr(":\n");
			core_func(content->path, flags);
		}
		if (content->next)
			recursive_func(content->next, flags);
	}
}
