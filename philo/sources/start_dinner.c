/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:23:13 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/27 11:50:42 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>

static void	*dinner_func(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)(arg);
	pthread_mutex_lock(&philo->table->time);
	while (!philo->table->s_time)
	{
		pthread_mutex_unlock(&philo->table->time);
		pthread_mutex_lock(&philo->table->time);
	}
	pthread_mutex_unlock(&philo->table->time);
	if ((philo->philo_id % 2) == 0)
		waiting(20);
	pthread_mutex_lock(&philo->table->die);
	while (!philo->table->die_control && philo->eat_count != \
		philo->table->must_eat)
	{
		pthread_mutex_unlock(&philo->table->die);
		take_fork(philo);
		eating(philo);
		pthread_mutex_lock(&philo->table->die);
	}
	philo->table->eat_ctrl++;
	pthread_mutex_unlock(&philo->table->die);
	return (NULL);
}

static void	die_controls(t_table *table)
{
	int	i;

	while (table->eat_ctrl != table->philo_count)
	{
		i = -1;
		while (++i < table->philo_count)
		{
			lock_unlock(table, 1);
			if (now_time() - table->philo[i].last_eat >= table->dead_time)
			{
				table->die_control = 1;
				printf("%lld %d %s", now_time() - table->s_time, i + 1, DIE);
				break ;
			}
			lock_unlock(table, 2);
		}
		if (table->die_control)
		{
			lock_unlock(table, 2);
			break ;
		}
	}
}

void	start_dinner(t_table *table)
{
	int	i;

	i = 0;
	table->s_time = 0;
	table->die_control = 0;
	while (i < table->philo_count)
	{
		pthread_create(&table->philo[i].thread, NULL, &dinner_func,
			&table->philo[i]);
		i++;
	}
	pthread_mutex_lock(&table->time);
	table->s_time = now_time();
	pthread_mutex_unlock(&table->time);
	die_waiting(table);
	die_controls(table);
	i = 0;
	while (i < table->philo_count)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}
