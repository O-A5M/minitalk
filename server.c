#include "minitalk.h"

void	print(int i)
{
	i = i + 1;
		printf("hello\n");
		exit(0);
}

int	main(int ac, char **av)
{
	ac = ac + 1;
	char **h = av;
	av = h;
	printf("%d\n", getpid());
	signal(SIGUSR1, print);
	while (1)
	{
		sleep(1);
	}
}
