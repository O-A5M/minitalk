/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakhmouc <oakhmouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:30:13 by oakhmouc          #+#    #+#             */
/*   Updated: 2025/03/18 14:30:16 by oakhmouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>

typedef struct s_minitalk
{
	char	byte;
	pid_t	client;
	int		n_bits;
	int		flag;
}	t_minitalk;

int		ft_atoi(const char *s);
void	ft_putnbr_fd(int n, int fd);

#endif
