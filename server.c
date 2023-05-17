/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:28:48 by sozbayra          #+#    #+#             */
/*   Updated: 2023/05/17 12:56:34 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_action(int sig)
{
	static int	count;
	static int	bit;

	if (sig == SIGUSR1)
	{
		count += (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", count);
		bit = 0;
		count = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("PID: %d\n", pid);
		while (1)
		{
			signal(SIGUSR1, ft_action);
			signal(SIGUSR2, ft_action);
			pause();
		}
	}
	else
	{
		ft_printf("Wrong format...");
		return (0);
	}
}
