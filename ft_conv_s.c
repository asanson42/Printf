/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:20:33 by asanson           #+#    #+#             */
/*   Updated: 2021/02/01 14:54:00 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	if_prec_s(t_flags *s, char *str, int len, int send)
{
	int	count;

	count = 0;
	if (s->prec == true)
	{
		if (s->n_prec < len)
		{
			while (count < s->n_prec)
			{
				if (send == 1)
					ft_putchar(str[count]);
				count++;
			}
			return (count);
		}
	}
	if (send == 1)
		ft_putstr(str);
	return (len);
}

int	if_width_s(t_flags *s, int size)
{
	int	count;

	count = 0;
	if (s->n_width > size)
	{
		while (count < s->n_width - size)
		{
			ft_putchar(' ');
			count++;
		}
	}
	return (count);
}

int	if_flag_s(t_flags *s, char *str, int len)
{
	int	count;
	int	size;

	count = 0;
	if (s->right == true)
		if_prec_s(s, str, len, 1);
	size = if_prec_s(s, str, len, 0);
	if (s->width == true)
		count = if_width_s(s, size);
	if (s->right == false)
		if_prec_s(s, str, len, 1);
	return (size + count);
}

int	ft_conv_s(va_list args, t_flags *s)
{
	char	*str;
	int		i;
	int		len;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	if (s->prec == false && s->n_prec == -1)
		str = "";
	len = ft_strlen(str);
	i = if_flag_s(s, str, len);
	return (i);
}
