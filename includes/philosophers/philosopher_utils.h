/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:33:47 by jeseco            #+#    #+#             */
/*   Updated: 2022/11/08 11:37:26 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_UTILS_H
# define PHILOSOPHER_UTILS_H

# include "philosopher.h"

void	take_fork(t_philosophers *philo);

void	drop_fork(t_philosophers *philo);

#endif