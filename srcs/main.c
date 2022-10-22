/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:56 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/21 09:46:36 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include "../includes/simulation/simulation.h"

int	usage(void)
{
	printf("USAGE: ./philosopher [number_of_philo] [time_to_die] [time_to_eat] [time_to_sleep]\
			| OPTIONAL: [number_of_meal]\n");
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_args	args;

	if (argc != 5 && argc != 6)
	{
		return (usage());
	}
	args = parse(argc, argv);
	simulation(args);
	return (0);
}
