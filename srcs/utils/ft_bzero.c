/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:27:33 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2022/10/18 10:46:46 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils/utils.h"
#include "../includes/utils/ft_bzero.h"

void	ft_bzero(void *str, size_t n)
{
	char	*pt_str;

	pt_str = str;
	while (n-- > 0)
		*pt_str++ = '\0';
}
