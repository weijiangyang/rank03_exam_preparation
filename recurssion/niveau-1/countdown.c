/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countdown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:08:56 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/15 11:17:30 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar (char c)
{
	write (1, &c, 1);
}

void ft_putstr(char *c)
{
	while (*c)
	{
		ft_putchar(*c);
		c++;
	}
}

void ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar ('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
	
void countdown(int n)
{
	if (n > 0)
	{
		ft_putnbr(n);
		ft_putchar(' ');
		countdown(n - 1);
		ft_putchar(' ');
		ft_putnbr(n);
	}
	else
	{

		ft_putnbr (0);
	}
}

int main(void)
{
	countdown(50);
	return (0);
}
		
