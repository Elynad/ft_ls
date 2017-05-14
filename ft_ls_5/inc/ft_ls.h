#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
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
}						t_fold;

typedef struct			s_lst
{
	char				*name;
	char				*path;
	long				time;
	struct s_lst		*next;
}						t_lst;

/*
**		PARSING
*/

char					**parsing(char **arguments, t_flags *flags);
void					get_flags(t_flags *flags, char *str);
char					**get_fargs(char **arguments, int index);
char					**no_args(void);

/*
**		CORE FUNC
*/

t_lst					core_func(char *path, int index, t_flags flags);
t_lst					*open_directory(char *path, t_flags flags);
void					recursive_func(t_lst *content, t_flags flags);

/*
**		LINKED LISTS
*/

void					first_elem(t_lst *list, char *name, char *path);
void					new_elem(t_lst *list, char *name, char *path);
char					*set_path(char *path, char *name);

/*
**		PRINT
*/

void					my_printf(t_lst *list, t_flags flags);
void					print_no_flags(t_lst *list, t_flags flags);
void					print_l_flag(t_lst *list, t_flags flags);
void					lprint_2(char *str, char *path, struct stat sb);
void					print_type(struct stat sb);
void					print_dependencies(char *path, struct stat sb);
void					print_author(char *str, struct stat sb);
void					print_group(char *str, struct stat sb);
void					print_time(char *str, struct stat sb);
void					print_rights(struct stat sb);
void					print_usr_rights(struct stat sb);
void					print_grp_rights(struct stat sb);
void					print_oth_rights(struct stat sb);

/*
**		SORT
*/

void					sort_reverse(t_lst *list);	// TEST

/*
**		INIT
*/

void					init_flags_struct(t_flags *flags);
void					init_fold_struct(t_fold *fold);

/*
**		ERRORS
*/

void					error(int a, char *str);

#endif
