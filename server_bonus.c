#include <signal.h>
#include "./libft_42/libft.h"
#include "./ft_printf/ft_printf.h" 

static void ft_getPid(int getPid){
    static int i;
    static int count;
    if (getPid == SIGUSR1)
        count += (0x01 << i);
    i++;
    if (i == 16){
        kill(count, SIGUSR1);
        i = 0;
        count = 0;
    }
}

static int ft_getSize(int sig){
    static int i;
    static int count;
    static int r;
    if (sig == SIGUSR1)
        count += (0x01 << i);
    i++;
    if (i == 32){
        r = count;
        count = 0;
        i = 0;
        return (r);
    }
    return(count);
}

static void     ft_write(int sig){
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

static void     ft_action(int sig){
    static int count;
    static int size;
    if(count < 16){
        ft_getPid(sig);
        count++;
    }
    else if (count < 48 && count > 15){
        size = ft_getSize(sig);
        count++;
    }
    else if (count > 47 && count < (48 + (size * 8))){
        ft_write(sig);
        count++;
        if (count == (48 + (size * 8))){
            ft_printf("\n");
            count = 0;
            size = 0;
        }
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