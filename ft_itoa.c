/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 18:21:50 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/06 11:54:28 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_size(int n)
{
	int				i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		num = -n;
		i++;
	}
	while (num / 10 > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	to_div(unsigned int n)
{
	int		l;

	l = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		l *= 10;
	}
	return (l);
}

unsigned int	handle_neg_number(int n)
{
	unsigned int	number;

	number = n;
	if (n < 0)
		number = -n;
	return (number);
}

char	*init_num(char *num, int n, unsigned int *number, int *i)
{
	if (n < 0)
	{
		num[*i] = '-';
		*number = -n;
		*i = *i + 1;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	int				n_to_div;
	char			*num;
	int				i;
	int				ws;
	unsigned int	number;

	i = 0;
	n_to_div = 0;
	ws = word_size(n);
	number = n;
	num = malloc(sizeof(char) * ws + 1);
	if (!num)
		return (NULL);
	num = init_num(num, n, &number, &i);
	n_to_div = to_div(number);
	while (i < ws)
	{
		num[i] = number / n_to_div + '0';
		number %= n_to_div;
		n_to_div /= 10;
		i++;
	}
	num[i] = '\0';
	return (num);
}
