/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:44:04 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/13 15:34:40 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <philosopher.h>

typedef struct s_state 
{
	bool alive;
	bool hungry;
	bool sleeping;
	bool thinking;
}	t_state;

typedef struct s_self
{
	struct s_state	state;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
}	t_self;

void	philo_routine(struct s_args args);

#endif
