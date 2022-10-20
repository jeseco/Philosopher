/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:48 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/20 10:39:23 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "../../includes/philo.h"
#include "../../includes/philosophers/philosopher.h"
#include "../../includes/utils/utils.h"

void	init_fork()
{

}

struct s_philosophers	*init_philosophers(t_args args, bool *simulation_run)
{
	unsigned int	i;
	t_philosophers	*philosophers;
	t_philosophers	*current;

	i = 1;
	philosophers = ft_calloc(args.nu_philo, sizeof(t_philosophers));
	while (i <= args.nu_philo)
	{
		current = philosophers + (i - 1);
		current->name = i;
		current->state = THINKING;
		current->time_to_die = args.time_to_die;
		current->time_to_eat = args.time_to_eat;
		current->time_to_sleep = args.time_to_sleep;
		current->simulation_run = simulation_run;
		i++;
	}
	init_fork();
	return (philosophers);
}
