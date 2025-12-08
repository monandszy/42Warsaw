/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:24:13 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/03 12:36:23 by sandrzej         ###   ########.fr       */
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
	int		is_null;
	int		justification;
	int		width;
	int		precision;
	int		zero_padding;
	int		alt_type;
	int		plus_padding;
	int		spc_padding;
}			t_pobj;

typedef struct s_lengths
{
	size_t	prefix;
	size_t	payload;
	size_t	padding;
	size_t	final;
	char	pad_char;
}			t_lengths;

int			ft_printf(const char *format, ...);
int			free_params(t_list ***master, va_list args);
int			ft_putstr(char *str, int error);
int			extract_args(char *format, va_list args, t_list ***master);
int			extract_string(char specifier, va_list args, t_pobj *obj);
char		*to_s(t_pobj *obj, char *str);
char		*to_c(int c);
char		*to_p(t_pobj *obj, void *p);
char		*to_hex(unsigned long d, char format, unsigned int i);
char		*ft_unsigned_itoa(unsigned int n);
char		*get_default(void);
void		extract_flags(char *f, char *t, t_pobj *obj);
void		null_init(t_pobj *pobj);
char		*find_trigger(char *format);
char		*find_specifier(char *format);
char		*ft_format(char *format, t_list **master, int *len);
int			copy_parts(char *f, t_list *i, char *new);
char		*copy_part(t_list *i, char *new);
size_t		get_total_len(char *f, t_list **master);

int			process_subflags(t_list **master);
int			process_pobj(t_pobj *pobj);
int			handle_null_precision(t_pobj *pobj);
int			handle_precision(t_pobj *pobj);

int			apply_precision(t_pobj *pobj);
char		*create_prefix(t_pobj *pobj);
char		*create_di_prefix(char sign);
char		*create_hex_prefix(char sign);
int			deminus_content(t_pobj *pobj);

int			assemble_output(t_pobj *pobj, char *prefix);
char		get_padding_char(t_pobj *pobj);
void		build_left_justified(t_pobj *pobj, char *prefix, t_lengths *lengths,
				char *output_str);
void		build_right_justified(t_pobj *pobj, char *prefix,
				t_lengths *lengths, char *output_str);
size_t		ft_better_stlen_questionmark(char *s);

#endif
