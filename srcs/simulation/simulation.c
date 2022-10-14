/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:19:18 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/14 08:56:27 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include "../../includes/philo.h"
#include "../../includes/parsing/parsing.h"
#include "../../includes/simulation/simulation.h"
#include "../../includes/waitor/waitor.h"

void    simulation(t_args args)
{
    struct timeval  simulation_start_time;
    unsigned int    generated_philo;

    gettimeofday(&simulation_start_time, NULL)
    printf("Simulation start. There is %d Philosophers\n", args.nu_philo);
    init_waitor();
    while (generated_philo <= args.nu_philo)
}