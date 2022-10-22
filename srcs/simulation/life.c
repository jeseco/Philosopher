/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:58:12 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/21 15:00:53 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <time.h>

#include "../../includes/philosophers/philosopher.h"
#include "../../includes/simulation/life.h"
#include "../../includes/utils/utils.h"

extern void	*life(void *philosopher)
{
	time_t			current_time;
	t_philosophers	*philo;
	pthread_t		routine_tid;

	philo = philosopher;
	routine_tid = philo->routine;
	pthread_create(&routine_tid, NULL, philo_routine, philo);
	while (philo->simulation_run && philo->alive)
	{
		current_time = get_current_time();
		if ((current_time - philo->last_meal) >= \
			(philo->last_meal + philo->time_to_die))
		{
			philo->alive = false;
			return (NULL);
		}
		else if (current_time - philo->last_meal >= philo->time_to_hunger && \
				philo->state != EATING)
		{
			philo->state = HUNGRY;
		}
	}
	return (NULL);
}
