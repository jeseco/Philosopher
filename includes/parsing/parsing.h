/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:49:45 by jcourtem          #+#    #+#             */
/*   Updated: 2022/11/03 20:43:58 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdbool.h>
# include <string.h>
# include <time.h>

# include "ft_isdigit.h"
# include "ft_atol.h"

typedef struct s_args {
	time_t			nu_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	unsigned long	number_of_meal;
	bool			error;
}	t_args;	

t_args	parse(int argc, char **argv);

#endif
