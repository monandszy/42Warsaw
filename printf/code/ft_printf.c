/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:29:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/09 15:52:57 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* UNDEFINED BEHAVIOUR
	if not sufficient arguments - takes next anyway
	if additional arguments - does not process them
	if type mismatch - processes as specifier
	if invalid specifier - print % without specifier

	if crash nothing will print
*/
/* PROCESS
convert args to a string list
-> count %ts -> alloc master list (validate)
->	extracts data type -> converts it
	->	applies .precision
	->	applies flags
apply string list to the format, creating new string
*/
int ft_printf(const char * format, ...)
{
	char *formatted;
	char **master;
	int c;
	va_list args;
	size_t len;

	c = count_args((char *) format);
	master = (char **) malloc(sizeof(char *) * (c + 1));
	if (!master)
		return (0);
	master[c] = NULL;
	va_start(args, format);
	master = extract_args((char *) format, args, master);
	va_end(args);
	if (!master)
		return (0);
	formatted = ft_format((char *) format, master);
	ft_putstr(formatted);
	len = ft_strlen(formatted);
	free(formatted);
	return (len);
}

char *ft_format(char *format, char **master)
{
	(void) format;
	(void) master;
	return (NULL);
}


