#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void){
	pid_t pid = fork();
	if(pid){
		write(1,"parent: \n",9);
		wait(NULL);
	}
	else{
		write(1,"child: ",7);
		execl("./prog","prog",NULL);
	}
	return 0;
}
