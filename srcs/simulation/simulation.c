/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:19:18 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/20 09:04:07 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/time.h>
#include <time.h>

#include "../../includes/philo.h"
#include "../../includes/parsing/parsing.h"
#include "../../includes/simulation/simulation.h"
#include "../../includes/waitor/waitor.h"
#include "../../includes/philosophers/philosopher.h"
#include "../../includes/utils/utils.h"
#include "../../includes/simulation/life.h"

int	create_life(void *philosopher)
{
	pthread_t		life_tid;
	t_philosophers	*philo;

	philo = philosopher;
	life_tid = philo->life;
	philo->alive = true;
	printf("Birth of philosopher_%d\n", philo->name);
	pthread_create(&life_tid, NULL, life, philo);
	return (0);
}

int	simulation_start(unsigned int nu_philo, t_philosophers *philosophers)
{
	unsigned int	i;
	t_philosophers	*current;
	struct timeval	simulation_start_time;

	i = 0;
	gettimeofday(&simulation_start_time, NULL);
	printf("0000: simulation started\n");
	while (i < nu_philo)
	{
		current = philosophers + i;
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
