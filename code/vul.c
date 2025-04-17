#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void grantAccess() {
    printf("Access granted! You are now root.\n");
    system("/bin/sh"); // Opens a shell (simulating privilege escalation)
}

void vulnerableFunction() {
    char buffer[64]; // Fixed-size buffer
    printf("Enter your input: ");
    gets(buffer);  // Dangerous function - NO bounds checking!
    printf("You entered: %s\n", buffer);
}

int main() {
    setuid(0); // Simulating a SUID binary (privileged execution)
    vulnerableFunction();
    printf("Execution completed safely.\n");
    return 0;
}

