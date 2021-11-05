/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:20:14 by asanson           #+#    #+#             */
/*   Updated: 2021/02/01 14:53:20 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_aff_p(char *str)
{
	ft_putstr("0x");
	ft_putstr(str);
}

int		if_flag_p(t_flags *s, char *hexa, int len)
{
	int	count;

	count = 0;
	if (s->right == true)
		ft_aff_p(hexa);
	if (s->width == true)
	{
		if (s->n_width > len)
		{
			while (count < s->n_width - len)
			{
				ft_putchar(' ');
				count++;
			}
		}
	}
	if (s->right == false)
		ft_aff_p(hexa);
	return (count + len);
}

int		ft_conv_p(va_list args, t_flags *s)
{
	char		*base;
	char		*hexa;
	uintptr_t	ad;
	int			i;
	int			len;

	base = "0123456789abcdef";
	hexa = NULL;
	i = 0;
	ad = va_arg(args, uintptr_t);
	if (!ad)
		hexa = "0";
	else
		hexa = ft_conv_uint(ad, hexa, base);
	len = ft_strlen(hexa) + 2;
	i += if_flag_p(s, hexa, len);
	return (i);
}
