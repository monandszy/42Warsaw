/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:09:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/13 13:09:49 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paired_philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

long long	ft_altoi(char *i)
{
	long long	value;
	long long	c;

	value = 0;
	c = 0;
	while (i[c])
	{
		if (!ft_isdigit(i[c]))
			return (-1);
		value *= 10;
		value += (i[c] - '0');
		c++;
	}
	return (value);
}
