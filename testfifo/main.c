#include <sys/types.h>
#include <sys/stat.h>

int		main(void)
{
	mkfifo("./test_fifo", 777);
	return (0);
}
