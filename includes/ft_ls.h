#ifndef FT_LS_H

# define FT_LS_H

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	print_func(char c, char *str);
char	**get_files_name(char **str);
void	open_close_error(int a);

#endif
