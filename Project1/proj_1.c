#include"q.h"

int main()
{
	puts("hi");
	struct node** head;
	struct node*  item;
	initQueue(head);
	item = newItem();
	addQueue(head, item);
	delQueue(head);
	return 0;
}
