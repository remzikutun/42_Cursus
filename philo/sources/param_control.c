/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:41:50 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/25 13:07:31 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parametre_control(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '\0')
			return (0);
		if (ft_atol(str[i]) > 2147483647)
			return (1);
		while (str[i][j])
		{
			if (str[i][0] == '0' && str[i][1] == '\0')
				return (2);
			if (str[i][j] < '0' || str[i][j] > '9')
				return (3);
			j++;
		}
		i++;
	}
	return (4);
}
