/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:24:21 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/23 16:55:40 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	assemble_output(t_pobj *pobj, char *prefix)
{
	t_lengths	lengths;
	char		*output_str;

	lengths.prefix = ft_better_stlen_questionmark(prefix);
	lengths.payload = lengths.prefix + pobj->len;
	if (pobj->width >= 0 && (size_t)pobj->width > lengths.payload)
		lengths.final = pobj->width;
	else
		lengths.final = lengths.payload;
	lengths.padding = lengths.final - lengths.payload;
	output_str = (char *)malloc(sizeof(char) * (lengths.final + 1));
	if (!output_str)
		return (1);
	lengths.pad_char = get_padding_char(pobj);
	if (pobj->justification == 1)
		build_left_justified(pobj, prefix, &lengths, output_str);
	else
		build_right_justified(pobj, prefix, &lengths, output_str);
	output_str[lengths.final] = '\0';
	free(pobj->content);
	pobj->content = output_str;
	pobj->len = lengths.final;
	return (0);
}

char	get_padding_char(t_pobj *pobj)
{
	if (pobj->zero_padding == 1 && pobj->justification != 1
		&& pobj->precision < 0 && ft_strchr("diuoxX", pobj->specifier))
	{
		return ('0');
	}
	return (' ');
}

void	build_left_justified(t_pobj *pobj, char *prefix, t_lengths *lengths,
		char *output_str)
{
	char	*ptr;
	char	pad_char;

	ptr = output_str;
	pad_char = lengths->pad_char;
	ft_memcpy(ptr, prefix, lengths->prefix);
	ptr += lengths->prefix;
	ft_memcpy(ptr, pobj->content, pobj->len);
	ptr += pobj->len;
	ft_memset(ptr, pad_char, lengths->padding);
}

void	build_right_justified(t_pobj *pobj, char *prefix, t_lengths *lengths,
		char *output_str)
{
	char	*ptr;
	char	pad_char;

	ptr = output_str;
	pad_char = lengths->pad_char;
	if (pad_char == '0')
	{
		ft_memcpy(ptr, prefix, lengths->prefix);
		ptr += lengths->prefix;
		ft_memset(ptr, pad_char, lengths->padding);
		ptr += lengths->padding;
		ft_memcpy(ptr, pobj->content, pobj->len);
	}
	else
	{
		ft_memset(ptr, pad_char, lengths->padding);
		ptr += lengths->padding;
		ft_memcpy(ptr, prefix, lengths->prefix);
		ptr += lengths->prefix;
		ft_memcpy(ptr, pobj->content, pobj->len);
	}
}

size_t	ft_better_stlen_questionmark(char *s)
{
	if (s)
		return (ft_strlen(s));
	else
		return (0);
}
