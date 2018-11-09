#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h> 
static void signalhandler(int signo){
	if(signo == SIGINT){
		char blame[15] = "Blame SIGINT\n";
		int fd = open("intercepter.txt",O_APPEND);
		write(fd,blame,14);
		close(fd);
		exit(0);
	}
	if(signo == SIGUSR1){
		printf("My father's name is %d",getppid());
	}
}
int main(){
	signal(SIGINT, signalhandler);
	signal(SIGUSR1,signalhandler);
	while(1){
		printf("Hi my name is %d\n",getpid());
		sleep(1);
	}
	return 0;
}
