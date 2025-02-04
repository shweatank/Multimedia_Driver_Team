#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Received SIGUSR1 signal\n");
    }
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
  
        signal(SIGUSR1, signal_handler);  
        printf("Child waiting for signal...\n");
        pause(); 
        printf("Child finished\n");
    } else {
     
        sleep(1); 
        kill(pid, SIGUSR1); 
        wait(NULL); 
    }

    return 0;
}
