/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 03:46:58 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/18 14:04:30 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/philosophers/philosopher.h"

void	philo_think(t_philosophers *philo)
{
	philo->state = THINKING;
	while (philo->alive && philo->state != HUNGRY)
	{
		usleep(9 * 1000);
		philo->last_meal += 9;
	}
	usleep(philo->time_to_think);
	philo->state = THINKING;
}

void	philo_sleep(t_philosophers *philo)
{
	philo->state = SLEEPING;
	usleep(philo->time_to_sleep);
}

void	philo_eat(t_philosophers *philo)
{
	usleep(philo->time_to_eat);
}

void	*philo_routine(void *philosopher)
{
	t_philosophers	*self;

	self = philosopher;
	while (self->alive)
	{
		if (self->state == HUNGRY)
		{
			philo_eat(self);
			philo_sleep(self);
		}
	}
	return (NULL);
}
