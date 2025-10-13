/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:29:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/13 14:02:27 by sandrzej         ###   ########.fr       */
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
int	ft_printf(const char *format, ...)
{
	char	*formatted;
	t_list	***master;
	va_list	args;
	size_t	len;

	if (!format)
		return (ft_putstr(NULL));
	master = (t_list ***)malloc(sizeof(t_list **));
	if (!master)
		return (ft_putstr(NULL));
	va_start(args, format);
	if (extract_args((char *)format, args, master))
		return (free_params(master, args));
	if (process_flags((char *)format, args, *master))
		return (free_params(master, args));
	formatted = ft_format((char *)format, *master);
	free_params(master, args);
	return (ft_putstr(formatted));
}

int	free_params(t_list ***master, va_list args)
{
	// todo nested free logic
	va_end(args);
	return (-1);
}

int	ft_putstr(char *str)
{
	size_t	len;

	if (str == NULL)
		len = -2;
	else
	{
		len = ft_strlen(str);
		write(STDOUT_FILENO, str, len);
		free(str);
	}
	return (len);
}
