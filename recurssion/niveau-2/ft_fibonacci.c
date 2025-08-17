/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 12:49:27 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/15 12:53:34 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_fibonacci(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return ft_fibonacci (n - 1) + ft_fibonacci(n -2);
}

int main()
{
	int result;

	result = ft_fibonacci (6);
	printf("%d\n", result);
	return (0);
}
