/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:49:45 by jcourtem          #+#    #+#             */
/*   Updated: 2022/10/17 03:31:31 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <string.h>

# include "ft_isdigit.h"
# include "ft_atol.h"

typedef struct s_args {
	unsigned int	nu_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	number_of_meal;
}	t_args;	

t_args	parse(int argc, char **argv);

#endif
