/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:19:18 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/14 15:19:01 by jcourtem         ###   ########.fr       */
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
    t_philosophers  *philosophers;

    generated_philo = 1;
    gettimeofday(&simulation_start_time, NULL);
    printf("Simulation start. There is %d Philosophers\n", args.nu_philo);
    philosophers = init_philosophers();
    waitor(philosophers);
}