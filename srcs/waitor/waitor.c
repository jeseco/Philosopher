/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:52:20 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/18 14:13:46 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "../../includes/waitor/waitor.h"
#include "../../includes/philosophers/philosopher.h"

void	waitor(t_args args, t_philosophers *philosophers, bool *simulation_run)
{
	unsigned int	i;

	i = 1;
	while (simulation_run && i <= args.nu_philo)
	{
		if (!(philosophers[i].alive))
			simulation_run = false;
		if (i == args.nu_philo)
			i = 1;
	}
}
