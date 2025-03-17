#include "minitalk.h"

static t_minitalk	data;

static void	signal_handler(int	signal, siginfo_t *pid, void *param)
{
	(void)param;
	if (data.bit_count == 0)
		data.received_char = 0;
	if (data.bit_count <= 7)
	{
		data.received_char <<= 1;
		if (signal == SIGUSR1)
		{
			data.received_char |= 1;
		}
		kill(pid->si_pid, SIGUSR1);
		data.bit_count++;
	}
	if (data.bit_count == 8)
	{
		if (data.received_char == '\0')
		{
			write(1, "\n", 1);
			kill(pid->si_pid, SIGUSR2);
		}
		else
		{
			write(1, &data.received_char, 1);
			kill(pid->si_pid, SIGUSR1);
		}
		data.bit_count = 0;
	}
}

int	main()
{
	struct sigaction	sa;

	data.bit_count = 0;
	data.received_char = 0;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		pause();
	}
}
