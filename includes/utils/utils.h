/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:45:18 by jcourtem          #+#    #+#             */
/*   Updated: 2022/11/03 20:17:20 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/philo.h"

void	*ft_calloc(size_t count, size_t size);

int		exit_clean(t_philosophers *philosopher);

time_t	get_current_time(void);

#endif