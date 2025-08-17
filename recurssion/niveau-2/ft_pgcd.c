/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:54:35 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/15 13:41:37 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_pgcd(unsigned int a, unsigned int b)
{
	if ( b == 0)
		return (a);
	return (ft_pgcd(b, a % b));
}

int	main(void)
{
	unsigned int a = 18;
	unsigned int b = 48;
	int result = ft_pgcd(a, b);
	printf("%d\n", result);
	return (0);
}
