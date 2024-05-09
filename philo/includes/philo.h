/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:50:40 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/27 11:47:58 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define DIE "is DIED"
# include <pthread.h>

typedef struct s_philo
{
	int				right_fork;
	int				left_fork;
	int				eat_count;
	int				philo_id;
	struct s_table	*table;
	u_int64_t		last_eat;
	pthread_t		thread;
}				t_philo;

typedef struct s_table
{
	int				philo_count;
	int				philo_eat;
	int				die_control;
	int				must_eat;
	int				eat_ctrl;
	u_int64_t		s_time;
	u_int64_t		eat_time;
	u_int64_t		sleep_time;
	u_int64_t		dead_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	die;
	pthread_mutex_t	time;
	t_philo			*philo;
}				t_table;

int			ft_atoi(char *str);
u_int64_t	ft_atol(char *str);
void		error_states(int error_number);
void		destroy(t_table *table, int size);
void		die_waiting(t_table *table);
void		take_fork(t_philo *philo);
void		eating(t_philo *philo);
int			parametre_control(char **str);
u_int64_t	now_time(void);
void		waiting(u_int64_t time);
int			m_init(t_table *table);
int			p_init(t_table *table);
int			t_init(char **str, int ac, t_table *table);
void		start_dinner(t_table *table);
void		lock_unlock(t_table *table, int lock_number);

#endif