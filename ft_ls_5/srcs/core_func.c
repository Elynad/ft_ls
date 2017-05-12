#include "../inc/ft_ls.h"

t_lst		core_func(char *path, int index, t_flags flags)
{
	struct stat		sb;
	t_lst			content;

	if (stat(path, &sb) == -1)
		error(0, path);
	if (S_ISDIR(sb.st_mode))
	{
		content = open_directory(path, flags);
	}
	else if (S_ISREG(sb.st_mode))
	{
		ft_putstr(path);
	}
}

t_lst		open_directory(char *path, t_flags flags)
{
	t_fold		fold;
	t_lst		content;

	init_fold_struct(&fold);
	content.next = NULL;
	if ((fold.rep = opendir(path)) == NULL)
		error(4, "");
	if ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		if ((fold.readfile->d_name[0] != '.' && flags.f_a == 0)
				|| flags.f_a == 1)
			first_elem(&content, fold.readfile->d_name, path);
	}
	while ((fold.readfile = readdir(fold.rep)) != NULL)
	{
		if ((fold.readfile->d_name[0] != '.' && flags.f_a == 0)
				|| flags.f_a == 1)
			new_elem(&content, fold.readfile->d_name, path);
	}
	my_printf(&content, flags);
}
