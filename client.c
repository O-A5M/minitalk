#include "minitalk.h"

int	sign;

int	parse_pid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '+' && s[i] != '-' && (s[i] < '0' || s[i] > '9'))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return ft_atoi(s);
}

void	client_handler(int signal)
{
	(void)signal;
	sign = 1;
}

void	send_message(int pid, char *s)
{
	int		i;
	char	j;

	i = 0;
	while (1)
	{
		j = 8;
		while (--j >= 0)
		{
			if ((s[i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			if (!sign)
			{
				write(1, "Error\n", 6);
				exit (1);
			}
			sign = 0;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
}

int	main(int ac, char **av)
{
	int				s_pid;
	struct sigaction	sa;

	if (ac != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	s_pid = parse_pid(av[1]);
	if (s_pid == -1 || av[2][0] == '\0')
	{
		write(1, "Error\n", 6);
		return (1);
	}
	sa.sa_handler = client_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		write(1, "Error\n", 19);
		return (1);
	}
	send_message(s_pid, av[2]);
}
