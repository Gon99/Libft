/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:27:46 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/28 16:38:11 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	int		is_ascii;

	is_ascii = 0;
	if (c >= 0 && c <= 127)
		is_ascii = 1;
	return (is_ascii);
}
