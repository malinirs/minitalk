/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 01:07:16 by awoods            #+#    #+#             */
/*   Updated: 2021/08/11 01:07:21 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receiving_messages(int signal)
{
	static int	count = 0;
	static char	symbol = 0;

	if (SIGUSR2 == signal)
		symbol = symbol + (1 << count);
	count++;
	if (count > 7)
	{
		write(1, &symbol, 1);
		count = 0;
		symbol = 0;
	}
}

void	put_pit(void)
{
	char	*str;

	write(1, "PID: ", 5);
	str = ft_itoa(getpid());
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

int	main(void)
{
	put_pit();
	signal(SIGUSR2, receiving_messages);
	signal(SIGUSR1, receiving_messages);
	while (1)
		pause();
	return (0);
}
