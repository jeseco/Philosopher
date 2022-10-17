/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 03:46:58 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/17 03:47:40 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	philo_think(t_philosophers *philo)
{
	philo->state = thinking;
	while (philo->alive && philo->state != hungry)
	{
		philo->state = check_state(philo);
		usleep(9 * 1000);
		philo->time_from_last_meal += 9;
	}
	usleep(philo->time_to_think);
	philo->state = thinking;
}

void	philo_sleep(t_philosophers *philo)
{
	philo->state = sleeping;
	usleep(philo->time_to_sleep);
}

void	philo_eat(t_philosophers *philo)
{
	usleep(philo->time_to_eat);
}

void	philo_routine(t_philosophers *philo)
{
	while (philo->alive)
	{
		philo->state = check_state(philo);
		if (philo->state == hungry)
		{
			philo_eat(philo);
			philo_sleep(philo);
		}
	}
}