/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:20:42 by asanson           #+#    #+#             */
/*   Updated: 2021/02/11 12:31:37 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_get_ln_size(unsigned int n)
{
	int	size;

	size = 1;
	while (n / 10 != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

int	if_prec_u(t_flags *s, unsigned int n, int len, int send)
{
	int	count;

	count = 0;
	if (s->prec == true)
	{
		if (s->n_prec > len)
		{
			while (count < s->n_prec - len)
			{
				if (send == 1)
					ft_putchar('0');
				count++;
			}
		}
		if (s->n_prec > 0 && send == 1)
			ft_put_unbr(n);
	}
	else if (send == 1)
	{
		if (s->precprec == true && n == 0)
			return (count);
		ft_put_unbr(n);
	}
	return (count);
}

int	if_flag_u(t_flags *s, unsigned int n)
{
	int	count;
	int	size;
	int	prec;

	prec = 0;
	count = 0;
	size = ft_get_ln_size(n);
	if (s->prec == true && s->n_prec == 0)
		size = 0;
	if (s->right == true)
		if_prec_u(s, n, size, 1);
	if (s->prec == true)
		prec = if_prec_u(s, n, size, 0);
	if (s->width == true)
		count += if_width_di(s, size, prec, n);
	if (s->right == false)
		if_prec_u(s, n, size, 1);
	return ((size + prec) + count);
}

int	ft_conv_u(va_list args, t_flags *s)
{
	unsigned int	n;
	int				size;

	n = va_arg(args, int);
	size = if_flag_u(s, n);
	return (size);
}
