/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanson <asanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:21:45 by asanson           #+#    #+#             */
/*   Updated: 2021/02/11 12:45:12 by asanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct	s_flags
{
	bool	right;
	bool	zero;
	bool	prec;
	bool	width;
	bool	precprec;
	int		n_prec;
	int		n_width;
}				t_flags;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
void			ft_putnbr(long int nb);
void			ft_put_unbr(unsigned int nb);
char			*ft_putnbr_base(long long int nb, char *h, char *b, int size);
char			*ft_putnbr_uint(uintptr_t nb, char *hexa, char *base, int size);
char			*ft_conv_hexa(long long int n, char *hexa, char *base);
char			*ft_conv_uint(uintptr_t n, char *hexa, char *base);
int				ft_fatoi(char *num, int i);

int				prec_di_true(t_flags *s, int len, int send);
int				if_prec_di(t_flags *s, int n, int len, int send);
int				if_prec_x(t_flags *s, char *str, int len, int send);
int				if_prec_s(t_flags *s, char *str, int len, int send);
int				if_prec_u(t_flags *s, unsigned int n, int len, int send);

int				if_width_c(t_flags *s);
int				if_width_s(t_flags *s, int size);
int				if_width_di(t_flags *s, int size, int prec, int n);
int				if_width_x(t_flags *s, int len, int prec);

int				ft_get_n_size(int n);
int				ft_get_ln_size(unsigned int n);
int				if_flag_c(t_flags *s, char c);
int				if_flag_s(t_flags *s, char *str, int len);
int				if_flag_di(t_flags *s, int n);
int				if_flag_u(t_flags *s, unsigned int n);
int				if_flag_x(t_flags *s, char *hexa, int len);
int				if_flag_p(t_flags *s, char *ad, int len);

void			ft_aff_p(char *str);

int				if_width_perc(t_flags *s);
int				if_flag_perc(t_flags *s);
int				ft_conv_perc(t_flags *s);

int				ft_conv_c(va_list args, t_flags *s);
int				ft_conv_s(va_list args, t_flags *s);
int				ft_conv_di(va_list args, t_flags *s);
int				ft_conv_u(va_list args, t_flags *s);
int				ft_conv_xx(va_list args, t_flags *s);
int				ft_conv_x(va_list args, t_flags *s);
int				ft_conv_p(va_list args, t_flags *s);

int				c_is_conv(char c);
int				c_is_flags(char c);

void			prec_is_flag(t_flags *s, char c);
int				flags_prec(va_list args, t_flags *s, char *format, int i);
int				flags_width(va_list args, t_flags *s, char *format, int i);
int				ft_check_conv(va_list args, char *format, int i, t_flags *s);

void			return_struct(t_flags *s);
int				ft_aff_conv(va_list args, char conv, t_flags *s);
int				ft_print_format(va_list args, char *f, t_flags *s, int len);
int				ft_printf(const char *format, ...);

#endif
