#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char command[250];
	
	strcpy(command, argv[1]);

	for(int i = 2; i < argc; i++) {
		strcat(command, " ");
		strcat(command, argv[i]);
	}
	system(command);

	return 0;
}
