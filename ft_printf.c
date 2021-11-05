/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:21:23 by asanson           #+#    #+#             */
/*   Updated: 2021/02/10 15:41:24 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_aff_conv(va_list args, char conv, t_flags *s)
{
	int	len;

	len = 0;
	if (conv == 's')
		len = ft_conv_s(args, s);
	if (conv == 'c')
		len = ft_conv_c(args, s);
	if (conv == 'd' || conv == 'i')
		len = ft_conv_di(args, s);
	if (conv == 'u')
		len = ft_conv_u(args, s);
	if (conv == 'X')
		len = ft_conv_xx(args, s);
	if (conv == 'x')
		len = ft_conv_x(args, s);
	if (conv == 'p')
		len = ft_conv_p(args, s);
	if (conv == '%')
		len = ft_conv_perc(s);
	return (len);
}

void	return_struct(t_flags *s)
{
	s->right = false;
	s->zero = false;
	s->width = false;
	s->prec = false;
	s->precprec = false;
	s->n_prec = 0;
	s->n_width = 0;
}

int		ft_print_format(va_list args, char *form, t_flags *s, int len)
{
	int	i;

	i = 0;
	while (i < ft_strlen((char *)form))
	{
		return_struct(s);
		if (form[i] == '%')
		{
			if (form[i + 1] == ' ')
				len += 1;
			i += ft_check_conv(args, (char *)form, i, s);
			if (c_is_conv(form[i]) == 0)
				return (-1);
			len += ft_aff_conv(args, form[i++], s);
		}
		else
		{
			ft_putchar(form[i++]);
			len++;
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;
	t_flags		t;
	t_flags		*s;

	s = &t;
	len = 0;
	return_struct(s);
	va_start(args, format);
	len = ft_print_format(args, (char *)format, s, len);
	va_end(args);
	return (len);
}
