/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:44:00 by jnottle           #+#    #+#             */
/*   Updated: 2022/08/04 13:59:12 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_print
{
	va_list	args;
	int		counter;
}	t_print;

void	if_character(t_print *arg_count);
void	if_string(t_print *arg_count);
void	if_pointer(t_print *arg_count);
void	if_hex(t_print *arg_count, char character);
void	if_int(t_print *arg_count);
void	if_unsignedint(t_print *arg_count);
int		ft_printf(const char *string, ...);

#endif
