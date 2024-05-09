/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:16:30 by rkutun            #+#    #+#             */
/*   Updated: 2023/11/28 13:17:03 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result);
}

void	char_or_signals(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	count;

	count = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][count] != 0)
		{
			char_or_signals(pid, av[2][count]);
			count++;
		}
		char_or_signals(pid, '\n');
	}
	else if (ac != 3)
		write(1, "Please enter 3 arguments.", 25);
	return (0);
}
