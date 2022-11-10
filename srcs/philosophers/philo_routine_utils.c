/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:32:58 by jeseco            #+#    #+#             */
/*   Updated: 2022/11/09 16:01:06 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers/philosopher_utils.h"
#include "../../includes/waitor/waitor.h"
#include <stdio.h>
#include "../../includes/utils/utils.h"

void	take_fork(t_philosophers *philo)
{
	if (philo->simulation_run && philo->alive)
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%ld Philosopher_%d has taken right fork\n", \
			get_current_time() - *(philo->simulation_start_time), \
			philo->name);
		pthread_mutex_lock(philo->l_fork);
		printf("%ld Philosopher_%d has taken left fork\n", \
			get_current_time() - *(philo->simulation_start_time), \
			philo->name);
	}
}

void	drop_fork(t_philosophers *philo)
{
	if (philo->alive && philo->simulation_run)
	{
		pthread_mutex_unlock(philo->r_fork);
		printf("%ld Philosopher_%d has drop right fork\n", \
			get_current_time() - *(philo->simulation_start_time), \
			philo->name);
		pthread_mutex_unlock(philo->l_fork);
		printf("%ld Philosopher_%d has drop left fork\n", \
			get_current_time() - *(philo->simulation_start_time), \
			philo->name);
	}
}
