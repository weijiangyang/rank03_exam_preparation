/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:34:58 by weiyang           #+#    #+#             */
/*   Updated: 2025/08/15 11:46:14 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen_rec(char *s)
{
	int	len;

	if (*s == '\0')
		return 0;

	return  ( 1 + ft_strlen_rec(s + 1));
}

int main(void)
{
	int len;

	len = ft_strlen_rec("hello");
	printf("%d\n", len);
	return (0);
}

