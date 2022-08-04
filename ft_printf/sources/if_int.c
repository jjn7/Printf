/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:14:18 by jnottle           #+#    #+#             */
/*   Updated: 2022/08/04 15:03:48 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_int(t_print *arg_count)
{
	char	*string;
	int		result;

	result = va_arg(arg_count->args, int);
	string = ft_itoa(result);
	ft_putstr_fd(string, 1);
	arg_count->counter += ft_strlen(string);
	free(string);
}
