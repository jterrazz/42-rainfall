#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av)
{
	char 	buffer[40];	
	size_t 	size;

	size = atoi(av[1]);
	if (size <= 9)
	{
		memcpy(buffer, av[2], size * 4);
		if (size == 0x574f4c46)
			execl("/bin/sh", "sh", 0);
		return (0);
	}
	return (1);
}
