/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:29:41 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/15 11:34:20 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_power(unsigned int n1, unsigned int n2)
{
	if (n2 == 0)
		return 1;
	return (n1 * ft_power(n1, n2 - 1));
}

int	main(void)
{
	int 	result;
	unsigned int 	n1;
	unsigned int	n2;
	
	n1 = 2;
	n2 = 5;
	result = ft_power(n1, n2);
	printf("%d\n", result);
	return 0;
}
