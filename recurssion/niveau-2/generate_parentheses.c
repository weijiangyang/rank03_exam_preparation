/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_parentheses.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 14:01:47 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/15 14:18:23 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	generate(char *str, int pos, int open, int close)
{
	if (open == 0 && close == 0)
	{
		str[pos] = '\0';
		ft_putstr(str);
		ft_putchar('\n');
	}
	if (open > 0)
	{
		str[pos] = '(';
		generate(str, pos + 1, open - 1, close);
	}
	if (close > open)
	{
		str[pos] = ')';
		generate(str, pos + 1, open, close - 1);
	}
}

void	generate_parentheses(int n)
{
	char str[2*n + 1];
	generate(str, 0, n, n);
}

int	ft_atoi(char *s)
{
	long 	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*s && (*s >= 9 && *s <= 13 || *s == 32))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
 	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
	}
	return (sign * num);
}

int main(int ac, char **av)
{
	if (ac == 2)
		generate_parentheses(ft_atoi(av[1]));
	ft_putchar('\n');
	return (0);
}
		
