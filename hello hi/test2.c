
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
	while((ds=msgget(key, 0))==-1);
	struct msgbuf buf;
	msgrcv(ds, (void*) &buf, sizeof(struct msgbuf), 123, 0);
	printf("%s\n", buf.mmsg);
	struct msgbuf buf2 = {321, "Hi"};
	msgsnd(ds,(void*) &buf2, sizeof(buf2.mmsg), 0);
	return 0;
}
