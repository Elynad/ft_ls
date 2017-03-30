#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	ft_swap_str(char **s1, char **s2)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * strlen(*s1))))
		exit(-1);
	tmp = strcpy(tmp, *s1);
	if (!(*s1 = (char *)malloc(sizeof(char) * strlen(*s2))))
		exit(-1);
	*s1 = strcpy(*s1, *s2);
	if (!(*s2 = (char *)malloc(sizeof(char) * strlen(tmp))))
		exit(-1);
	*s2 = strcpy(*s2, tmp);
}

int		ft_check_str(char **str)
{
	int		i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (strcmp(str[i], str[i + 1]) > 0)
			return (1);
		i++;
	}
	return (0);
}

char	**alpha_sorting(char **str)
{
	int		i;

	while (ft_check_str(str) != 0)
	{
		i = 0;
		while (str[i] && str[i + 1])
		{
			if (strcmp(str[i], str[i + 1]) > 0)
				ft_swap_str(&str[i], &str[i + 1]);
			i++;
		}
	}
	return (str);
}

void	print_d_str(char **str, int way)
{
	int		i;

	if (way == 0)
	{
		i = 0;
		while (str[i])
		{
			printf("%s\t", str[i]);
			i++;
		}
	}
	else if (way == 1)
	{
		i = 0;
		while (str[i + 1])
			i++;
		while (i >= 0)
		{
			printf("%s\t", str[i]);
			i--;
		}
	}
	printf("\n");
}

int		main(int ac, char **av)
{
	char	**dstring;
	int		i;

	i = 0;
	if (!(dstring = (char **)malloc(sizeof(char *) * ac)))
		return (-1);
	while (av[i + 1])
	{
		if (!(dstring[i] = (char *)malloc(sizeof(char *) * strlen(av[i + 1]))))
			return (-1);
		dstring[i] = strcpy(dstring[i], av[i + 1]);
		i++;
	}
	dstring[i] = NULL;
	print_d_str(dstring, 0);
	dstring = alpha_sorting(dstring);
	print_d_str(dstring, 0);
	print_d_str(dstring, 1);

	return (0);
}
