all:
	gcc -Wall -o cFunct cFunct.c
	gcc -Wall -o pFunct pFunct.c
	./pFunct ls -l


tester:
	./pFunct cat cFunct.c
