/* CSE 430 Project 2
Hailee Thomas & Sean Slamka
Description: This file implements standard queuing function using routines. */

//include header files
#include <stdio.h>
#include "tcb.h"

//function definitions
void initQueue(TCB_t **head);
TCB_t newN();
void addQueue(TCB_t **head, TCB_t *item);
TCB_t* delQueue(TCB_t **head);
void rotateQ(TCB_t **head);


//creates an empty queue, pointed to by the variable head
void initQueue(TCB_t **head)
{
	*head = NULL;
}

//returns a pointer to a new q-element
TCB_t newN()
{
	TCB_t newNode;

	newNode.next = NULL;
	newNode.prev = NULL;
	
	return newNode;
}

//adds a queue item, pointed to by "item", to the queue pointed to by head
void addQueue(TCB_t **head, TCB_t *item)
{
	//if empty, point to self
	if (*head == NULL)
	{
		item->next = item;
		item->prev = item;

		*head = item;
	}
	//else place at end of circular queue
	else
	{
		(*head)->prev->next = item;
		item->prev = (*head)->prev;
		item->next = *head;
		(*head)->prev = item;
	}
}

//deletes an item from head and returns a pointer to the deleted item
TCB_t* delQueue(TCB_t **head)
{
	TCB_t *temp;
	
	//if queue is empty
	if (*head == NULL)
		return NULL;

	//if there is one element
	else if ((*head)->next == *head)
	{
		temp = *head;
		*head == NULL;
	}

	//else if there are many elements
	else
	{
		temp = *head;

		(*head)->next->prev = (*head)->prev;
		(*head)->prev->next = (*head)->next;
		(*head) = (*head)->next;
	}

	//return deleted item
	return temp;
}

//moves the header pointer to the next element in the queue
void rotateQ(TCB_t **head)
{
	*head = (*head)->next;
}
