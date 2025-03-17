#ifndef MINITALK_H
# define MINITALK_H
// # define _POSIX_C_SOURCE 201112L
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_minitalk
{
	char	received_char;
	int		bit_count;
	int		pid_sender;
}				t_minitalk;


int		ft_atoi(const char *nptr);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
