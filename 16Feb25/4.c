//Implement a state machine where different states execute different functions.
#include<stdio.h>
void idle(){printf("System is in IDLE state\n");}
void running(){printf("System is in RUNNING state\n");}
void stopped(){printf("System is STOPPED\n");}
int main()
{
	void(*StateMachine[])()={idle,running,stopped};
	int state;
	printf("Enter state:\n0.IDLE\n1.RUNNING\n2.STOPPED\n");
	scanf("%d",&state);
	StateMachine[state]();
	return 0;
}
