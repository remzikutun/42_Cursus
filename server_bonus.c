/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:17:24 by rkutun            #+#    #+#             */
/*   Updated: 2023/11/29 12:10:33 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int number)
{
	if (number > 9)
	{
		ft_putnbr(number / 10);
		number = (number % 10);
	}
	write(1, &"0123456789"[number], 1);
}

void	binary_to_decimal_convert(int sig)
{
	static int	bit = 128;
	static int	dec = 0;

	if (sig == SIGUSR1)
		dec += bit;
	bit /= 2;
	if (bit == 0)
	{
		write(1, &dec, 1);
		bit = 128;
		dec = 0;
	}
}

int	main(void)
{
	write(1, "PID : ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, binary_to_decimal_convert);
	signal(SIGUSR2, binary_to_decimal_convert);
	while (1)
	{
		pause();
	}
}
