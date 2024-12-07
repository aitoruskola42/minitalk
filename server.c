/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:26:25 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/04 11:31:23 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*convertstr(char *str, long n, int numbers)
{	
	int	counter;
	int	character;

	str[numbers] = '\0';
	if (numbers == 1)
	{
		str[0] = n + '0';
		return (str);
	}
	counter = 0;
	if (n < 0)
	{
		str[0] = '-';
		counter = 1;
		n = (n * -1);
	}
	counter = 1;
	while (counter <= (numbers) && n > 0)
	{
		character = n % 10;
		n = n / 10;
		str[numbers - counter] = character + '0';
		counter ++;
	}
	return (str);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	make_pow(int number, int pow)
{
	if (pow == 0)
		number = number + 1;
	if (pow == 1)
		number = number + 2;
	if (pow == 2)
		number = number + 4;
	if (pow == 3)
		number = number + 8;
	if (pow == 4)
		number = number + 16;
	if (pow == 5)
		number = number + 32;
	if (pow == 6)
		number = number + 64;
	if (pow == 7)
		number = number + 128;
	return (number);
}

int	main(void)
{
	char	*pid;

	ft_putstr ("PID: ");
	pid = ft_itoa(getpid());
	ft_putstr (pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		sleep(1);
}
