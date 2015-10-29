/* CSE 430 Project 1
Hailee Thomas & Sean Slamka*/

#include "q.h"

//global header pointer
extern TCB_t *header;
void start_thread(void(*function)(void));
void yield();
void run();


void start_thread(void(*function)(void))
{
	int *stack = (int *)malloc(8192);
	TCB_t *tcb = (TCB_t*)malloc(sizeof(TCB_t));
	init_TCB(tcb, function, stack, 8192);
	addQueue(&header, tcb);
}

void yield()
{
	ucontext_t *pthread, *nthread;
	pthread = &(header->context);

	rotateQ(&header);
	nthread = &(header->context);
	swapcontext(pthread, nthread);
}

void run()
{
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	swapcontext(&parent, &(header->context));  // start the first thread
}


