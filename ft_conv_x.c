/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:21:06 by asanson           #+#    #+#             */
/*   Updated: 2021/02/11 11:50:46 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	if_prec_x(t_flags *s, char *str, int len, int send)
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
			ft_putstr(str);
	}
	else if (send == 1)
		ft_putstr(str);
	return (count);
}

int	if_width_x(t_flags *s, int len, int prec)
{
	int	count;

	count = 0;
	if (s->n_width > len + prec)
	{
		while (count < s->n_width - (len + prec))
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

int	if_flag_x(t_flags *s, char *hexa, int len)
{
	int	count;
	int	prec;

	prec = 0;
	count = 0;
	if (s->right == true)
		if_prec_x(s, hexa, len, 1);
	if (s->prec == true)
		prec = if_prec_x(s, hexa, len, 0);
	if (s->width == true)
		count += if_width_x(s, len, prec);
	if (s->right == false)
		if_prec_x(s, hexa, len, 1);
	return (prec + count);
}

int	ft_conv_x(va_list args, t_flags *s)
{
	char			*base;
	char			*hexa;
	int				len;
	long long int	n;

	base = "0123456789abcdef";
	hexa = NULL;
	n = va_arg(args, unsigned int);
	if (n == 0 && (s->precprec != true))
		hexa = "0";
	else if ((s->prec == true && s->n_prec == 0)
			|| (s->precprec == true && n == 0))
		hexa = "";
	else
		hexa = ft_conv_hexa(n, hexa, base);
	if (s->prec == true && s->n_prec == 0)
		len = 0;
	else
		len = ft_strlen(hexa);
	len += if_flag_x(s, hexa, len);
	return (len);
}

int	ft_conv_xx(va_list args, t_flags *s)
{
	char			*base;
	char			*hexa;
	int				len;
	long long int	n;

	base = "0123456789ABCDEF";
	hexa = NULL;
	n = va_arg(args, unsigned int);
	if (n == 0 && s->precprec != true)
		hexa = "0";
	else if ((s->prec == true && s->n_prec == 0)
			|| (s->precprec == true && n == 0))
		hexa = "";
	else
		hexa = ft_conv_hexa(n, hexa, base);
	if (s->prec == true && s->n_prec == 0)
		len = 0;
	else
		len = ft_strlen(hexa);
	len += if_flag_x(s, hexa, len);
	return (len);
}
