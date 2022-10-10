/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:03:21 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2022/10/08 17:17:40 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing/ft_isdigit.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
