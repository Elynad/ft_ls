#include "../inc/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flags		flags;
	char		**fargs;
	int			i;

	i = 0;
	init_flags_struct(&flags);
	fargs = parsing(argv, &flags);
	while (fargs[i])
	{
		core_func(fargs[i], 0, flags);
		i++;
	}
	return (0);
}
