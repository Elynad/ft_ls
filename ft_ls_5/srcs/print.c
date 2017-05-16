#include "../inc/ft_ls.h"

void		my_printf(t_lst *list, t_flags flags)
{
	// need to sort the list before printing it
	if (flags.f_l == 0)
		print_no_flags(list, flags);
	else if (flags.f_l == 1)
		print_l_flag(list, flags);
}

void		print_no_flags(t_lst *list, t_flags flags)
{
	ft_putstr(list->name);
	if (list->next)
		ft_putchar('\t');
	else
		ft_putchar('\n');
	if (list->next)
		print_no_flags(list->next, flags);
}

void		print_l_flag(t_lst *list, t_flags flags)
{
	struct stat		sb;

	// The if may be useless
	if (list && list->path && list->name)
	{
		ft_putstr(list->name);
		if (stat(list->path, &sb) == -1)
		{
			if (lstat(list->path, &sb) == -1)
				error(3, "print - line 27");
		}
		lprint_2(list->name, list->path, sb);
		if (list->next)
			print_l_flag(list->next, flags);
	}
}

void		lprint_2(char *str, char *path, struct stat sb)
{
	print_type(sb);
	print_rights(sb);
	print_dependencies(path, sb);
	print_author(str, sb);
	print_group(str, sb);
	ft_putnbr(sb.st_size);
	ft_putchar('\t');
	print_time(str, sb);
	ft_putstr(str);
	ft_putchar('\n');
}
