/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:28:55 by sozbayra          #+#    #+#             */
/*   Updated: 2023/05/17 12:57:36 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sender(char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	size;
	int	i;

	i = 0;
	size = 0;
	if (argc == 3)
	{
		size = ft_strlen(argv[2]);
		pid = ft_atoi(argv[1]);
		while (i < size)
		{
			ft_sender(argv[2][i], pid);
			i++;
		}
	}
	else
	{
		ft_printf("Wrong format...");
		return (0);
	}
	if (size == i)
		ft_sender('\n', pid);
}
