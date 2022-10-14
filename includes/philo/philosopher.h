/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:44:04 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/13 16:54:34 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "../parsing/parsing.h"

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

void	philo_routine(t_args args);

#endif
