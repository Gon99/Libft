/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 16:38:32 by goliano-          #+#    #+#             */
/*   Updated: 2021/07/28 16:45:53 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	int		is_print;

	is_print = 0;
	if (c > 31 && c < 127)
		is_print = 1;
	return (is_print);
}
