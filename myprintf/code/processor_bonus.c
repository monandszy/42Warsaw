/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:24:21 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/23 16:55:40 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
[v]	convert to string
	apply precision || width
	if (num)
		apply plus padding
		apply if(x) alt_type
	apply width&if(num) zero ||
	apply justification

flag processing
all: - w
s: .
c:(.?)
p: (.?)
di: + ' ' 0 .
u: 0 .
xX: 0 # .
%: none
other: ?

width processing
(padding after - or +)

precision processing
diuxX - max num of digits, pads with 0
s - truncation
(applied only to original arg)
*/

//#include <stdio.h>

// printf("[content: %s]\n", pobj -> content);
// printf("[len: %zu]\n", pobj -> len);
// printf("[specifier: %c]\n", pobj -> specifier);
// printf("[justification: %d]\n", pobj -> justification);
// printf("[width: %ld]\n", pobj -> width);
// printf("[precision: %d]\n", pobj -> precision);
// printf("[zero_padding: %d]\n", pobj -> zero_padding);
// printf("[alt_type: %d]\n", pobj -> alt_type);
// printf("[plus_padding: %d]\n", pobj -> plus_padding);
// printf("[spc_padding: %d]\n", pobj -> spc_padding);
// printf("\n");
// printf("[prefix: [%s]]\n", prefix);
int	process_subflags(t_list **master)
{
	t_list	*i;

	i = *master;
	while (i)
	{
		if (process_pobj((t_pobj *)i->content))
			return (1);
		i = i->next;
	}
	return (0);
}

int	process_pobj(t_pobj *pobj)
{
	char	*prefix;

	prefix = create_prefix(pobj);
	if (handle_precision(pobj))
	{
		free(prefix);
		return (1);
	}
	if (assemble_output(pobj, prefix))
	{
		free(prefix);
		return (1);
	}
	free(prefix);
	return (0);
}

int	handle_null_precision(t_pobj *pobj)
{
	if (pobj->is_null == 1 && pobj->precision < 6)
	{
		free(pobj->content);
		pobj->content = ft_strdup("");
		if (!pobj->content)
			return (1);
		pobj->len = 0;
	}
	return (0);
}

int	handle_precision(t_pobj *pobj)
{
	if (pobj->precision >= 0)
	{
		if (handle_null_precision(pobj))
			return (1);
		if (apply_precision(pobj))
			return (1);
	}
	return (0);
}
