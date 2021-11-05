/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:19:59 by asanson           #+#    #+#             */
/*   Updated: 2021/02/11 12:45:46 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	prec_di_true(t_flags *s, int len, int send)
{
	int	count;

	count = 0;
	if (s->n_prec > len)
	{
		while (count < s->n_prec - len)
		{
			if (send == 1)
				ft_putchar('0');
			count++;
		}
	}
	return (count);
}

int	if_prec_di(t_flags *s, int n, int len, int send)
{
	int	count;

	count = 0;
	if (n < 0 && s->prec == true)
	{
		if (send == 1)
			ft_putchar('-');
		n = n * -1;
		len--;
	}
	if (s->prec == true)
		count += prec_di_true(s, len, send);
	if (send == 1)
	{
		if ((s->precprec == true && n == 0))
			return (count);
		ft_putnbr(n);
	}
	return (count);
}

int	if_width_di(t_flags *s, int size, int prec, int n)
{
	int	count;

	if (s->precprec == true && n == 0)
		size--;
	count = 0;
	if (s->n_width > size + prec)
	{
		while (count < s->n_width - (size + prec))
		{
			if (s->zero == true && s->right == false && s->prec == false)
				ft_putchar('0');
			else
				ft_putchar(' ');
			count++;
		}
	}
	return (count);
}

int	if_flag_di(t_flags *s, int n)
{
	int	count;
	int	size;
	int	prec;

	size = 0;
	prec = 0;
	count = 0;
	if (n < 0 && s->zero == true && s->right == false && s->prec == false)
	{
		ft_putchar('-');
		n = n * -1;
		size++;
	}
	size += ft_get_n_size(n);
	if (s->prec == true && s->n_prec == 0)
		size = 0;
	if (s->right == true)
		if_prec_di(s, n, size, 1);
	if (s->prec == true)
		prec = if_prec_di(s, n, size, 0);
	if (s->width == true)
		count += if_width_di(s, size, prec, n);
	if (s->right == false)
		if_prec_di(s, n, size, 1);
	return ((size + prec) + count);
}

int	ft_conv_di(va_list args, t_flags *s)
{
	int	n;
	int	size;

	n = va_arg(args, int);
	size = if_flag_di(s, n);
	return (size);
}
