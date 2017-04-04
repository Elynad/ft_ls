#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int		main(void)
{
	 DIR			*rep;
	 struct dirent	*readfile;
	 struct stat	sb;

	 rep = NULL;
	 readfile = NULL;

	rep = opendir("./");
	if (rep == NULL)
		return (-1);
	while ((readfile = readdir(rep)) != NULL)
	{
		stat(readfile->d_name, &sb);
		printf("Size = %lld\t", sb.st_size);
		printf("%s\n", readfile->d_name);
	}
	if (closedir(rep) == -1)
		return (-1);
	return (0);
}
