/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:49:45 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/13 14:19:12 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <string.h>

# include "../philosopher.h"
# include "ft_isdigit.h"
# include "ft_atol.h"

struct s_args {
	int nu_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_meal;
};	

struct s_args parse(int argc, char **argv);

#endif
