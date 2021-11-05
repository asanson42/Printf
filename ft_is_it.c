/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:21:16 by asanson           #+#    #+#             */
/*   Updated: 2021/02/11 12:46:11 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	c_is_flags(char c)
{
	if (c == '-' || c == '*' || c == '.' || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

int	c_is_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' ||
			c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_get_n_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = n * -1;
	}
	while (n / 10 != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}
