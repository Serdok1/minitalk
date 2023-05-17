/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:28:15 by sozbayra          #+#    #+#             */
/*   Updated: 2023/05/17 13:12:58 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

static void	ft_confirm(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Message delivered successfully ...");
	}
}

static void	ft_send_pid(int send, int pid)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((send & (1 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

static void	ft_send_size(int send, int pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((send & (1 << i)) != 0)
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
	int	client_pid;
	int	size;
	int	i;

	i = 0;
	size = 0;
	client_pid = getpid();
	if (argc == 3)
	{
		signal(SIGUSR1, ft_confirm);
		size = ft_strlen(argv[2]);
		pid = ft_atoi(argv[1]);
		ft_send_pid(client_pid, pid);
		ft_send_size(size, pid);
		while (i < size)
		{
			ft_sender(argv[2][i], pid);
			i++;
		}
	}
	else
		ft_printf("Wrong format...");
}
