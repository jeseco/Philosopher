/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:52:20 by jeseco            #+#    #+#             */
/*   Updated: 2022/11/09 16:01:44 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include "../../includes/waitor/waitor.h"
#include "../../includes/philosophers/philosopher.h"
#include "../../includes/utils/utils.h"

bool	objective_completed(t_philosophers *philos)
{
	unsigned int	i;

	i = 0;
	while (i < philos->args.nu_philo)
	{
		if (!(philos[i].objective_completed))
			return (false);
		i++;
	}
	return (true);
}

void	*waitor(void *philosophers)
{
	unsigned int	i;
	t_philosophers	*philos;
	bool			*sim_run;

	i = 0;
	philos = philosophers;
	sim_run = philos->simulation_run;
	while (sim_run && !(objective_completed(philos)))
	{
		if (!(philos[i].alive))
		{
			printf("\033[0;31m%ld Philosopher_%d died!\033[0m\n", \
			get_current_time() - *(philos->simulation_start_time), \
			philos[i].name);
			sim_run = false;
		}
		i++;
		if (objective_completed(philos))
			return (NULL);
		if (i == philos->args.nu_philo)
			i = 0;
	}
	return (NULL);
}
