/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:14:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/10 11:29:12 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Each conversion specification is introduced
by the character %, and ends with a conversion specifier. 
In between there may be (in this order) zero or more flags, an
optional minimum field width, an optional precision and an
optional length modifier.

%
[argument$] // not in req
[flags] // # 0 - ' ' +
[width] // (number) - minium
[.precision] // .(number)
[length modifier] // not in req
conversion // c s p d i u x X %
*/
char **extract_args(char *format, va_list args, char **master)
{
	(void) format;
	(void) args;
	(void) master;
	return (NULL);
}
