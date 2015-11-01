/* CSE 430 Project 1
Hailee Thomas & Sean Slamka*/

#include "q.h"

//global header pointer
//declaire functions
extern TCB_t *header;
void start_thread(void(*function)(void));
void yield();
void run();

//Function to start threads using a function pointer as parameter
void start_thread(void(*function)(void))
{
	//Creat the stack
	int *stack = (int *)malloc(8192);
	TCB_t *tcb = (TCB_t*)malloc(sizeof(TCB_t));
	init_TCB(tcb, function, stack, 8192);
	addQueue(&header, tcb);//Add the Queue to the stack
}

//Function to start yielding for multi threads
void yield()
{
	ucontext_t *pthread, *nthread;
	pthread = &(header->context);
	//Rotate the Queue
	rotateQ(&header);
	nthread = &(header->context);
	swapcontext(pthread, nthread);
}

//Run function to get threads going
void run()
{
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	swapcontext(&parent, &(header->context));  // start the first thread
}


