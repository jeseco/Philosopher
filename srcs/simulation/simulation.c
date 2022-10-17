/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:19:18 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/17 03:58:17 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include "../../includes/philo.h"
#include "../../includes/parsing/parsing.h"
#include "../../includes/simulation/simulation.h"
#include "../../includes/waitor/waitor.h"
#include "../../includes/philo/philosopher.h"

void    simulation(t_args args)
{
    struct timeval  simulation_start_time;
    // unsigned int    generated_philo;
    t_philosophers  *philosophers;

    // generated_philo = 1;
    gettimeofday(&simulation_start_time, NULL);
    printf("Simulation start. There is %d Philosophers\n", args.nu_philo);
    philosophers = init_philosophers(args.nu_philo);
    waitor(philosophers);
}