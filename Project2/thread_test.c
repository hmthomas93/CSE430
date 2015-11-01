/* CSE 430 Project 1
Hailee Thomas & Sean Slamka*/

#include "threads.h"

//Declerations
void thread1();
void thread2();
void thread3();
void thread4();

int a, b;
TCB_t *header;


//First thread to increment x to infinity
void thread1()
{
	int x = 25;
	while (1)//Forver loop
	{
		printf(" %d ", x);
		x++;
		yield();//Yield to other threads
	}
}

//Thread 2 to decrement global variable a forever
void thread2()
{
	a = 250;
	while (1)// Forver Loop
	{
		printf(" %d ", a);
		a--;
		yield();//Yield to other threads
	}

}


//Thread 3 to print out random numbers for global variable b
void thread3()
{
	while (1)// Forever Loop
	{
		b = rand();
		printf(" %d ", b);
		yield();//Yield to other threads
	}
}

//thread 4 to add global variable a and b
void thread4()
{

	while (1)// Forver Loop
	{
		printf("add %d ", a + b);
		yield();//Yield to other threads
	}
}

//Main will start threads and then run the programming and go on forver.
int main()
{
	TCB_t *header;
	//Initilaize the Queue
	initQueue(&header);

	//Starting threads
	start_thread(thread1);
	start_thread(thread2);
	start_thread(thread3);
	start_thread(thread4);
	//Run the program
	run();
	return 0;
}
