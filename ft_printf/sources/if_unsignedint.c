/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnottle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:19:54 by jnottle           #+#    #+#             */
/*   Updated: 2022/08/04 15:02:12 by jnottle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlength(unsigned int num)
{
	int	length;

	length = 1;
	while (num > 9)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

static char	*itoa(unsigned int num)
{
	char	*string;
	int		length;

	length = numlength(num);
	string = (char *)malloc(length + 1 * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[length] = '\0';
	while (length > 0)
	{
		string[--length] = num % 10 + '0';
		num = num / 10;
	}
	return (string);
}

void	if_unsignedint(t_print *arg_count)
{
	char	*string;
	int		result;

	result = va_arg(arg_count->args, unsigned int);
	string = itoa(result);
	ft_putstr_fd(string, 1);
	arg_count->counter += ft_strlen(string);
	free(string);
}
