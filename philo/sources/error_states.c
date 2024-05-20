/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:31:19 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/27 11:36:39 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>

void	falsestart(void)
{
	printf("🔴 \x1b[31mInappropriate use. Usage : ./philo 1 2 3 4 5\n");
	printf("\x1b[31m-> 1: Number of Philosophers.\n");
	printf("\x1b[31m-> 2: Time to die for the Philosophers.\n");
	printf("\x1b[31m-> 3: Dinnertime for the Philosophers.\n");
	printf("\x1b[31m-> 4: Bedtime for the Philosophers.\n");
	printf("\x1b[31m-> 5: [Optional]The number of times philosophers eat.\n");
	printf("\x1b[0m-----------------------------------------------------");
}

int	error_states(char **av, int error_number)
{
	int	error_control;

	error_control = parametre_control(&av[1]);
	if (error_number == 1)
		printf(M_INIT);
	if (error_control != 4)
	{
		if (error_control == 0)
			printf(EMPTY);
		if (error_control == 1)
			printf(BIG_NUMBER);
		if (error_control == 2)
			printf(ZERO);
		if (error_control == 3)
			printf(INT);
		return (0);
	}
	return (1);
}
