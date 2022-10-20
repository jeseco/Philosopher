/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 03:46:58 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/20 12:12:19 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/philosophers/philosopher.h"
#include "../includes/utils/utils.h"

void	philo_think(t_philosophers *philo)
{
	philo->state = THINKING;
	while (philo->alive && philo->state != HUNGRY && philo->simulation_run)
		usleep(10 * 1000);
}

void	philo_sleep(t_philosophers *philo)
{
	time_t	sleeping_start_time;

	philo->state = SLEEPING;
	sleeping_start_time = get_current_time();
	while (philo->alive && philo->simulation_run && \
	((get_current_time() - sleeping_start_time) != philo->time_to_sleep))
		usleep(10 * 1000);
}

void	philo_eat(t_philosophers *philo)
{
	time_t	eating_start_time;

	while (philo->alive && philo->simulation_run)
	{
		if (philo->r_fork && philo->l_fork)
		{
			eating_start_time = get_current_time();
			while (get_current_time() - eating_start_time != philo->time_to_eat)
				usleep(10 * 1000);
		}
	}
	philo->last_meal = get_current_time();
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
