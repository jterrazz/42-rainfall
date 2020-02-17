#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	run()
{ 
	write(1, "Good... Wait what?\n", 19);
	system("/bin/sh");
}

int	main()
{
	char	*buffer;
	
	gets(buffer);
	return (0);
}
