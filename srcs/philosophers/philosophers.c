/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:48 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/17 03:48:40 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../../includes/philo.h"
#include "../../includes/philosophers/philosopher.h"
#include "../../includes/utils/utils.h"

enum e_state	life(t_philosophers *philo)
{
	while (philo->alive)
	{
		if (philo->time_from_last_meal >= time_to_die)
		{
			philo->alive = false;
		}
	}
}

struct s_philosophers	*init_philosophers(int num_philo)
{
	int				i;
	t_philosophers	*philosophers;
	t_philosophers	*current;

	i = 1;
	if (!(philosophers = ft_calloc(num_philo, sizeof(t_philosophers))))
		return (clean_exit());
	current = philosophers;
	while (i <= num_philo)
	{
		current->name = i;
		current->state = thinking;
		i++;
	}
}
