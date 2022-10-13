/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:48 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/13 15:23:07 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../../includes/philo.h"

void think();

void sleep();

void eat();

struct s_state	check_state(struct s_self self)
{
	/*check wheter the philo is still alive
		if philo is still alive, check if philo is hungry
		return (self)
	*/	
}

void	philo_routine(struct s_args args)
{
	struct s_self self;

	while (self.state.alive)
	{
		self.state = check_state(self);
		if (!self.state.alive)
			return (notifiy_waitor(self));
		if (self.state.hungry)
			eat();
	}
}