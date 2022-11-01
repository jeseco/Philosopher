/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:41:16 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/23 23:32:18 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

#include "../../includes/philo.h"
#include "../../includes/utils/utils.h"

time_t	get_current_time(void)
{
	pthread_mutex_t	lock;
	struct timeval	tv;

	pthread_mutex_init(&lock, NULL);
	pthread_mutex_lock(&lock);
	gettimeofday(&tv, NULL);
	pthread_mutex_unlock(&lock);
	pthread_mutex_destroy(&lock);
	return ((tv.tv_sec * 1000) + (tv.tv_usec % 1000));
}

int	exit_clean(t_philosophers *philosopher)
{
	free (philosopher);
	return (0);
}
