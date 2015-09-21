#include"q.h"

int main()
{
	puts("hi");
	struct node** head = NULL;
	struct node*  item = NULL;
	initQueue(head);
	item = newItem();
	addQueue(head, item);
	return 0;
}
