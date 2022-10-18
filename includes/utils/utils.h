/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:45:18 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/18 13:47:06 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes/philo.h"

void	*ft_calloc(size_t count, size_t size);

int		exit_clean(t_philosophers *philosopher);

int		get_current_time(void);

#endif