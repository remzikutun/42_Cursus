/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_unlock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:02:46 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/27 11:47:43 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lock_unlock(t_table *table, int lock_number)
{
	if (lock_number == 1)
	{
		pthread_mutex_lock(&table->die);
		pthread_mutex_lock(&table->time);
	}
	if (lock_number == 2)
	{
		pthread_mutex_unlock(&table->die);
		pthread_mutex_unlock(&table->time);
	}
}
