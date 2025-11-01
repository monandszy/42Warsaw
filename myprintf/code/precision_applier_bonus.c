/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:52:39 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/23 16:52:50 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
