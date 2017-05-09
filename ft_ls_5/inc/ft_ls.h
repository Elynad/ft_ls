#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <dirrent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>			// May be not useful

typedef struct			s_flags
{
	int					f_l;
	int					f_R;
	int					f_a;
	int					f_r;
	int					f_t;
}						t_flags;

typedef struct			s_fold
{
	DIR					*rep;
	struct dirent		*readfile;
	struct stat			*info;
	int					index;
	char				**names;
}						t_fold;

typedef struct			s_list
{
	char				*name;
	int					time;
	struct s_list		*next;
}						t_list;

#endif
