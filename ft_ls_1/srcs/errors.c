#include "../includes/ft_ls.h"

void	open_close_error(int a)
{
	if (a == 0)
		perror("Opening - FAILURE\nError : ");
	else if (a == 1)
		perror("Closing - FAILURE\nError : ");
	else if (a == 2)
		printf("Malloc failed.\n");
	exit(-1);
}
