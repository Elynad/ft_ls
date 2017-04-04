#ifndef FT_LS_H

# define FT_LS_H

#include "../libft/libft.h"
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>		// DELETE BEFORE LAST PUSH

typedef struct		s_folders
{
	DIR					*rep;
	struct dirent		*readfile;
	struct stat			*info;
	char				**names;
	int					index;
	struct s_folders	*next;
}					t_folders;

typedef struct		s_flags
{
	int				f_l;
	int				f_R;
	int				f_a;
	int				f_r;
	int				f_t;
}					t_flags;

typedef struct		s_box
{
	DIR				*rep;
	struct dirent	*readfile;
	struct stat		*info;
}					t_box;


int					recursive_test(t_flags flags);

/*
**		PARSING
*/

void				parsing(t_flags *flags, char **arguments);


/*
**		OTHER
*/

void				fusion(char **double_char, char **str);
void				init_flags_struct(t_flags *flags);
void				init_box_struct(t_box *box);
void				init_folders_struct(t_folders *folders);
void				error(int a);

#endif
