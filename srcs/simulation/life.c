/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:58:12 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/18 14:00:31 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <sys/_pthread/_pthread_t.h>
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

	philo = philosopher;
	printf("Birth of philosopher_%d\n", philo->name);
	pthread_create(philo->routine, NULL, philo_routine, philo);
	while (philo->alive)
	{
		current_time = get_current_time();
		if (current_time - philo->last_meal >= philo->time_to_die)
		{
			philo->alive = false;
			printf("Death of philosopher_%d\n", philo->name);
			return (NULL);
		}
		else if (current_time - philo->last_meal >= philo->time_to_hunger)
		{
			philo->state = HUNGRY;
		}
	}
	return (NULL);
}
