/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 09:54:09 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/17 10:06:39 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void generate(char *str, int start, int open, int close, int n)
{
	int i;

	i = start;
	if (open == 0 && close == 0)
	{
		str[i] = '\0';
		ft_putstr(str);
		ft_putchar('\n');
		return;
	}

	if (open > 0)
	{
		str[i] = '(';

		generate(str, i + 1, open - 1, close, n);
		
	}
	if (close > open)
	{
		str[i] = ')';

		generate(str, i + 1, open, close - 1, n);
		
	}
}

void parentehese(int n)
{
	char *str;

	str = malloc(2 * n + 1);
	if (!str)
		return;
	generate(str, 0, n, n, n);
	free(str);
}

int main(int ac, char **av)
{
	int n;

	n = 3;
	parentehese(n);
	return (0);
}
