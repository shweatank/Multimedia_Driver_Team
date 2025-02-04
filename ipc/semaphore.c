#include <stdio.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SEM_KEY 1234

int main() {
    int semid;
    struct sembuf sem_op;

    // Create semaphore set
    semid = semget(SEM_KEY, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget failed");
        return 1;
    }

    // Initialize semaphore
    semctl(semid, 0, SETVAL, 1);  // Set initial semaphore value to 1

    pid_t pid = fork();
    if (pid == 0) {
        // Child process: Wait (decrement semaphore)
        sem_op.sem_num = 0;
        sem_op.sem_op = -1;  // P operation (wait)
        sem_op.sem_flg = 0;
        semop(semid, &sem_op, 1);  // Wait on semaphore
        printf("Child entered critical section\n");
        sleep(2);  // Simulate critical section work
        printf("Child leaving critical section\n");
        sem_op.sem_op = 1;  // V operation (signal)
        semop(semid, &sem_op, 1);  // Signal the semaphore
    } else {
        // Parent process: Wait (decrement semaphore)
        sem_op.sem_num = 0;
        sem_op.sem_op = -1;  // P operation (wait)
        sem_op.sem_flg = 0;
        semop(semid, &sem_op, 1);  // Wait on semaphore
        printf("Parent entered critical section\n");
        sleep(2);  // Simulate critical section work
        printf("Parent leaving critical section\n");
        sem_op.sem_op = 1;  // V operation (signal)
        semop(semid, &sem_op, 1);  // Signal the semaphore
        wait(NULL);  // Wait for child to finish
    }

    // Clean up
    semctl(semid, 0, IPC_RMID);  // Remove semaphore set
    return 0;
}
