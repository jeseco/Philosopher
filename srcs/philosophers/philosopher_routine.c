/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 03:46:58 by jeseco            #+#    #+#             */
/*   Updated: 2022/11/09 16:00:26 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/waitor/waitor.h"
#include "../includes/philosophers/philosopher.h"
#include "../includes/philosophers/philosopher_utils.h"
#include "../includes/utils/utils.h"

void	philo_think(t_philosophers *philo)
{
	philo->state = THINKING;
	if (philo->alive && philo->simulation_run && philo->state != HUNGRY)
	{
		printf("%ld Philosopher_%d is thinking\n", \
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
		printf("%ld Philosopher_%d is sleeping\n", \
			get_current_time() - *(philo->simulation_start_time), \
			philo->name);
		while (philo->alive && philo->simulation_run && \
		((get_current_time() - sleeping_start_time) < \
		philo->args.time_to_sleep))
			usleep(1);
	}
}

void	philo_eat(t_philosophers *philo)
{
	time_t	eating_start_time;

	if (philo->alive && philo->simulation_run)
	{
		take_fork(philo);
		philo->state = EATING;
		printf("%ld Philosopher_%d is eating\n", \
			get_current_time() - *(philo->simulation_start_time), \
			philo->name);
		eating_start_time = get_current_time();
		while (get_current_time() - eating_start_time < philo->args.time_to_eat)
			usleep(5);
	}
	drop_fork(philo);
	philo->last_meal = get_current_time() - *(philo->simulation_start_time);
	philo->meal_eaten += 1;
	if (philo->meal_eaten == philo->target_num_meal)
		philo->objective_completed = true;
}

void	*philo_routine(void *philosopher)
{
	t_philosophers	*self;

	self = philosopher;
	while (self->alive && self->simulation_run && !(self->objective_completed))
	{
		if (self->state == HUNGRY && !(self->objective_completed))
		{
			philo_eat(self);
			if (!(self->objective_completed) && self->simulation_run)
				philo_sleep(self);
		}
		else if (self->alive && self->simulation_run && \
		!(self->objective_completed))
			philo_think(self);
	}
	return (NULL);
}
