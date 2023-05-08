/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:28:15 by sozbayra          #+#    #+#             */
/*   Updated: 2023/05/08 20:03:07 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_42/libft.h"
#include "./ft_printf/ft_printf.h"
#include <signal.h>
static void ft_sender(char c, int pid){
	int i;
	i = 0;
	while(i < 8)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}	
}

static void ft_auth(int sig)
{
    if(sig == SIGUSR1)
    {
        ft_printf("Message has arrived...");
    }
}

static void ft_sendPid(int send, int pid){
    int i;
    i = 0;
    while(i < 16){
        if ((send & (0x01 << i)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        i++;
    }
}

static void ft_sendSize(int send, int pid){
    int i;
    i = 0;
    while(i < 32){
        if ((send & (0x01 << i)) != 0)
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
    int clientPid;
	int size;
	int	i;
	i = 0;
	size = 0;
    clientPid = getpid();
	if(argc == 3){
        signal(SIGUSR1,ft_auth);
		size = ft_strlen(argv[2]);
		pid = ft_atoi(argv[1]);
        ft_sendPid(clientPid, pid);
        ft_sendSize(size, pid);
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

}
