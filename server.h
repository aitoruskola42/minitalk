/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:52:48 by auskola-          #+#    #+#             */
/*   Updated: 2023/09/04 11:32:19 by auskola-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*convertstr(char *str, long n, int numbers);
int		characters(long n);
size_t	ft_strlen(char	*text);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_handler(int signum);
int		make_pow(int number, int pow);
char	*ft_itoa(int valor);

#endif