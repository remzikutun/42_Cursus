/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:49:10 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/25 17:18:00 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <sys/time.h>
#include <unistd.h>

void	die_waiting(t_table *table)
{
	u_int64_t	begin;

	begin = now_time() + table->dead_time;
	while (now_time() < begin && table->eat_ctrl != table->philo_count)
		usleep(200);
}

u_int64_t	now_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	waiting(u_int64_t time)
{
	u_int64_t	begin;

	begin = now_time() + time;
	while (now_time() < begin)
		usleep(200);
}
