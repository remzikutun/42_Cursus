/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:41:12 by rkutun            #+#    #+#             */
/*   Updated: 2023/10/25 14:01:16 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_formats(va_list args, const char formats)
{
	if (formats == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (formats == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (formats == 'p')
		return (ft_printfptr(va_arg(args, unsigned long int),
				"0123456789abcdef", 0));
	else if (formats == 'd' || formats == 'i')
		return (ft_printfgnrl(va_arg(args, int), "0123456789", 10));
	else if (formats == 'u')
		return (ft_printfgnrl(va_arg(args, unsigned int), "0123456789", 10));
	else if (formats == 'x')
		return (ft_printfgnrl(va_arg(args, unsigned int),
				"0123456789abcdef", 16));
	else if (formats == 'X')
		return (ft_printfgnrl(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16));
	else if (formats == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		lenght;
	int		tmp;

	index = 0;
	lenght = 0;
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%')
		{
			tmp = ft_formats(args, str[++index]);
			if (tmp == -1)
				return (-1);
			lenght += tmp;
		}
		else if (ft_putchar(str[index]) < 0)
			return (-1);
		else
			lenght += 1;
		index++;
	}
	va_end(args);
	return (lenght);
}
