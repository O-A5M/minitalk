#include "minitalk.h"

int	signal_sign;

static void	send_signal(int pid, char c)
{
	int	bit;
	int	time;

	bit = 7;
	while (bit >= 0)
	{
		signal_sign = 0;
		if ((c >> bit) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		time = 0;
		while (!signal_sign && time < 50)
		{
			usleep(350);
			time++;
		}
		if (!signal_sign)
			exit(1);
		bit--;
	}
}

static void	string_manipulation(int	pid, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_signal(pid, s[i]);
		i++;
	}
}

static int	pid_parsing(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '+' && s[i] != '-' && (s[i] < '0' || s[i] > '9'))
		{
			ft_putstr_fd("Error\n", 1);
			exit(1);
		}
		i++;
	}
	return (ft_atoi(s));
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		signal_sign = 1;
	else
		exit(0);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 3)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	pid = pid_parsing(av[1]);
	string_manipulation(pid, av[2]);
}
