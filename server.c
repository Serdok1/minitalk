#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void binaryToAscii(char binary[], char ascii[]) {
    int i, decimal, length, k;
    length = strlen(binary);
    
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
}

static void     action(int sig, siginfo_t *info, void *context){
    
}

int main(int argc, char *argv[]) {
    struct sigaction s_sigaction;
    s_sigaction.sa_flags = SA_SIGINFO;
    s_sigaction.sa_sigaction = action;
    sigaction(SIGUSR1, &s_sigaction, 0);
    sigaction(SIGUSR2, &s_sigaction, 0);
    printf("PID: %d", getpid());
    while(1)
    {
        pause();
    }
}