/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:44:04 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/18 14:01:22 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdbool.h>

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
	int				name;
	bool			alive;
	bool			*simulation_run;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	last_meal;
	unsigned long	time_to_think;
	unsigned long	time_to_hunger;
	pthread_t		*life;	
	pthread_t		*routine;
	t_State			state;
}	t_philosophers;

struct s_philosophers	*init_philosophers(t_args args, bool *simulation_run);

void					*philo_routine(void *philo);

void					check_state(struct s_philosophers *philo);

void					philo_think(t_philosophers *philo);

void					philo_sleep(t_philosophers *philo);

void					philo_eat(t_philosophers *philo);

#endif
