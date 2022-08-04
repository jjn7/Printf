/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:12:41 by jnottle           #+#    #+#             */
/*   Updated: 2022/08/03 16:15:50 by jnottle          ###   ########.fr       */
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

void	if_hex(t_print *arg_count, char character)
{
	unsigned int	num;
	int				length;
	char			*string;

	num = va_arg(arg_count->args, unsigned int);
	length = 1;
	string = numlength(num, &length);
	length--;
	while (length >= 0)
	{
		if (num % 16 < 10)
			string[length] = '0' + (num % 16);
		else if (character == 'x')
			string[length] = 'a' - 10 + (num % 16);
		else if (character == 'X')
			string[length] = 'A' - 10 + (num % 16);
		num = num / 16;
		length--;
		arg_count->counter++;
	}
	ft_putstr_fd(string, 1);
	free(string);
}
