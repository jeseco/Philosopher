/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:41:16 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/20 12:21:06 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include "../../includes/philo.h"
#include "../../includes/utils/utils.h"

time_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_sec / 1000));
}

int	exit_clean(t_philosophers *philosopher)
{
	free (philosopher);
	return (0);
}
