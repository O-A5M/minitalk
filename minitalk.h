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
