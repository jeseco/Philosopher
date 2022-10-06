/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:56 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/06 13:17:22 by jcourtem         ###   ########.fr       */
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
	struct s_args	args;
	struct timeval	*sim_start = NULL;
	
	if (argc != 5 && argc != 6){
		return (usage());
	}
	args = parse(argc, argv);
	if (gettimeofday(sim_start, NULL) != 0) {
		printf("Error getting time of days\n");
		return (0);
	}
	// sim(args, sim_start);
	return (0);
}