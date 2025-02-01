#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int main(void) {
    pid_t pid;
    char *argv[] = { "/bin/ls", "-l", NULL };
    
    posix_spawn_file_actions_t file_actions;
    posix_spawn_file_actions_init(&file_actions);
    
    int out_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd == -1) {
        perror("Failed to open output file");
        return 1;
    }
    
    posix_spawn_file_actions_adddup2(&file_actions, out_fd, STDOUT_FILENO);
    posix_spawn_file_actions_addclose(&file_actions, out_fd);
    
    posix_spawnattr_t attr;
    posix_spawnattr_init(&attr);
    
    sigset_t sigmask;
    sigemptyset(&sigmask);
    sigaddset(&sigmask, SIGINT);
    posix_spawnattr_setsigmask(&attr, &sigmask);
    
    int ret = posix_spawn(&pid, "/bin/ls", &file_actions, &attr, argv, environ);
    
    if (ret == 0) {
        printf("Spawned child process with PID: %d\n", pid);
        waitpid(pid, NULL, 0);
    } else {
        perror("posix_spawn failed");
    }

    posix_spawn_file_actions_destroy(&file_actions);
    posix_spawnattr_destroy(&attr);
    
    return 0;
}
