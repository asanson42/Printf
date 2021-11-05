/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:19:26 by asanson           #+#    #+#             */
/*   Updated: 2021/02/11 12:47:07 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	prec_is_flag(t_flags *s, char c)
{
	if (s->n_prec < 0)
	{
		s->prec = false;
		s->n_prec = 0;
	}
	if (s->prec == true && s->n_prec == 0 && (c == 'd' || c == 'i' ||
				c == 'u' || c == 'x' || c == 'X'))
	{
		s->precprec = true;
		s->prec = false;
	}
}

int		flags_prec(va_list args, t_flags *s, char *format, int i)
{
	int	j;

	j = i;
	s->prec = true;
	if (format[i] == '*' || format[i] == 'd' || format[i] == 'i' ||
			format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
	{
		if (format[i] != '*')
			i--;
		else
			s->n_prec = va_arg(args, int);
		i++;
	}
	else if (format[i] >= 48 && format[i] <= 57)
	{
		s->n_prec = ft_fatoi(format, i);
		while (format[i] >= 48 && format[i] <= 57 && format[i])
			i++;
	}
	prec_is_flag(s, format[i]);
	return (i - j);
}

int		flags_width(va_list args, t_flags *s, char *format, int i)
{
	int	j;

	j = i;
	s->width = true;
	if (format[i] == '*')
	{
		s->n_width = va_arg(args, int);
		if (s->n_width < 0)
		{
			s->n_width = s->n_width * -1;
			s->right = true;
		}
		i++;
	}
	else if (format[i] >= 48 && format[i] <= 57)
	{
		s->n_width = ft_fatoi(format, i);
		while (format[i] && format[i] >= 48 && format[i] <= 57)
			i++;
	}
	else
		s->width = false;
	return ((i - j) - 1);
}

int		ft_check_conv(va_list args, char *format, int i, t_flags *s)
{
	int	count;

	count = i;
	i++;
	if (format[i] == ' ')
		ft_putchar(format[i++]);
	while (c_is_flags(format[i]))
	{
		if (format[i] == '-')
			s->right = true;
		else if (format[i] == '0')
			s->zero = true;
		else if (format[i] == '.')
			i += flags_prec(args, s, format, i + 1);
		else if ((format[i] == '*' || (format[i] >= 48 && format[i] <= 57))
				&& format[i - 1] != '.')
			i += flags_width(args, s, format, i);
		i++;
	}
	return (i - count);
}
