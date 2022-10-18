/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:19:18 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/18 13:54:35y jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/time.h>

#include "../../includes/philo.h"
#include "../../includes/parsing/parsing.h"
#include "../../includes/simulation/simulation.h"
#include "../../includes/waitor/waitor.h"
#include "../../includes/philosophers/philosopher.h"
#include "../../includes/utils/utils.h"
#include "../../includes/simulation/life.h"

int	create_life(t_philosophers	*philosopher)
{
	philosopher->alive = true;
	pthread_create(philosopher->life, NULL, life, philosopher);
	return (0);
}

int	simulation_start(unsigned int nu_philo, t_philosophers *philosopher)
{
	unsigned int	i;
	t_philosophers	*current;
	struct timeval	simulation_start_time;

	i = 0;
	gettimeofday(&simulation_start_time, NULL);
	printf("simulation started");
	while (i < nu_philo)
	{
		current = philosopher + i;
		create_life(current);
		i++;
	}
	return (0);
}

int	simulation(t_args args)
{
	t_philosophers	*philosophers;
	bool			simulation_run;

	philosophers = init_philosophers(args, &simulation_run);
	if (!philosophers)
		return (exit_clean(philosophers));
	simulation_run = true;
	waitor(args, philosophers, &simulation_run);
	simulation_start(args.nu_philo, philosophers);
	return (0);
}
