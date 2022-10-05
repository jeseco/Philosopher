/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:51:21 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/05 14:14:04 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

struct s_args	parse(int argc, char **argv)
{
	struct s_args args;

	args.nu_philo = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	
	if (argc == 6)
		args.number_of_meal = ft_atoi(argv[5]);
	else
		args.number_of_meal = 0;	
	return (args);
}