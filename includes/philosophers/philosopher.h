/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:44:04 by jcourtem          #+#    #+#             */
/*   Updated: 2022/11/08 10:44:49 by jeseco           ###   ########.fr       */
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
	bool			objective_completed;
	t_args			args;
	unsigned int	target_num_meal;
	unsigned int	meal_eaten;
	time_t			last_meal;
	time_t			time_to_think;
	time_t			time_to_hunger;
	time_t			*simulation_start_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t		life;	
	pthread_t		routine;
	t_State			state;
}	t_philosophers;

struct s_philosophers	*init_philosophers(t_args args, bool *simulation_run, \
										time_t *simulation_start_time, \
										pthread_mutex_t *forks);

void					*philo_routine(void *philo);

void					check_state(struct s_philosophers *philo);

void					philo_think(t_philosophers *philo);

void					philo_sleep(t_philosophers *philo);

void					philo_eat(t_philosophers *philo);

#endif
