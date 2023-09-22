/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:00:57 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/09/20 22:25:46 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0)
		return (0);
	while (s1[index] && s2[index] && index < n - 1 && s1[index] == s2[index])
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

int	ft_isint(const char *str)
{
	int	index;

	if (ft_strlen(str) > 11)
		return (0);
	index = 0;
	if (str[0] == '+')
		index++;
	while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
			return (0);
		index++;
	}
	if (ft_strlen(str) == 11)
	{
		if (str[0] == '-' && ft_strncmp(str, "-2147483648", 11) > 0)
			return (0);
		if (str[0] == '+' && ft_strncmp(str, "+2147483647", 11) > 0)
			return (0);
	}
	else if (ft_strlen(str) == 10
		&& ft_strncmp(str, "2147483647", 10) > 0 && str[0] != '-')
		return (0);
	return (1);
}
