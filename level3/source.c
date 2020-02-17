#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	v()
{
	int	m = 0;
	char	buffer[512];
	
	fgets(buffer, 512, STDIN);
	printf(buffer);
	if (m != 64)
		return ;
	write(1, "Wait what?!\n", 12);
	system("bin/sh");
}

int	main()
{
	v();
	return (0);
}
