/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 01:07:03 by awoods            #+#    #+#             */
/*   Updated: 2021/08/11 01:07:07 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_massage(int pid, char c)
{
	int		i;
	int		bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

void	ft_exit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc < 3 || argc > 3)
		ft_exit("Error: there must be three arguments!");
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_exit("Error: invalid PID!");
	str = argv[2];
	while (*str)
	{
		put_massage(pid, *str);
		str++;
	}
	put_massage(pid, '\n');
	return (0);
}
