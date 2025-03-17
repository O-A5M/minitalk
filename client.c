#include "minitalk.h"

int	main(int ac, char **av)
{
	ac = ac + 1;
	kill(ft_atoi(av[1]), SIGUSR1);
}
