/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:20:24 by asanson           #+#    #+#             */
/*   Updated: 2021/02/01 14:53:37 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	if_width_perc(t_flags *s)
{
	int	count;

	count = 0;
	if (s->n_width > 1)
	{
		while (count < s->n_width - 1)
		{
			if (s->zero == true && s->right == false)
				ft_putchar('0');
			else
				ft_putchar(' ');
			count++;
		}
	}
	return (count);
}

int	if_flag_perc(t_flags *s)
{
	int	count;

	count = 0;
	if (s->right == true)
		ft_putchar('%');
	if (s->width == true)
		count = if_width_perc(s);
	if (s->right == false)
		ft_putchar('%');
	return (count);
}

int	ft_conv_perc(t_flags *s)
{
	int	i;

	i = 0;
	i = if_flag_perc(s);
	return (i + 1);
}
