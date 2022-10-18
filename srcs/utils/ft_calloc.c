/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:23:10 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2022/10/17 11:49:54 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils/ft_calloc.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	ft_bzero(ptr, count * size);
	return (ptr);
}
	