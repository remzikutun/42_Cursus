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
# define DIE "💀️ \x1b[31mis DIED\x1b[0m"
# define SLEEP "😴️ \x1b[34mis sleeping\x1b[0m"
# define THINK "🤔 \x1b[36mis thinking\x1b[0m"
# define EATING "🍝️ \x1b[32mis eating\x1b[0m"
# define EMPTY "🔴 \x1b[31mNo empty arguments should be entered!!!\x1b[0m\n"
# define BIG_NUMBER "🔴 \x1b[31mFalse argument : Arg < 2147483647!!!\x1b[0m\n"
# define ZERO "🔴 \x1b[31mThe value entered cannot be '0'.\x1b[0m\n"
# define INT "🔴 \x1b[31mThe argument entered must be an integer.\x1b[0m\n"
# define M_INIT "🔴 \x1b[31mThe mutex initialization error.\x1b[0m\n"
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
int			error_states(char **av, int error_number);
int			parametre_control(char **str);
int			m_init(t_table *table);
int			t_init(char **str, int ac, t_table *table);
int			take_fork(t_philo *philo);
int			eating(t_philo *philo);
void		falsestart(void);
void		destroy(t_table *table, int size);
void		die_waiting(t_table *table);
void		p_init(t_table *table);
void		waiting(u_int64_t time);
void		start_dinner(t_table *table);
void		lock_unlock(t_table *table, int lock_number);
void		print(t_philo *philo, char *str);
u_int64_t	now_time(void);
u_int64_t	ft_atol(char *str);

#endif