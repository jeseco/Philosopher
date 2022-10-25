/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:51:21 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/25 15:47:10 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h" 
#include "../../includes/parsing/parsing.h"
#include "../../includes/parsing/ft_atol.h"
#include "../../includes/parsing/ft_isdigit.h"

int	check_arg_is_num(char *str)
{
	int	i;
	int	current;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			current = str[i];
			if (!ft_isdigit(current))
				return (0);
			i++;
		}
	}
	return (ft_atol(str));
}

bool	check_args(struct s_args args)
{
	if (!args.nu_philo)
		return (false);
	else if (!args.time_to_die)
		return (false);
	else if (!args.time_to_eat)
		return (false);
	else if (!args.time_to_sleep)
		return (false);
	return (true);
}

t_args	parse(int argc, char **argv)
{
	struct s_args	args;

	args.nu_philo = check_arg_is_num(argv[1]);
	args.time_to_die = check_arg_is_num(argv[2]);
	args.time_to_eat = check_arg_is_num(argv[3]);
	args.time_to_sleep = check_arg_is_num(argv[4]);
	if (argc == 6)
	{
		args.number_of_meal = check_arg_is_num(argv[5]);
		if (args.number_of_meal == 0)
		{
			printf("Error: optional argument {number_of_meal} cannot be '0'\n");
			args.error = true;
			return (args);
		}
	}
	else
		args.number_of_meal = 0;
	return (args);
}
