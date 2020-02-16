#include <stdlib.h>
#include <stdio.h>

void	o()
{
	system("/bin/sh");
	_exit();
}

void	n()
{
	char	buffer[512];
	
	fgets(buffer, 512, STDIN);
	printf(buffer);
	exit();
}

int	main()
{
	n();
	return (0);
}
