
/*
 ============================================================================
 Name        : test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
struct msgbuf
{
	long p;
	char mmsg[255];
};


int main(void)
{
	int ds;
	key_t key;
	key=ftok("test2.c", 'b');
	ds=msgget(key, IPC_CREAT|0666);
	struct msgbuf buf = {123, "Hello"};
	struct msgbuf buf2;
	msgsnd(ds,(void*) &buf, sizeof(struct msgbuf), 0);
	msgrcv(ds, (void*) &buf2, sizeof( buf2.mmsg), 321, 0);
	printf("%s\n", buf2.mmsg);
	msgctl(ds, IPC_RMID, 0);
	return 0;
}
