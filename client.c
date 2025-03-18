/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:30:35 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/03/18 14:30:38 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sign;

static void	error_message(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	parse_pid(char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		error_message();
	if ((s[0] == '+' || s[0] == '-') && s[1] == '\0')
		error_message();
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	else
		i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			error_message();
		i++;
	}
	return (ft_atoi(s));
}

void	client_handler(int signal)
{
	(void)signal;
	g_sign = 1;
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
			if (!g_sign)
				error_message();
			g_sign = 0;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
}

int	main(int ac, char **av)
{
	int					s_pid;
	struct sigaction	sa;

	if (ac != 3)
		error_message();
	s_pid = parse_pid(av[1]);
	if (s_pid == -1 || av[2][0] == '\0')
		error_message();
	sa.sa_handler = client_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		error_message();
	send_message(s_pid, av[2]);
}
