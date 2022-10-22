/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 03:46:58 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/21 15:22:00 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/philosophers/philosopher.h"
#include "../includes/utils/utils.h"

void	philo_think(t_philosophers *philo)
{
	philo->state = THINKING;
	if (philo->alive && philo->simulation_run && philo->state != HUNGRY)
	{
		printf("%ld: Philosophers_%d started thinking\n", \
					get_current_time() - *(philo->simulation_start_time), \
					philo->name);
		while (philo->alive && philo->state != HUNGRY && philo->simulation_run)
			usleep(1);
	}
}

void	philo_sleep(t_philosophers *philo)
{
	time_t	sleeping_start_time;

	philo->state = SLEEPING;
	if (philo->alive && philo->simulation_run)
	{
		sleeping_start_time = get_current_time();
		printf("%ld: Philosopher_%d started sleeping\n", \
				get_current_time() - *(philo->simulation_start_time), \
				philo->name);
		while (philo->alive && philo->simulation_run && \
		((get_current_time() - sleeping_start_time) < philo->time_to_sleep))
			usleep(1);
	}
}

void	philo_eat(t_philosophers *philo)
{
	time_t	time_eating;

	time_eating = 0;
	if (philo->alive && philo->simulation_run)
	{
		philo->state = EATING;
		printf("%ld: Philosopher_%d started eating\n", \
			get_current_time() - *(philo->simulation_start_time), \
			philo->name);
		while (time_eating < philo->time_to_eat)
			time_eating += 10;
	}
	philo->last_meal = get_current_time() - *(philo->simulation_start_time);
}

void	*philo_routine(void *philosopher)
{
	t_philosophers	*self;

	self = philosopher;
	while (self->alive && self->simulation_run)
	{
		if (self->state == HUNGRY)
		{
			philo_eat(self);
			philo_sleep(self);
		}
		else
			philo_think(self);
	}
	return (NULL);
}
