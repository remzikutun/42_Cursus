/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkutun <rkutun@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:59:22 by rkutun            #+#    #+#             */
/*   Updated: 2024/03/25 17:11:52 by rkutun           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	int		check;

	if (ac > 4 && ac < 7)
	{
		if (parametre_control(&av[1]) == 0)
		{
			error_states(2);
			return (1);
		}
		t_init(av, ac, &table);
		p_init(&table);
		check = m_init(&table);
		if (check)
		{
			destroy(&table, check);
			return (1);
		}
		start_dinner(&table);
		destroy(&table, table.philo_count + 4);
	}
	else
		error_states(1);
}
