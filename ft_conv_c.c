/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:19:49 by asanson           #+#    #+#             */
/*   Updated: 2021/02/01 14:52:39 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	if_width_c(t_flags *s)
{
	int	count;

	count = 0;
	if (s->n_width > 1)
	{
		while (count < s->n_width - 1)
		{
			ft_putchar(' ');
			count++;
		}
	}
	return (count);
}

int	if_flag_c(t_flags *s, char c)
{
	int	count;

	count = 0;
	if (s->right == true)
		ft_putchar(c);
	if (s->width == true)
		count = if_width_c(s);
	if (s->right == false)
		ft_putchar(c);
	return (count);
}

int	ft_conv_c(va_list args, t_flags *s)
{
	char	c;
	int		i;

	i = 0;
	c = va_arg(args, int);
	i = if_flag_c(s, c);
	return (1 + i);
}
