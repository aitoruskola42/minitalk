/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:28:13 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/04 11:36:20 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

char	*ft_itoa(int value)
{
	int		strings;
	char	*str;

	strings = characters(value);
	str = (char *)malloc(sizeof(char) * (strings) +1);
	if (!str)
		return (NULL);
	str = convertstr(str, value, strings);
	return (str);
}

size_t	ft_strlen(char	*text)
{
	size_t	i;

	i = 0;
	if (!text)
		return (0);
	while (text[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_handler(int signum)
{
	static int	len = 0;
	static int	character = 0;

	if (signum == SIGUSR1)
		character = make_pow(character, 7 - len);
	len++;
	if (len == 8)
	{
		ft_putchar(character);
		character = 0;
		len = 0;
	}
}

int	characters(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter++;
		n = n * -1;
	}
	if (n == 0)
		return (1);
	while ((n / 10) > 0)
	{
		n = n / 10;
		counter ++;
	}
	return (counter + 1);
}
