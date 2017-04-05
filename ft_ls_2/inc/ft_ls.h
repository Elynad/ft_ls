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
#include <pwd.h>
#include <grp.h>
#include <time.h>
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
**		SORTING
*/

void				ft_swap_str(char **s1, char **s2);
int					ft_check_str(char **str);
char				**alpha_sorting(char **str);
void				revalpha_sorting(char **str);
void				print_d_str(char **str, int way);

/*
**		PRINTING
*/

void				my_printf(char **str, t_flags flags);
void				print_no_flags(char **str, t_flags flags);
void				print_l_flag(char **str, t_flags flags);

/*
**		PRINTING WITHIN
*/

void				print_type(char *str, struct stat sb);
void				print_dependencies(char *str, struct stat sb);
void				print_author(char *str, struct stat sb);
void				print_group(char *str, struct stat sb);
void				print_time(char *str, struct stat sb);

/*
**		PRINTING RIGHTS
*/

void				print_rights(char *str, struct stat sb);
void				print_usr_rights(char *str, struct stat sb);
void				print_grp_rights(char *str, struct stat sb);
void				print_oth_rights(char *str, struct stat sb);

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
