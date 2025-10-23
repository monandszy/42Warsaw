/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:24:21 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/23 16:38:07 by sandrzej         ###   ########.fr       */
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
		if (pobj->is_null != 1 && pobj->precision >= 0)
			if (apply_precision(pobj))
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

int	deminus_content(t_pobj *pobj)
{
	char	*new_content;

	new_content = ft_strdup(pobj->content + 1);
	if (!new_content)
		return (1);
	free(pobj->content);
	pobj->content = new_content;
	pobj->len = pobj->len - 1;
	return (0);
}

char	*create_prefix(t_pobj *pobj)
{
	char	*prefix;
	char	sign;

	prefix = NULL;
	sign = 0;
	if (ft_strchr("di", pobj->specifier))
	{
		if (pobj->content[0] == '-')
		{
			sign = '-';
			if (deminus_content(pobj))
				return (NULL);
		}
		else
		{
			if (pobj->plus_padding == 1)
				sign = '+';
			if (pobj->spc_padding == 1)
				sign = ' ';
		}
		if (sign != 0)
		{
			prefix = (char *)malloc(sizeof(char) * (2));
			if (!prefix)
				return (NULL);
			prefix[0] = sign;
			prefix[1] = '\0';
			ft_strlcpy(prefix, &sign, 2);
		}
	}
	else if (pobj->alt_type == 1 && ft_strchr("xX", pobj->specifier)
		&& (pobj->len != 1 || pobj->content[0] != '0'))
	{
		prefix = (char *)malloc(sizeof(char) * (3));
		if (!prefix)
			return (NULL);
		prefix[0] = '0';
		prefix[1] = pobj->specifier;
		prefix[2] = '\0';
	}
	return (prefix);
}

// Edge case: Precision of 0 for a value of 0 results in an empty string.
// e.g., printf("%.0d", 0) prints nothing.
// If the precision is less than or equal to the current length, do nothing.
int	apply_numeric_precision(t_pobj *pobj)
{
	size_t	zeros_to_add;
	char	*new_content;

	if (pobj->precision == 0 && pobj->content[0] == '0')
	{
		free(pobj->content);
		pobj->content = ft_strdup("");
		if (!pobj->content)
			return (1);
		pobj->len = 0;
		return (0);
	}
	if ((size_t)pobj->precision <= pobj->len)
		return (0);
	zeros_to_add = pobj->precision - pobj->len;
	new_content = (char *)malloc(sizeof(char) * (pobj->precision + 1));
	if (!new_content)
		return (1);
	ft_memset(new_content, '0', zeros_to_add);
	ft_memcpy(new_content + zeros_to_add, pobj->content, pobj->len);
	new_content[pobj->precision] = '\0';
	free(pobj->content);
	pobj->content = new_content;
	pobj->len = pobj->precision;
	return (0);
}

int	apply_string_precision(t_pobj *pobj)
{
	char	*new_content;

	if ((size_t)pobj->precision >= pobj->len)
		return (0);
	new_content = (char *)malloc(sizeof(char) * (pobj->precision + 1));
	if (!new_content)
		return (1);
	ft_memcpy(new_content, pobj->content, pobj->precision);
	new_content[pobj->precision] = '\0';
	free(pobj->content);
	pobj->content = new_content;
	pobj->len = pobj->precision;
	return (0);
}

// For other specifiers like 'c', '%', 'p', precision is ignored.
int	apply_precision(t_pobj *pobj)
{
	char	s;

	if (pobj->precision < 0)
		return (0);
	s = pobj->specifier;
	if (ft_strchr("diuoxX", s))
		return (apply_numeric_precision(pobj));
	else if (s == 's')
	{
		return (apply_string_precision(pobj));
	}
	return (0);
}
