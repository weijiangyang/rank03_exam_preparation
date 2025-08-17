/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:17:40 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/15 11:25:09 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	sum(unsigned int n)
{

	if (n == 1)
		return 1;
	else
		return sum(n - 1) + n;
}

int main(void)
{
	int result;

	result = sum(20);
	printf("%d\n", result);
	return (0);
}
