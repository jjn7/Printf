/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:54:09 by jnottle           #+#    #+#             */
/*   Updated: 2022/08/04 14:57:15 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*numlength(unsigned long num, int *length)
{
	char	*string;

	while (num >= 16)
	{
		num = num / 16;
		*length += 1;
	}
	string = (char *)malloc((*length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[*length] = '\0';
	return (string);
}

void	if_pointer(t_print *arg_count)
{
	int				length;
	char			*string;
	unsigned long	num;

	num = va_arg(arg_count->args, unsigned long);
	length = 1;
	string = numlength(num, &length);
	ft_putstr_fd("0x", 1);
	arg_count->counter += 2;
	length--;
	while (length >= 0)
	{
		if (num % 16 < 10)
			string[length] = '0' + (num % 16);
		else
			string[length] = 'a' + (num % 16) - 10;
		num = num / 16;
		length--;
		arg_count->counter++;
	}
	ft_putstr_fd(string, 1);
	free(string);
}
