/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:24:13 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/14 16:50:19 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pobj
{
	char	*content;
	size_t	len;
	char	specifier;
	int		justification;
	int 	width;
	int		precision;
	int		zero_padding;
	int		alt_type;
	int		plus_padding;
	int		spc_padding;
}			t_pobj;

int			ft_printf(const char *format, ...);
void null_init(t_pobj *pobj);
int			extract_args(char *format, va_list args, t_list ***master);
int			extract_string(char specifier, va_list args, t_pobj *obj);
void		extract_flags(char *f, char *t, t_pobj *obj);
int assemble_output(t_pobj *pobj, char *prefix);
char		*to_c(int c);
char		*to_s(char *str);
char		*get_default(void);
char		*find_trigger(char *format);
char		*find_specifier(char *format);
int			process_subflags(t_list **master);
int			process_num_precision(t_pobj *pobj);
char		*create_padding(size_t len, char c);
int			apply_precision(t_pobj *pobj);
void	apply_width(t_pobj *pobj);
void	apply_prefixes(t_pobj *pobj);
char		*ft_format(char *format, t_list **master, int *len);
int			ft_putstr(char *str, int error);
int			free_params(t_list ***master, va_list args);
char		*ft_unsigned_itoa(unsigned int n);
char		*to_p(void *p);
char		*to_hex(unsigned long d, char format, unsigned int i);
void		correct_len(t_list **master, int *len);
char		*process_arg(char *arg, char *n, t_list *i);
char	*create_prefix(t_pobj *pobj);
int deminus_content(t_pobj *pobj);

#endif
