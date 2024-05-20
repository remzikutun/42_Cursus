/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:20:56 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/27 11:49:36 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <stdio.h>

void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->die);
	pthread_mutex_lock(&philo->table->time);
	if (!philo->table->die_control)
		printf("\x1b[30m%5llums \x1b[33m%d %s\n", now_time() - \
	philo->table->s_time, philo->philo_id, str);
	pthread_mutex_unlock(&philo->table->die);
	pthread_mutex_unlock(&philo->table->time);
}

int	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	print(philo, "🍴 \x1b[35mhas taken a fork [Right_Hand ✋]\x1b[0m");
	if (philo->table->philo_count == 1)
	{
		pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
		waiting(philo->table->eat_time);
		return (1);
	}
	pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
	print(philo, "🍴 \x1b[35mhas taken a fork [Left_Hand  🤚]\x1b[0m");
	return (0);
}

int	eating(t_philo *philo)
{
	print(philo, EATING);
	waiting(philo->table->eat_time);
	pthread_mutex_lock(&philo->table->time);
	philo->last_eat = now_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->table->time);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	if (philo->eat_count == philo->table->must_eat)
	{
		philo->table->eat_ctrl++;
		return (1);
	}
	return (0);
}
