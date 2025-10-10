/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:24:21 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/10 18:24:23 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
convert to string
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
t_list	**process_flags(char *format, va_list args, t_list **master)
{
	/*  char **i;
		if (!master)
			return (NULL);
		i = master;
		while (*i)
		{
			f = find_target(f);
			if (f == NULL)
				return (master);
			i++;
		}
		return (master); */
	return (master);
}
