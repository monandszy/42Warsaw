/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:24:21 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/13 15:12:43 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
[v]	convert to string
	apply precision | width
	if (num)
		apply plus padding
		apply if(x) alt_type
	apply width&if(num) zero |
	apply justification

flag processing
all: -
csp:
di: + ' ' 0
u: 0
xX: 0 #
%: none
other: ?

width processing
(padding after - or +)

precision processing
diuxX - max num of digits, pads with 0
s - truncation
(applied only to original arg)
*/
int process_flags(char *format, va_list args, t_list **master)
{
/*	t_pobj *tmp;
	t_list *i;

	i = *master;
	while(i)
	{
		tmp = (t_pobj *) i -> content;
		if (tmp -> precision)
		{
		}
		else if (tmp -> width)
		{
		}
		if (ft_strchr("diu", tmp -> specifier))
		{
			if (tmp -> plus_padding)
			if (tmp -> spc_padding)
			if (tmp -> precision && tmp -> width)
				// width
		}
		else if (ft_strchr("xX", tmp -> specifier))
		{
			if (tmp -> alt_type)
			if (tmp -> precision && tmp -> width)
				// width
		}
		if (tmp -> justification)
		{
		}
		i = i -> next;
	} */
	return (0); 
}
