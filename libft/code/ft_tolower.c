/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:23:59 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/23 19:33:20 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isupper(int c);

#include "libft.h"

int ft_tolower(int c)
{
	if (ft_isupper(c))
	{
		return (c + ' ');
	}
	else
	{
		return (c);
	}
}

int ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
