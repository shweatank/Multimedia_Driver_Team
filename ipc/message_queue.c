#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MSG_KEY 1234

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = MSG_KEY;
    int msgid;
    struct msg_buffer message;

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process: Receive message
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Child received: %s\n", message.msg_text);
    } else {
        // Parent process: Send message
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from parent via message queue");
        msgsnd(msgid, &message, sizeof(message), 0);
        wait(NULL);  // Wait for child to finish
    }

    // Clean up the message queue
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

