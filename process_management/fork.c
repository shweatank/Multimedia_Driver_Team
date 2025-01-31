#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#if 1

int main(void){
	pid_t pid = fork();
	printf("hello\n");
	int status;
	if(pid>0){
		printf("parent: %d ",wait(&status));
		printf("%d\n",WEXITSTATUS(status));
	}
	else{
	      printf("child: \n");
	}
	
	return 0;
}

#else

int main(void){
	int count =0;
child:
	count++;
	pid_t pid = fork();
	if(count<5 && !pid)goto child;
	else{
		if(pid)
		printf("pid%d: %d\n",count,getpid());
		wait(NULL);
	       	return 0;
	}
}

#endif
