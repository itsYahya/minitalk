/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:00:48 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/12/21 14:39:54 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int g_server_conferm = 1;
int	ft_itoa(char *num)
{
	int	index;
	int	number;

	index = 0;
	number = 0;
	while (num[index])
		number = number * 10 + (num[index++] - '0');
	return (number);
}

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

void	printf_bits(char bits, int p_id)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		while (g_server_conferm)
			;
		g_server_conferm = 0;
		if ((bits & (1 << i)) == 0)
			kill(p_id, SIGUSR2);
		else
			kill(p_id, SIGUSR1);
		i--;
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	size_t	index;
	int		prossec;
	size_t	len;

	index = 0;
	if (argc > 2)
	{
		len = ft_strlen(argv[2]);
		prossec = ft_itoa(argv[1]);
		while (index < len)
			printf_bits(argv[2][index++], prossec);
	}
	return (0);
}
