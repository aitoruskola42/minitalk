/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:26:19 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/04 10:20:10 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

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

int	ft_atoi(char *str)
{
	size_t	counter;
	int		sign;
	int		number;

	sign = 1;
	counter = 0;
	number = 0;
	if (str[0] == '-')
		sign = -1;
	while (counter < ft_strlen(str))
	{
		if (str[counter] >= 48 && str[counter] <= 57)
		{
			number = number * 10 + (str[counter] - '0');
		}
		counter++;
	}
	return (sign * number);
}

int	number_binary(unsigned int number, int bit)
{
	int		i;

	i = 0;
	while (i <= bit)
	{
		if (i == bit)
			return (number % 2);
		number = number / 2;
		i++;
	}
	return (0);
}

// usleep(xxx). Can be in slower computer 
// need to make upper than 250.

static void	send_binary(int pid, char *str)
{
	int	i;
	int	j;
	int	chars;

	chars = ft_strlen(str);
	i = 0;
	while (i < chars)
	{
		j = 7;
		while (j >= 0)
		{
			if (number_binary(str[i], j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(250);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	send_binary(pid, argv[2]);
	return (0);
}
