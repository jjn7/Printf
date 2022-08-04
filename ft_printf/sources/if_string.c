/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:48:20 by jnottle           #+#    #+#             */
/*   Updated: 2022/08/04 14:55:39 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_string(t_print *arg_count)
{
	char	*string;
	int		length;

	string = va_arg(arg_count->args, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		arg_count->counter += 6;
	}
	else
	{
		length = ft_strlen(string);
		ft_putstr_fd(string, 1);
		arg_count->counter += length;
	}
}
