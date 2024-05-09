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

#include <stdio.h>

static	void	falsestart(void)
{
	printf("\nInappropriate use. Usage : ./philo 1 2 3 4 5");
	printf("\n-> 1: Number of Philosophers.");
	printf("\n-> 2: Time to die for the Philosophers.");
	printf("\n-> 3: Dinnertime for the Philosophers.");
	printf("\n-> 4: Bedtime for the Philosophers.");
	printf("\n-> 5: [Optional]The number of times philosophers eat.\n\n");
}

void	error_states(int error_number)
{
	if (error_number == 1)
		falsestart();
	if (error_number == 2)
		printf("\nThe values entered must be positive number values.\n\n");
	if (error_number == 3)
		printf("\nThe mutex initialization error.\n\n");
}
