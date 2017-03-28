#include "../includes/ft_ls.h"

char	**parsing(void)
{
	int				i;
	char			**str;

	i = calc_files_number();
	if (!(str = (char **)malloc(sizeof(char *) * (i + 1))))
		open_close_error(2);
	// i = calc_files_number();
	// malloc
	// recuperation files

}

int		calc_files_number(void)
{
	DIR					*rep;
	struct	dirent		*readfile;
	unsigned int		nbr_files;

	rep = NULL;
	readfile = NULL;
	nbr_files = 0;
	rep = opendir("./");
	if (rep == NULL)
		open_close_error(0);
	while ((readfile = readdir(rep)) != NULL)
		nbr_files++;
	return (nbr_files);
}
