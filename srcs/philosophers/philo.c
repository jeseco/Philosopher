/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:48 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/14 15:22:31 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../includes/philo.h"

void think();

void sleep();

void eat();

void	philo_routine(struct t_philosophers *philo)
{
	pthread_t		tid;
	t_philosophers	*self;

	self = philo;
	while(self->state) {
		self->state = self_state_check(self);
		if (self->state == hungry)
			eat();	
			sleep();
	}
}

enum state check_state(struct t_philosophers *self, t_args *args)
{
	/*check wheter the philo is still alive
		if philo is still alive, check if philo is hungry
		return (self)
	*/	
}

t_philosophers *init_philosophers(int num_philo)
{
	int	i;
	t_philosophers 	*philosophers;
	t_philosophers	*current;

	i = 1;
	if (!(philosophers = ft_calloc(num_philo, sizeof(t_philosophers))))
		return (clean_exit());
	current = philosophers;
	while (i <= num_philo)
	{
		current->name = i;
		current->state = thinking;
		current->alive = true;
		current++;
		i++;
	}
}
