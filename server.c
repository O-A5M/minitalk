#include "minitalk.h"

t_minitalk	data;

void	server_handler(int signum, siginfo_t *pid, void *param)
{
	(void)param;
	if (data.n_bits != 0 && data.client != pid->si_pid)
		data.n_bits = 0;
	if (signum == SIGUSR1)
		data.byte = (data.byte << 1) | 1;
	else
		data.byte <<= 1;
	data.n_bits++;
	if (data.n_bits < 8)
		data.flag = 1;
	data.client = pid->si_pid;
}

void	print_data(void)
{
	while (1)
	{
		if (data.flag)
		{
			data.flag = 0;
			kill(data.client, SIGUSR1);
		}
		else if (data.n_bits == 8)
		{
			if (data.byte)
			{
				write(1, &data.byte, 1);
				data.n_bits = 0;
				kill(data.client, SIGUSR1);
			}
			else
			{
				write(1, "\n", 1);
				data.n_bits = 0;
				kill(data.client, SIGUSR2);
			}
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = server_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	write(1, "PID=>", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	print_data();
}
