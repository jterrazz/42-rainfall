#include <stdio.h>

char	c[80];
char	*s____d = "%s - %d\n";

void	m()
{
	printf(s____d, c, time());
}

int	main(int ac, char **av)
{
	char	*pass = "/home/user/level8/.pass";
	int	*save1;
	int	*save2;

	save1 = malloc(8);
	save1[0] = 1;
	save1[1] = malloc(8);

	save2 = malloc(8);
	save2[0] = 2;
	save2[1] = malloc(8);
	
	strcpy(save1[1], av[1]);
	strcpy(save2[1], av[2]);
	fgets(c, 68, fopen(pass, 0x80486e9));
	puts("~~");
	return (0);
}
