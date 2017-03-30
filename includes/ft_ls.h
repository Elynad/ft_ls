#ifndef FT_LS_H

# define FT_LS_H

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct		s_flags
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_flags;

void	print_func(char c, char *str);
char	**get_files_name(char **str);
void	open_close_error(int a);
int		calc_files_number(void);

void	ft_swap_str(char **s1, char **s2);
int		ft_check_str(char **str);
char	**alpha_sorting(char **str);
void	print_d_str(char **str, int way);

#endif
