/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:08:53 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/25 17:11:56 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>

void	destroy(t_table *table, int size)
{
	int	i;

	i = 0;
	while (i < table->philo_count && i < size)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	if (i < size)
		pthread_mutex_destroy(&table->write);
	i++;
	if (i < size)
		pthread_mutex_destroy(&table->die);
	i++;
	if (i < size)
		pthread_mutex_destroy(&table->time);
	free(table->philo);
	free(table->forks);
}
