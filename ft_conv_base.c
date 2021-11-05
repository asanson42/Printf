/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:19:39 by asanson           #+#    #+#             */
/*   Updated: 2021/02/02 15:48:40 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_fatoi(char *num, int i)
{
	int	n;

	n = 0;
	while (num[i] && (num[i] >= 48 && num[i] <= 57))
		n = (n * 10) + (num[i++] - 48);
	return (n);
}

char	*ft_putnbr_base(long long int nb, char *h, char *b, int size)
{
	size--;
	if (nb >= 16)
	{
		ft_putnbr_base((nb / 16), h, b, size);
		h[size] = b[nb % 16];
	}
	if (nb < 16)
		h[size] = b[nb];
	return (h);
}

char	*ft_conv_hexa(long long int n, char *hexa, char *base)
{
	int				size;
	long long int	tmp;

	size = 1;
	tmp = n;
	while (tmp / 16 != 0)
	{
		size++;
		tmp = tmp / 16;
	}
	if (!(hexa = malloc(sizeof(char) * (size + 1))))
		return (0);
	hexa[size] = '\0';
	return (ft_putnbr_base(n, hexa, base, size));
}

char	*ft_putnbr_uint(uintptr_t nb, char *hexa, char *base, int size)
{
	size--;
	if (nb >= 16)
	{
		ft_putnbr_uint((nb / 16), hexa, base, size);
		hexa[size] = base[nb % 16];
	}
	if (nb < 16)
		hexa[size] = base[nb];
	return (hexa);
}

char	*ft_conv_uint(uintptr_t n, char *hexa, char *base)
{
	uintptr_t	tmp;
	int			size;

	size = 1;
	tmp = n;
	while (tmp / 16 != 0)
	{
		size++;
		tmp = tmp / 16;
	}
	if (!(hexa = malloc(sizeof(char) * (size + 1))))
		return (0);
	hexa[size] = '\0';
	return (ft_putnbr_uint(n, hexa, base, size));
}
