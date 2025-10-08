/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:29:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/08 18:46:25 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* UNDEFINED BEHAVIOUR
	if not sufficient arguments - takes next anyway
	if additional arguments - does not process them
	if type mismatch - processes as specifier
	if invalid specifier - print %
*/
int ft_printf(const char * format, ...)
{
	char *formatted;

	va_list args;
	va_start(args, format);
	formatted = format(ft_strdup(format), args);
	va_end(args);
	ft_putstr(formatted);
	free(formatted);
}

/* PROCESS
convert args to a string list
-> count %ts -> alloc master list (validate)
->	extracts data type -> converts it
	->	applies .precision
	->	applies flags
apply string list to the format, creating new string
*/
char *format(char *format, va_list args)
{
	char type;

	while (*format)
	{
		if (*format == '%')
		{
			type = extract_specifier(format)
			if (type == 0)
			{
				format++;
				continue;
			}
			format = process_specifier(type, format, args);
		}
		format++;
	}
	return (format);
}

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
char *process_specifier(char *index)
{
}

char *extract_specifier
