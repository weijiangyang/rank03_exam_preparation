/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:42:15 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/17 11:42:18 by weiyang          ###   ########.fr       */
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

int sum (int *tab, int depth)
{
    int i;
    int sum;

    sum = 0;
    i = 0;
    while (i < depth)
    {
        sum += tab[i];
        i++;
    }
    return (sum);
}


void ft_putnbr(unsigned long n)
{
    if (n > 9)
        ft_putnbr(n /10);
    ft_putchar (n % 10 + '0');
}

void    print_tab(int *tab, int depth)
{
    int i;

    i = 0;
    while (i < depth)
    {
        ft_putnbr(tab[i]);
        ft_putchar (' ');
        i++;
    }

}

void backtracking(int *tab, int *target, int n, int start, int len, int depth)
{
    int i;
    int s;

    i = start;
    s = sum (target, depth);
    if (s == n)
    {
        print_tab(target, depth);
        ft_putchar('\n');
        return ;
    }
    if (s > n)
        return ;
    while (i < len)
    {
        target[depth] = tab[i];
        backtracking(tab, target, n, i + 1, len, depth + 1);
        i++;
    }

}

int main(int ac, char **av)
{
    if (ac < 3)
    {
        write(1, "Usage: ./a.out n num1 num2 ...\n", 31);
        return 1;
    }

    int n = atoi(av[1]);
    int len = ac - 2;
    int tab[len];
    int target[len];

    for (int i = 0; i < len; i++)
        tab[i] = atoi(av[i + 2]);

    backtracking(tab, target, n, 0, len, 0);
    return 0;
}