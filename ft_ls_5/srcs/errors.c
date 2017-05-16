#include "../inc/ft_ls.h"

void		error(int a, char *str)
{
	if (a == 0)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(str);
		ft_putstr(": No such file or directory\n");
	}
	else if (a == 1)
	{
		ft_putstr("ft_ls: illegal optin -- ");
		ft_putstr(str);
		ft_putstr("\nusage: ./ft_ls [-lRart] [file ...]\n");
		exit(1);
	}
	else if (a == 2)
	{
		ft_putstr("Dynamic allocation failed somewhere.\n");
		exit(1);
	}
	else
		error_2(a, str);
}

void		error_2(int a, char *str)
{
	if (a == 3)
	{
		ft_putstr("Stat function failed - ");
		ft_putstr(str);
		ft_putchar('\n');
		exit(1);
	}
	else if (a == 4)
	{
		ft_putstr("Opening failed - ");
		ft_putstr(str);
		ft_putstr("\nerrno = ");
		ft_putnbr(errno);
		exit(1);
	}
	else if (a == 5)
	{
		ft_putstr("Closing failed somewhere.\n");
		ft_putnbr(errno);
		exit(1);
	}
}
