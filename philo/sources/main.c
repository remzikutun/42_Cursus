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
		if (error_states(av, 0) == 0)
			return (0);
		if (t_init(av, ac, &table) == 0)
			return (0);
		p_init(&table);
		check = m_init(&table);
		if (check)
		{
			error_states(av, 1);
			destroy(&table, check);
			return (0);
		}
		start_dinner(&table);
		destroy(&table, table.philo_count + 4);
	}
	else
		falsestart();
}
