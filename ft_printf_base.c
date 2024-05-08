/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:37:20 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/25 11:50:26 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *ptr)
{
	int	index;

	index = 0;
	if (!ptr)
		return (write(1, "(null)", 6));
	while (ptr[index] != '\0')
	{
		if (write(1, &ptr[index], 1) < 0)
			return (-1);
		index++;
	}
	return (index);
}

int	ft_printfptr(unsigned long int nmbr, char *base, int hex)
{
	int	counter;

	counter = 0;
	if (hex < 1)
	{
		if (ft_putstr("0x") < 0)
			return (-1);
		hex = 2;
		counter += 2;
	}
	if (nmbr >= 16)
		counter += ft_printfptr(nmbr / 16, base, hex);
	if (ft_putchar(base[nmbr % 16]) < 0)
		return (-1);
	return (counter + 1);
}

int	ft_printfgnrl(long int nmbr, char *base, int bsize)
{
	int	counter;
	int	tmp;

	counter = 0;
	if (nmbr < 0)
	{
		if (ft_putchar('-') < 0)
			return (-1);
		nmbr *= -1;
		counter++;
	}
	if (nmbr >= bsize)
	{
		tmp = ft_printfgnrl(nmbr / bsize, base, bsize);
		if (tmp < 0)
			return (-1);
		counter += tmp;
	}
	if (ft_putchar(base[nmbr % bsize]) < 0)
		return (-1);
	return (counter + 1);
}
