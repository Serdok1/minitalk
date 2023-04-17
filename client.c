#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft_42/libft.h"

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}

/* int x = 0;

void handle_sigusr1(int sig){
    if (x == 0)
    {
        printf("\nhint\n");
    }  
}

int main(int argc, char* argv[]) {
    int pid = fork();
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else {
        struct sigaction s_sa = { 0 };
        s_sa.sa_flags = SA_RESTART;
        s_sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &s_sa, NULL);

        printf("3x5?:");
        scanf("%d", &x);
        if (x == 15){
            printf("right");
        }else{
            printf("wrong");
        }
    }
    return 0;
} */