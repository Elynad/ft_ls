#include "../inc/ft_ls.h"

t_lst		core_func(char *path, int index, t_flags flags)
{
	struct stat		sb;
	t_lst			*content;

	if (stat(path, &sb) == -1)
		error(0, path);
	if (S_ISDIR(sb.st_mode))
	{
		content = open_directory(path, flags);
		if (flags.f_R == 1)
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
	ft_putchar('a');
	ft_putstr(path);
	if ((fold.rep = opendir(path)) == NULL)
		error(4, "");
	ft_putchar('b');
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		ft_putchar('c');
		if ((fold.readfile->d_name[0] != '.' && flags.f_a == 0)
				|| flags.f_a == 1)
			{
				ft_putchar('d');
				if (i == 0)
				{
					ft_putchar('e');
					first_elem(content, fold.readfile->d_name, path);
					i++;
				}
				else
				{
					ft_putchar('f');
					new_elem(content, fold.readfile->d_name, path);
					ft_putchar('1');
				}
				ft_putchar('g');
			}
			ft_putchar('h');
	}
	ft_putchar('i');
	my_printf(content, flags);
	ft_putchar('\n');
	return (content);
}

// The following function is used only if the -R flag is activated.
// It will check each elem of the linked list and go through each
// folder to list what is inside it.

void		recursive_func(t_lst *content, t_flags flags)
{
	struct stat		sb;

	if (stat(content->path, &sb) == -1)
		error(3, "");
	if (S_ISDIR(sb.st_mode))
	{
		ft_putstr(content->path);
		ft_putstr(":\n");
		open_directory(content->path, flags);
	}
	if (content->next)
		recursive_func(content->next, flags);
}
