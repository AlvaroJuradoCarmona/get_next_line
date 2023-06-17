#include "get_next_line_bonus.h"
#include <fcntl.h>

int main(){

	char *str;

	int fd = open("fichero.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}