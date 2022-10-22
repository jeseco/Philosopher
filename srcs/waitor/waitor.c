/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:52:20 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/21 10:13:19 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include "../../includes/waitor/waitor.h"
#include "../../includes/philosophers/philosopher.h"
#include "../../includes/utils/utils.h"

void	*waitor(void *philosophers)
{
	unsigned int	i;
	t_philosophers	*philos;
	bool			*sim_run;

	i = 0;
	philos = philosophers;
	sim_run = philos->simulation_run;
	while (sim_run)
	{
		if (!(philos[i].alive))
		{
			printf("%ld: Death of philosopher_%d!\n", \
			get_current_time() - *(philos->simulation_start_time), \
			philos[i].name);
			sim_run = false;
		}
		i++;
		if (i == philos->nu_philos)
			i = 0;
	}
	return (NULL);
}
