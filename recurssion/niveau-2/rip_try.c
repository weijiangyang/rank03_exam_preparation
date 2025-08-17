/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip_try.c                                          :+:      :+:    :+:   */
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

int is_valide(char *str)
{
    int bal;

    bal = 0;
    while (*str)
    {
        if (*str == '(')
            bal++;
        if (*str == ')')
        {
            bal--;
            if (bal < 0)
                return (0);
        }
        str++;
    }
    if (bal == 0)
        return (1);
    else
        return (0);
}

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

void backtracking(char *str, int pos, int ldel, int rdel)
{

    char tmp;

    if (!str[pos]) // reached end of string
    {
        if (ldel == 0 && rdel == 0 && is_valide(str))
        {
            ft_putstr(str); // prints without '-'
            ft_putchar('\n');
        }
        return;
    }

  
    if (str[pos] == '(' && ldel > 0)
    {
        tmp = str[pos];
        str[pos] = ' ';
        backtracking(str, pos + 1, ldel - 1, rdel);
        str[pos] = tmp;
    }
    if (str[pos] == ')' && rdel > 0)
    {
        tmp = str[pos];
        str[pos] = ' ';
        backtracking(str, pos + 1, ldel, rdel - 1);
        str[pos] = tmp;
    }
    backtracking(str, pos + 1, ldel, rdel);
}

int ft_strlen(char *str)
{
    // calculer la taille d'un str
    int size;

    size = 0;
    while (str[size])
        size++;
    return (size);
}

char *ft_strdup(char *s)
{
    // copy un string, et fini par '\0', si s est NULL, retourne NULL directement
    char *ptr;
    char *dst;
    int i;

    i = 0;
    if (!s)
        return (NULL);
    ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    dst = ptr;
    while (s[i])
    {
        dst[i] = s[i];
        i++;
    }
    dst[i] = '\0';
    return (ptr);
}

int main(int ac, char **av)
{
    char *str;
    int ldel;
    int rdel;
    int bal;
    int i;

    if (ac != 2)
        return (1);

    i = 0;
    ldel = 0;
    rdel = 0;
    bal = 0;
    str = ft_strdup(av[1]);
    if (!str)
        return (1);

    while (str[i])
    {
        if (str[i] == '(')
        {
            bal++;
        }
        else if (str[i] == ')')
        {
            if (bal == 0)
            {
                rdel++; // extra closing
            }
            else
            {
                bal--; // matched one
            }
        }
        i++;
    }

    if (bal > 0)
        ldel = bal; // leftover opens

    backtracking(str, 0, ldel, rdel);

    free(str);
    return (0);
}
