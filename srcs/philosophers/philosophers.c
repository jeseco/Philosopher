/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:48 by jcourtem          #+#    #+#             */
/*   Updated: 2022/11/08 10:45:44 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "../../includes/philo.h"
#include "../../includes/philosophers/philosopher.h"
#include "../../includes/utils/utils.h"

time_t	calculate_tth(time_t time_to_think, int i)
{
	float	time_to_hunger;

	if (i % 2)
		time_to_hunger = time_to_think / 4;
	else
		time_to_hunger = time_to_think / 2;
	return (time_to_hunger);
}

time_t	calc_time_to_think(t_args args)
{
	time_t	time_to_think;

	time_to_think = args.time_to_die \
					- args.time_to_eat \
					+ args.time_to_sleep;
	return (time_to_think);
}

struct s_philosophers	*init_philosophers(t_args args, bool *simulation_run, \
time_t *simulation_start_time, pthread_mutex_t *forks)
{
	unsigned int	i;
	t_philosophers	*philosophers;
	t_philosophers	*current;

	i = 1;
	philosophers = ft_calloc(args.nu_philo, sizeof(t_philosophers));
	while (i <= args.nu_philo)
	{
		current = philosophers + (i - 1);
		current->l_fork = forks + (i - 1);
		if (i != args.nu_philo)
			current->r_fork = forks + i;
		else
			current->r_fork = forks + 0;
		current->name = i;
		current->state = THINKING;
		current->alive = true;
		current->args = args;
		current->time_to_think = calc_time_to_think(args);
		current->simulation_run = simulation_run;
		current->simulation_start_time = simulation_start_time;
		current->time_to_hunger = calculate_tth(current->time_to_think, i);
		if (args.number_of_meal > 0)
			current->target_num_meal = args.number_of_meal;
		i++;
	}
	return (philosophers);
}
