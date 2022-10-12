/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:56 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/11 14:16:58 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	usage()
{
	printf("USAGE: ./philosopher [number_of_philo] [time_to_die] [time_to_eat] [time_to_sleep] | OPTIONAL: [number_of_meal]\n");
	return (0);
}

void	sim(struct s_args *args, struct timeval *sim_start) 
{/*TODO:
	- [ ] init_waitor
	- [ ] init_philos
	- [ ] start_sim
*/ 

	(void) args;
	(void) sim_start;
}

int main(int argc, char **argv)
{
	struct s_args	*args;
	struct timeval	*sim_start = NULL;

	if (argc != 5 && argc != 6){
		return (usage());
	}
	args = parse(argc, argv);
	if (gettimeofday(sim_start, NULL) != 0) {
		printf("Error getting time of days\n");
		return (0);
	}
	sim(args, sim_start);
	return (0);
}
