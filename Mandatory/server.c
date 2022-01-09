/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:00:40 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/12/18 15:20:51 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	g_pid;

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = n;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = -number;
	}
	if (number >= 10)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putnbr_fd(number % 10, fd);
	}
	else
	{
		number += '0';
		write(fd, &number, 1);
	}
}

void	signal_manager(int sig, siginfo_t *siginfo, void *ptr)
{
	static char		byte = 0;
	static int		i = 8;

	if ((g_pid == -1 || g_pid != siginfo->si_pid) && siginfo->si_pid != 0)
	{
		g_pid = siginfo->si_pid;
		byte = 0;
		i = 8;
	}
	i--;
	if (sig == SIGUSR1)
		byte = byte | (1 << i);
	if (i == 0)
	{
		write(1, &byte, 1);
		byte = 0;
		i = 8;
	}
	ptr = 0;
}

int	main(void)
{
	struct sigaction	sa;

	g_pid = -1;
	sa.sa_sigaction = &signal_manager;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
