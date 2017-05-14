#include "../inc/ft_ls.h"

void		init_flags_struct(t_flags *flags)
{
	flags->f_l = 0;
	flags->f_R = 0;
	flags->f_a = 0;
	flags->f_r = 0;
	flags->f_t = 0;
}

void		init_fold_struct(t_fold *fold)
{
	if (!(fold = malloc(sizeof(t_fold))))
		error(2, "");
	fold->rep = NULL;
	fold->readfile = NULL;
	fold->index = 0;
}
