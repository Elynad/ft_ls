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
			error(4, "");
		while ((fold.readfile = readdir(fold.rep)) != NULL)
			dependencies++;
	}
	else if (S_ISREG(sb.st_mode))
		dependencies = 1;
	ft_putnbr(dependencies);
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
	char				*s1;
	int					i;

	i = 3;
	if (!(s1 = (char *)malloc(sizeof(char) * (ft_strlen(ctime(&sb.st_mtime))))))
		error(2, "");
		s1 = ft_strcpy(s1, (ctime(&sb.st_mtime)));
	while (i <= 15)
	{
		ft_putchar(s1[i]);
		i++;
	}
	ft_putchar('\t');
	free(s1);
}
