#include "../inc/ft_ls.h"

char		**parsing(char **arguments, t_flags *flags)
{
	int		i;

	i = 1;
	while (arguments[i] && arguments[i][0] == '-' && arguments[i][1])
	{
		get_flags(flags, arguments[i]);
		i++;
	}
	if (arguments[i] && arguments[i][0] == '-' && !arguments[i][1])
		error(0, arguments[i]);
	return (get_fargs(arguments, i));
}

void		get_flags(t_flags *flags, char *str)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (str[i] && ft_is_space(str[i]) == 0)
	{
		if (str[i] == 'l')
			flags->f_l = 1;
		else if (str[i] == 'R')
			flags->f_R = 1;
		else if (str[i] == 'a')
			flags->f_a = 1;
		else if (str[i] == 'r')
			flags->f_r = 1;
		else if (str[i] == 't')
			flags->f_t = 1;
		else
			error(1, &str[i]);
		i++;
	}
}

char		**get_fargs(char **arguments, int index)
{
	char		**str;
	int			i;

	i = index;
	if (!arguments[index])
		return (no_args());
	while (arguments[i])
		i++;
	if (!(str = (char **)malloc(sizeof(char *) * (i - index + 1))))
		error(2, "");
	i = 0;
	while (arguments[index])
	{
		str[i] = ft_strdup(arguments[index]);
		index++;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char		**no_args(void)
{
	char		**str;

	if (!(str = (char **)malloc(sizeof(char *) * 2)))
		error(2, "");
	str[0] = ft_strdup("./");
	str[1] = NULL;
	return (str);
}
