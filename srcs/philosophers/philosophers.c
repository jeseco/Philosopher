/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:48 by jcourtem          #+#    #+#             */
/*   Updated: 2022/11/01 18:57:13 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "../../includes/philo.h"
#include "../../includes/philosophers/philosopher.h"
#include "../../includes/utils/utils.h"

time_t	random_float(time_t time_to_think, int i)
{
	float	time_to_hunger;

	if (i % 2)
		time_to_hunger = time_to_think / 4;
	else
		time_to_hunger = time_to_think / 2;
	return (time_to_hunger);
}

struct s_philosophers	*init_philosophers(t_args args, bool *simulation_run, \
time_t *simulation_start_time)
{
	unsigned int	i;
	t_philosophers	*philosophers;
	t_philosophers	*current;

	i = 1;
	philosophers = ft_calloc(args.nu_philo, sizeof(t_philosophers));
	while (i <= args.nu_philo)
	{
		current = philosophers + (i - 1);
		current->nu_philos = args.nu_philo;
		current->name = i;
		current->state = THINKING;
		current->alive = true;
		current->time_to_die = args.time_to_die;
		current->time_to_eat = args.time_to_eat;
		current->time_to_sleep = args.time_to_sleep;
		current->time_to_think = current->time_to_die - \
								(current->time_to_eat + current->time_to_sleep);
		current->simulation_run = simulation_run;
		current->simulation_start_time = simulation_start_time;
		current->time_to_hunger = random_float(current->time_to_think, i);
		if (args.number_of_meal > 0)
			current->target_num_meal = args.number_of_meal;
		i++;
	}
	return (philosophers);
}
