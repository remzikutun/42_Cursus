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

static void	print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->die);
	pthread_mutex_lock(&philo->table->time);
	if (!philo->table->die_control)
		printf("%lld %d %s\n", now_time() - philo->table->s_time,
			philo->philo_id, str);
	pthread_mutex_unlock(&philo->table->die);
	pthread_mutex_unlock(&philo->table->time);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left_fork]);
	print(philo, "has a fork");
	pthread_mutex_lock(&philo->table->forks[philo->right_fork]);
	print(philo, "has a fork");
}

void	eating(t_philo *philo)
{
	print(philo, "is eating");
	waiting(philo->table->eat_time);
	pthread_mutex_lock(&philo->table->time);
	philo->last_eat = now_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->table->time);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork]);
	print(philo, "is sleeping");
	waiting(philo->table->sleep_time);
	print(philo, "is thinking");
}
