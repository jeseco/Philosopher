/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:28:02 by jeseco            #+#    #+#             */
/*   Updated: 2022/11/07 23:59:05 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <time.h>

# include "../includes/parsing/parsing.h"
# include "../includes/philosophers/philosopher.h"

int	simulation(t_args args);

int	create_life(void *philosoher);

int	simulation_start(t_philosophers *philosopher, \
					time_t *simulation_start_time);

#endif