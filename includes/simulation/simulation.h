/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:28:02 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/18 13:48:43 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "../includes/parsing/parsing.h"
# include "../includes/philosophers/philosopher.h"

int	simulation(t_args args);

int	create_life(t_philosophers *philosoher);

int	simulation_start(unsigned int nu_philo, t_philosophers *philosopher);

#endif