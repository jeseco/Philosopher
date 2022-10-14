/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:50 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/14 14:40:17 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

# include "parsing/parsing.h"
# include "simulation/simulation.h"

typedef enum e_state
{
	hungry,
	eating,
	sleeping,
	thinking
}	t_state;

typedef struct s_philosophers
{
	char			*name;
	bool			alive;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	t_state			state;
}	t_philosophers;


int usage();

#endif
