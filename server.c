/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:31:53 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/03/18 14:31:55 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_minitalk	g_data;

void	server_handler(int signum, siginfo_t *pid, void *param)
{
	(void)param;
	if (g_data.n_bits != 0 && g_data.client != pid->si_pid)
		g_data.n_bits = 0;
	if (signum == SIGUSR1)
		g_data.byte = (g_data.byte << 1) | 1;
	else
		g_data.byte <<= 1;
	g_data.n_bits++;
	if (g_data.n_bits < 8)
		g_data.flag = 1;
	g_data.client = pid->si_pid;
}

void	print_data(void)
{
	while (1)
	{
		if (g_data.flag)
		{
			g_data.flag = 0;
			kill(g_data.client, SIGUSR1);
		}
		else if (g_data.n_bits == 8)
		{
			if (g_data.byte)
			{
				write(1, &g_data.byte, 1);
				g_data.n_bits = 0;
				kill(g_data.client, SIGUSR1);
			}
			else
			{
				write(1, "\n", 1);
				g_data.n_bits = 0;
				kill(g_data.client, SIGUSR2);
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
