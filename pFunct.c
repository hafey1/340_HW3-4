#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	
	pid_t pid;
	int status;

	char *childArg[argc + 1];
	childArg[argc + 1] = NULL;
	childArg[0] = "./cFunct";

	for (int i = 1; i < argc + 1; i++) {
                childArg[i] = argv[i];
        }

	//this is a parent not a child
	if ((pid = fork()) < 0) {
		printf("There was an error with the forking\n");
		exit(1);	
	}
	//this is a child
	else if (pid == 0) {
		//take the length of argv divided by the size of a char pointer?

		if (execvp(childArg[0], childArg) < 0){
			printf("There is something wrong with the child\n");
			exit(1);
		}
	}
	else {
		while (wait(&status) != pid); 
	}

	return 0;
}
