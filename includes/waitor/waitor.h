/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:53:03 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/18 12:50:54 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAITOR_H
# define WAITOR_H

# include "../philosophers/philosopher.h"

void	waitor(t_args args, t_philosophers *philosophers, bool *simulation_run);

#endif