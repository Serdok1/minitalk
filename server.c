#include <stdio.h>
#include <signal.h>
#include "./libft_42/libft.h"
#include "./ft_printf/ft_printf.h" 

static void     ft_action(int sig){
    static int count;
    static int bit;
    if(sig == SIGUSR1){
        count += (0x01 << bit); 
    }
    bit++;
    if (bit == 8){
        ft_printf("%c", count);
        bit = 0;
        count = 0;
    }
}

int main(int argc, char **argv) {
    int pid;
    (void)argv;
    if(argc == 1)
    {
        pid = getpid();
        ft_printf("PID: %d\n", pid);
        while(1){
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
    /* struct sigaction s_sigaction;
    s_sigaction.sa_flags = SA_SIGINFO;
    s_sigaction.sa_sigaction = action;
    sigaction(SIGUSR1, &s_sigaction, 0);
    sigaction(SIGUSR2, &s_sigaction, 0);
    printf("PID: %d", getpid());
    while(1)
    {
        pause();
    } */

    /* void ft_binaryToAscii(char binary[], char ascii[]) {
    int i, decimal, length, k;
    length = ft_strlen(binary);
    
    i = 0;
    while (i < length) {
        decimal = 0;
        k = 0;
        while(k < 8){
            decimal = decimal * 2 + (binary[i + k] - '0');
            k++;
        };
        ascii[i / 8] = decimal;
        i += 8;
    }
    
    ascii[i / 8] = '\0';
} */