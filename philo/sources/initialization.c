/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:16:04 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/25 17:01:52 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdlib.h>

int	m_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (i - 1);
		i++;
	}
	if (pthread_mutex_init(&table->write, NULL) != 0)
	{
		error_states (3);
		return (i - 1);
	}
	if (pthread_mutex_init(&table->die, NULL) != 0)
		return (i - 1);
	if (pthread_mutex_init(&table->time, NULL) != 0)
		return (i - 1);
	return (0);
}

int	p_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		table->philo[i].philo_id = i + 1;
		table->philo[i].left_fork = i;
		table->philo[i].right_fork = i - 1;
		if (i == 0)
			table->philo[i].right_fork = table->philo_count - 1;
		table->philo[i].last_eat = 0;
		table->philo[i].eat_count = 0;
		table->philo[i].table = table;
		i++;
	}
	return (0);
}

int	t_init(char **str, int ac, t_table *table)
{
	table->philo_count = atoi(str[1]);
	table->dead_time = atol(str[2]);
	table->eat_time = atol(str[3]);
	table->sleep_time = atol(str[4]);
	table->must_eat = -1;
	table->eat_ctrl = 0;
	if (ac == 6)
		table->must_eat = atoi(str[5]);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	if (!table->forks)
		return (0);
	table->philo = malloc(sizeof(t_philo) * table->philo_count);
	if (!table->philo)
		return (free(table->forks), 0);
	return (1);
}
