/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:59:32 by khou              #+#    #+#             */
/*   Updated: 2019/02/01 15:39:45 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_nbrlen(uintmax_t nbr)
{
	int len;

	len = 0;
	if (nbr == 0)
		len = 1;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
