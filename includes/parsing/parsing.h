/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:49:45 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/11 17:17:37 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "philosopher.h"
# include "ft_isdigit.h"
# include "ft_atol.h"

struct s_args {
	int nu_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_meal;
};	

struct s_args *parse(int argc, char **argv);

#endif