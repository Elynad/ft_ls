#include "../inc/ft_ls.h"

void		my_printf(t_lst *list, t_flags flags)
{
	// need to sort the list before print it
	if (flags.f_l == 0)
		print_no_flags(list, flags);
	else if (flags.f_l == 1)
		print_l_flag(list, flags);
}

void		print_no_flags(t_lst *list, t_flags flags)
{
	ft_putstr(list->name);
	ft_putchar('\n');
	if (list->next)
		print_no_flags(list->next, flags);
}

void		print_l_flag(t_lst *list, t_flags flags)
{
	struct stat		sb;

	ft_putstr("File: ");
	ft_putstr(list->name);
	ft_putchar('\t');
	ft_putstr("Path :");
	ft_putstr(list->path);
	ft_putchar('\n');
	if (stat(list->path, &sb) == -1)
		error(3, "");
	lprint_2(list->name, list->path, sb);
	if (list->next)
		print_l_flag(list->next, flags);
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
