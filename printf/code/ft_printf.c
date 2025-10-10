/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:29:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/10 17:08:04 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const static char	*g_flags = "#0- +.";
const static char	*g_specifiers = "cspdiuxX";

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
int	ft_printf(const char *format, ...)
{
	char	*formatted;
	t_list	**master;
	va_list	args;
	size_t	len;

	if (!format)
		return (-1);
	va_start(args, format);
	master = extract_args((char *)format, args);
	master = process_flags((char *)format, args, master);
	if (!master)
		return (free_args(master, args));
	formatted = ft_format((char *)format, master);
	free_args(master, args);
	if (!formatted)
		return (-1);
	ft_putstr(formatted);
	len = ft_strlen(formatted);
	free(formatted);
	return (len);
}

int	free_args(t_list **master, va_list args)
{
	va_end(args);
	// free master
	return (-1);
}

char	*ft_format(char *format, t_list **master)
{
	(void)format;
	(void)master;
	return (NULL);
}
