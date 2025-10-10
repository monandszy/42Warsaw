/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:24:13 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/10 18:25:36 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

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
	int justification; // 0: right 1: left
	size_t	width;
	int		precision;
	// 0: no 1: yes
	int		zero_padding;
	int		alt_type;
	int		plus_padding;
	int		spc_padding;
}			t_pobj;

int			ft_printf(const char *, ...);
// char **alloc_args(char *format);
t_list		**extract_args(char *format, va_list args);
void		extract_string(char specifier, va_list args, t_pobj *obj);
void		extract_flags(char *f, char *t, t_pobj *obj);
char		*extract_c(char *c);
char		*extract_s(char *s);
char		*extract_p(void *p);
char		*extract_di(int di);
char		*extract_u(unsigned int u);
char		*extract_x(unsigned int x);
char		*extract_X(unsigned int X);
char		*extract_default(void);
char		*find_trigger(char *format);
char		*find_specifier(char *format);

t_list		**process_flags(char *format, va_list args, t_list **master);
char		*ft_format(char *format, t_list **master);
void		ft_putstr(char *str);
int			free_args(t_list **master, va_list args);

#endif
