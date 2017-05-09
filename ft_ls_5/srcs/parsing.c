#include "../inc/ft_ls.h"

t_list		parsing(char **str, t_flags *flags)
{
	int		i;

	i = 0;
}

void		get_flags(char **str, t_flags *flags, int *i)
{
	int		j;

	while (str[*i][0] == '-')
	{
		j = 0;
		while (str[*i][j])
		{
			if (str[*i][j] == 'l')
				flags->f_l == 1;
			else if (str[*i][j] == 'R')
				flags->f_R == 1;
			else if (str[*i][j] == 'a')
				flags->f_a == 1;
			else if (str[*i][j] == 'r')
				flags->f_r == 1;
			else if (str[*i][j] == 't')
				flags->f_t == 1;
			else
				error(0, str[*i][j]);
			j++;
		}
		*i++;
	}
}
