/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:16:05 by jnottle           #+#    #+#             */
/*   Updated: 2022/08/04 14:59:58 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print	*start(void)
{
	t_print	*arg_count;

	arg_count = (t_print *)malloc(sizeof(t_print));
	if (arg_count == NULL)
		return (NULL);
	arg_count->counter = 0;
	return (arg_count);
}

void	conversion(const char character, t_print *arg_count)
{
	if (character == 'c')
		if_character(arg_count);
	else if (character == 's')
		if_string(arg_count);
	else if (character == 'p')
		if_pointer(arg_count);
	else if (character == 'i' || character == 'd')
		if_int(arg_count);
	else if (character == 'u')
		if_unsignedint(arg_count);
	else if (character == 'x' || character == 'X')
		if_hex(arg_count, character);
	else if (character == '%')
	{
		ft_putchar_fd('%', 1);
		arg_count->counter++;
	}
	else if (character != '\0')
	{
		write(1, &character, 1);
		arg_count->counter++;
	}
}

int	ft_printf(const char *string, ...)
{
	t_print	*arg_count;
	int		print;
	int		i;

	i = 0;
	arg_count = start();
	print = 0;
	va_start(arg_count->args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
			conversion(string[++i], arg_count);
		else
		{
			ft_putchar_fd(string[i], 1);
			arg_count->counter++;
		}
		if (string[i] != '\0')
			i++;
	}
	print = arg_count->counter;
	va_end(arg_count->args);
	free(arg_count);
	return (print);
}
