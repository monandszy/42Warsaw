/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:14:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/14 15:05:24 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Each conversion specification is introduced
by the character %, and ends with a conversion specifier.
In between there may be (in this order) zero or more flags, an
optional minimum field width, an optional precision and an
optional length modifier.

[argument$] // not in req
[flags] // # 0 - ' ' +
[width] // (number) - minium
[.precision] // .(number)
[length modifier] // not in req
conversion // c s p d i u x X %
*/

/*
edge cases:
flags do not work with %
if % at end return (-1), but print rest
*/
int	extract_args(char *f, va_list args, t_list ***alloc)
{
	t_list	**master;
	t_pobj	*tmp;
	char	*t;

	master = (t_list **)malloc(sizeof(t_list *));
	if (!master)
		return (1);
	*master = NULL;
	*alloc = master;
	t = find_trigger(f);
	f = find_specifier(t);
	while (f && t && *f)
	{
		tmp = (t_pobj *)malloc(sizeof(t_pobj));
		if (!tmp)
			return (1);
		extract_flags(f, t, tmp);
		if (extract_string(*f, args, tmp))
			return (1);
		f++;
		ft_lstadd_back(master, ft_lstnew(tmp));
		t = find_trigger(f);
		f = find_specifier(t);
	}
	return (0);
}

void	extract_flags(char *t, char *f, t_pobj *obj)
{
	while (t != f)
	{
		if (*t == '-')
			obj->justification = 1;
		else if (*t == '0')
			obj->zero_padding = 1;
		else if (*t == ' ')
			obj->spc_padding = 1;
		else if (*t == '+')
			obj->plus_padding = 1;
		else if (*t == '#')
			obj->alt_type = 1;
		else
			break ;
		t++;
	}
	if (t != f)
		obj->width = ft_atoi(t);
	while (t != f && *t != '.')
		t++;
	if (*t == '.')
		obj->precision = ft_atoi(++t);
}

int	extract_string(char specifier, va_list args, t_pobj *obj)
{
	char	*str;

	if (specifier == 'c')
		str = to_c(va_arg(args, unsigned int));
	else if (specifier == 's')
		str = to_s(va_arg(args, char *));
	else if (specifier == 'p')
		str = to_p(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		str = ft_itoa(va_arg(args, int));
	else if (specifier == 'u')
		str = ft_unsigned_itoa(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		str = to_hex(va_arg(args, unsigned int), (specifier - 23), 0);
	else
		str = get_default();
	if (str == NULL)
	{
		free(obj);
		return (1);
	}
	obj->content = str;
	obj->len = ft_strlen(str);
	obj->specifier = specifier;
	return (0);
}
