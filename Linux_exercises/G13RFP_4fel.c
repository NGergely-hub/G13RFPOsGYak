#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>


int main(void) {



	pid_t pid =fork();

	if (pid == 0){
	printf("it is a parent process=> PPID=%d, this is child process=> PID=%d\n", getppid(), getpid()); // a használt rendszerhívások: getppid(), getpid()
	exit(0);
	}
	else {
		printf("it is a parent process => PID=%d\n", getpid());
		printf("wait till the child process is finished..\n");
		wait(0);
		printf("the child process is now finished.\n");
		} 

	
	return 0;
}

