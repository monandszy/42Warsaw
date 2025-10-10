/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:14:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/10 18:22:59 by sandrzej         ###   ########.fr       */
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
t_list	**extract_args(char *f, va_list args)
{
	t_list	**master;
	t_list	**i;
	t_pobj	*tmp;
	char	*str;
	char	*t;

	master = (t_list **)malloc(sizeof(t_list *));
	if (!master)
		return (NULL);
	i = master;
	t = find_trigger(f);
	f = find_specifier(f);
	while (*f)
	{
		tmp = (t_pobj *)malloc(sizeof(t_pobj));
		if (!tmp)
			return (NULL);
		extract_flags(f, t, tmp);
		extract_string(*f, args, tmp);
		ft_lstadd_back(master, ft_lstnew(tmp));
		t = find_trigger(f);
		f = find_specifier(++f);
	}
	return (master);
}

void	extract_flags(char *f, char *t, t_pobj *obj)
{
	while (f != t)
	{
		if (*f == '-')
			obj->justification = 1;
		else if (*f == '0')
			obj->zero_padding = 1;
		else if (*f == ' ')
			obj->spc_padding = 1;
		else if (*f == '+')
			obj->plus_padding = 1;
		else if (*f == '#')
			obj->alt_type = 1;
		else
			break ;
		f++;
	}
	if (f != t)
		obj->width = ft_atoi(f);
	while (f != t && *f != '.')
		f++;
	if (*f == '.')
		obj->precision = ft_atoi(++f);
}

void	extract_string(char specifier, va_list args, t_pobj *obj)
{
	char	*str;

	if (specifier == 'c')
		str = extract_c(va_arg(args, char *));
	else if (specifier == 's')
		str = extract_s(va_arg(args, char *));
	else if (specifier == 'p')
		str = extract_p(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		str = extract_di(va_arg(args, int));
	else if (specifier == 'u')
		str = extract_u(va_arg(args, unsigned int));
	else if (specifier == 'x')
		str = extract_x(va_arg(args, unsigned int));
	else if (specifier == 'X')
		str = extract_X(va_arg(args, unsigned int));
	else
		str = extract_default();
	obj->content = str;
	obj->len = ft_strlen(str);
	obj->specifier = specifier;
}
