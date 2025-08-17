/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorial.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:25:22 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/15 11:29:15 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int factorial(unsigned int n)
{
	if (n <= 1)
		return 1;
	else
		return ( n * factorial(n - 1));
}

int main(void)
{
	int result;

	result = factorial(4);
	printf("%d\n", result);
	return (0);
}
