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
	t_pobj	*pobj;
	char	*prefix;

	i = *master;
	while (i)
	{
		pobj = (t_pobj *)i->content;
		prefix = create_prefix(pobj);
		if (pobj->precision >= 0)
		{
			if (pobj->is_null == 1 && pobj->precision < 6)
			{
				free(pobj->content);
				pobj->len = 0;
				pobj->content = ft_strdup("");
				if (!pobj->content)
					return (1);
			}
			if (apply_precision(pobj))
			{
				free(prefix);
				return (1);
			}
		}
		if (assemble_output(pobj, prefix))
		{
			free(prefix);
			return (1);
		}
		free(prefix);
		i = i->next;
	}
	return (0);
}

int	assemble_output(t_pobj *pobj, char *prefix)
{
	size_t	prefix_len;
	size_t	payload_len;
	size_t	padding_len;
	size_t	final_len;
	char	pad_char;
	char	*output_str;
	char	*i;

	if (prefix != NULL && *prefix != '\0')
		prefix_len = ft_strlen(prefix);
	else
		prefix_len = 0;
	payload_len = prefix_len + pobj->len;
	if (pobj->width >= 0 && (size_t)pobj->width > payload_len)
		final_len = pobj->width;
	else
		final_len = payload_len;
	padding_len = final_len - payload_len;
	output_str = (char *)malloc(sizeof(char) * (final_len + 1));
	if (!output_str)
		return (1);
	i = output_str;
	pad_char = ' ';
	if (pobj->zero_padding == 1 && pobj->justification != 1
		&& !(pobj->precision >= 0) && ft_strchr("diuoxX", pobj->specifier))
	{
		pad_char = '0';
	}
	if (pobj->justification == 1)
	{
		ft_memcpy(i, prefix, prefix_len);
		i += prefix_len;
		ft_memcpy(i, pobj->content, pobj->len);
		i += pobj->len;
		ft_memset(i, ' ', padding_len);
	}
	else if (pad_char == '0')
	{
		ft_memcpy(i, prefix, prefix_len);
		i += prefix_len;
		ft_memset(i, '0', padding_len);
		i += padding_len;
		ft_memcpy(i, pobj->content, pobj->len);
	}
	else
	{
		ft_memset(i, ' ', padding_len);
		i += padding_len;
		ft_memcpy(i, prefix, prefix_len);
		i += prefix_len;
		ft_memcpy(i, pobj->content, pobj->len);
	}
	output_str[final_len] = '\0';
	free(pobj->content);
	pobj->content = output_str;
	pobj->len = final_len;
	return (0);
}
