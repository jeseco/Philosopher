/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:44:04 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/17 03:44:25 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include "../parsing/parsing.h"
# include "pthread.h"

typedef enum e_HandPreference
{
	RIGHT,
	LEFT
}	t_handPref;

typedef enum e_State
{
	HUNGRY,
	EATING,
	SLEEPING,
	THINKING
}	t_State;

typedef struct s_philosophers
{
	char			*name;
	bool			alive;
	unsigned float	hunger;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_from_last_meal;
	unsigned long	time_to_think;
	unsigned long	time_to_hunger;
	pthread_t		life;	
	pthread_t		routine;
	t_State			state;
}	t_philosophers;

struct s_philosophers	*init_philosophers(int num_philo);

void					philo_routine(struct s_philosophers *philo);

enum e_State			check_state(struct s_philosophers *self);

void					philo_think(t_philosophers *philo);

void					philo_sleep(t_philosophers *philo);

void					philo_eat(t_philosophers *philo);

#endif
