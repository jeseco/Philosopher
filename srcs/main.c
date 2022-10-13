/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:56 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/13 15:21:54 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	usage()
{
	printf("USAGE: ./philosopher [number_of_philo] [time_to_die] [time_to_eat] [time_to_sleep] | OPTIONAL: [number_of_meal]\n");
	return (0);
}

void	sim(struct s_args args) 
{/*TODO:
	- [ ] init_waitor
	- [ ] init_philos
	- [ ] start_sim
*/ 
	(void) args;
}

int main(int argc, char **argv)
{
	struct s_args	args;

	if (argc != 5 && argc != 6){
		return (usage());
	}
	args = parse(argc, argv);
	sim(args);
	return (0);
}
