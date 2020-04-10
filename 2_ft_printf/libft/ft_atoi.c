/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <mihykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 00:34:37 by mihykim           #+#    #+#             */
/*   Updated: 2020/03/17 00:34:58 by mihykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char **str)
{
	int		atoi;

	atoi = 0;
	if (!is_set(**str, DIGIT))
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		atoi = atoi * 10 + (**str - '0');
		(*str)++;
	}
	return (atoi);
}