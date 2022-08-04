/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:39:51 by jnottle           #+#    #+#             */
/*   Updated: 2022/08/03 15:43:21 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_character(t_print *arg_count)
{
	ft_putchar_fd(va_arg(arg_count->args, int), 1);
	arg_count->counter++;
}
