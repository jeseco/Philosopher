/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:56 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/08 16:29:14 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	usage()
{
	printf("USAGE: ./philosopher [number_of_philo] [time_to_die] [time_to_eat] [time_to_sleep] | OPTIONAL: [number_of_meal]\n");
	return (0);
}

// void	sim(struct s_args args, struct timeval *sim_start); // TODO [ ]

int main(int argc, char **argv)
{
	// struct s_args	args;
	struct timeval	*sim_start = NULL;

	(void)argv;
	(void)argc;
	
	if (argc != 5 && argc != 6){
		return (usage());
	}
	// args = parse(argc, argv);
	if (gettimeofday(sim_start, NULL) != 0) {
		printf("Error getting time of days\n");
		return (0);
	}
	// sim(args, sim_start);
	return (0);
}
