/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:26:18 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/09 16:07:12 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char s)
{
	int		is_s;

	is_s = 0;
	if (s == '\n' || s == ' ' || s == '\v' || s == '\t' || s == '\r' \
			|| s == '\f')
		is_s = 1;
	return (is_s);
}

int	ft_atoi(const char *str)
{
	char	*aux;
	long	res;
	int		is_n;

	aux = (char *)str;
	res = 0;
	is_n = 0;
	while (is_space(*aux) != '\0')
		aux++;
	if (*aux == '+' || *aux == '-')
	{
		if (*aux == '-')
			is_n = 1;
		aux++;
	}
	while (*aux >= '0' && *aux <= '9')
	{
		res = res * 10 + *aux - '0';
		aux++;
	}
	if (is_n)
		res = -res;
	return (res);
}