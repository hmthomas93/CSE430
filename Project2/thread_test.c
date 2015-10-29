/* CSE 430 Project 1
Hailee Thomas & Sean Slamka*/

#include "threads.h"

void thread1();
void thread2();
void thread3();
void thread4();

int a, b;
TCB_t *header;

void thread1()
{
	int x = 25;
	while (1)
	{
		printf(" %d ", x);
		x++;
		yield();
	}
}

void thread2()
{
	a = 250;
	while (1)
	{
		printf(" %d ", a);
		a--;
		yield();
	}

}

void thread3()
{
	while (1)
	{
		b = rand();
		printf(" %d ", b);
		yield();
	}
}

void thread4()
{
	
	while (1)
	{
		printf("add %d ", a + b);
		yield();
	}
}

int main()
{
	TCB_t *header;
	initQueue(&header);

	start_thread(thread1);
	start_thread(thread2);
	start_thread(thread3);
	start_thread(thread4);

	run();
	return 0;
}
