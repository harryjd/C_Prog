#pragma once
#include <malloc.h>

typedef struct linked_stack_node
{
	int x;
	int y;
	struct linked_stack_node * pnext;
}Linked_Stack_Node;


Linked_Stack_Node * CreateLinkedStack()
{
	Linked_Stack_Node * pHead = (Linked_Stack_Node*)malloc(sizeof(Linked_Stack_Node));
	if (pHead != NULL)
	{
		pHead->pnext = NULL;
		return(pHead);
	}
	else
		return NULL;
}

void DestroyLinkedStack(Linked_Stack_Node * pHead)
{
	if (pHead != NULL)
	{
		Linked_Stack_Node * pTop = pHead->pnext;
		while (pTop != NULL)
		{
			//逐个销毁栈中的元素
			pTop = pTop->pnext;
			free(pHead->pnext);
			pHead->pnext = pTop;
		}
		free(pHead);
	}
}

bool PushLinkedStack(Linked_Stack_Node * pHead, int x, int y)
{
	Linked_Stack_Node * pNewNode = (Linked_Stack_Node*)malloc(sizeof(Linked_Stack_Node));
	if ((pHead!=NULL) && (pNewNode != NULL))
	{
		pNewNode->x = x;
		pNewNode->y = y;
		pNewNode->pnext = pHead->pnext;
		pHead->pnext = pNewNode;
		return true;
	}
	else
		return false;
}

//
bool PopLinkedStack(Linked_Stack_Node * pHead, int *y, int *x)
{
	if ((pHead != NULL) && (pHead->pnext != NULL))
	{
		Linked_Stack_Node * pTop = pHead->pnext;
		*x = pTop->x;
		*y = pTop->y;
		pHead->pnext = pTop->pnext;
		free(pTop);
		return true;
	}
	else
		return false;
}