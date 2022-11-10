/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:19:18 by jeseco            #+#    #+#             */
/*   Updated: 2022/11/09 13:22:46 by jeseco           ###   ########.fr       */
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
	time_t			sim_start_time;
	t_philosophers	*philo;

	philo = philosopher;
	life_tid = philo->life;
	sim_start_time = *(philo->simulation_start_time);
	philo->last_meal = get_current_time() - sim_start_time;
	pthread_create(&life_tid, NULL, life, philo);
	pthread_detach(life_tid);
	return (0);
}

int	simulation_start(t_philosophers *philosophers, \
					time_t *simulation_start_time)
{
	unsigned int	i;
	t_philosophers	*current;

	i = 0;
	printf("0: Simulation started\n");
	*simulation_start_time = get_current_time();
	while (i < philosophers->args.nu_philo && philosophers->simulation_run)
	{
		current = philosophers + i;
		create_life(current);
		i++;
	}
	return (0);
}

void	set_the_table(t_args reservation, pthread_mutex_t *forks)
{
	unsigned int	i;

	i = 0;
	while (i < reservation.nu_philo)
	{
		pthread_mutex_init(forks + i, NULL);
		i++;
	}
}

void	clean_table(t_args reservation, pthread_mutex_t *forks)
{
	unsigned int	i;

	i = 0;
	while (i < reservation.nu_philo)
	{
		pthread_mutex_destroy(forks + i);
		i++;
	}
	free (forks);
}

int	simulation(t_args reservation)
{
	t_philosophers	*philosophers;
	pthread_mutex_t	*forks;
	pthread_t		waitor_tid;
	time_t			simulation_start_time;
	bool			simulation_run;

	forks = ft_calloc(sizeof(pthread_mutex_t) * reservation.nu_philo, 1);
	set_the_table(reservation, forks);
	philosophers = init_philosophers(reservation, &simulation_run, \
									&simulation_start_time, forks);
	if (!philosophers)
		return (exit_clean(philosophers));
	simulation_run = true;
	pthread_create(&waitor_tid, NULL, waitor, philosophers);
	simulation_start(philosophers, &simulation_start_time);
	pthread_join(waitor_tid, NULL);
	clean_table(reservation, forks);
	return (0);
}
