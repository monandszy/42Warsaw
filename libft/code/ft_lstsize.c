/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:07:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/04 14:09:03 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	unsigned int i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst -> next != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
} 
