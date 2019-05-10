// WalkMap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedStack.h"
#define MapLen 6
int AMap[MapLen][MapLen] = {
	{ 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 0, -3, 1 },
	{ 1, 1, 1, 1, 1, 1 } };
/*
��ͼ�1�����ϰ���2������·��0��������
�̶���㣺<1,1>
�߹��ĵ㣺-1
�յ㣺��ͼ�ϱ�-3
*/
void Demo_LinkedStack()
{
	Linked_Stack_Node * pHead = CreateLinkedStack();
	if (pHead != NULL)
	{
		if (PushLinkedStack(pHead, 1, 1))
		{
			PushLinkedStack(pHead, 2, 3);
			int x = 0, y = 0;
			if (PopLinkedStack(pHead, &x, &y))
			{
				printf("\nx=%d, y=%d\n", x, y);
			}
			if (PopLinkedStack(pHead, &x, &y))
			{
				printf("\nx=%d, y=%d\n", x, y);
			}
		}
		DestroyLinkedStack(pHead);
	}
}

//��ӡ��ͼ
void printMyMap()
{
	int x = 0, y = 0;
	for (y = 0; y<MapLen; y++)
	{
		printf("\n");
		for (x = 0; x<MapLen; x++)
		{
			switch (AMap[y][x])
			{
			case 0:
			case 2:
			case -2:
				printf("  ");
				break;
			case 1:
				printf(" #");
				break;
			case -1:
			case -3:
				printf(" *");
				break;
			default:
				break;
			};
		}
	}
}

void WalkMap(int y, int x, Linked_Stack_Node * pHead)
{
	if ((AMap[y][x] == 0)||(AMap[y][x] == -1))
	{
		if (AMap[y][x]==0)
			AMap[y][x] = -1;//��ǵ�ǰ��Ϊ����
		PushLinkedStack(pHead, x, y);//��ջ����ʾ����·������
		//��4��������ȥ��̽��һ��
		if ((AMap[y - 1][x] == 0)||(AMap[y - 1][x] == -3))
		{
			//��
			WalkMap(y - 1, x, pHead);
		}
		else if ((AMap[y][x+1] == 0)||(AMap[y][x + 1] == -3))
		{
			//��
			WalkMap(y, x + 1, pHead);
		}
		else if ((AMap[y + 1][x] == 0)||(AMap[y + 1][x] == -3))
		{
			//��
			WalkMap(y + 1, x, pHead);
		}
		else if ((AMap[y][x - 1] == 0)||(AMap[y][x - 1] == -3))
		{
			//��
			WalkMap(y, x - 1, pHead);
		}
		else
		{
			//�ĸ������߲���ȥ
			AMap[y][x] = 2;//��ǵ�ǰ��Ϊ��·
			int ly, lx;
			PopLinkedStack(pHead, &ly, &lx);
			PopLinkedStack(pHead, &ly, &lx);
			WalkMap(ly, lx, pHead);
		}
	}
	if (AMap[y][x] == -3)
	{
		printf("\n�����յ�\n");
	}
	if ((x == 1) && (y == 1) && (AMap[y][x] == 2))
	{
		printf("\n�޷��ҵ�·��\n");
	}
}

int main()
{
	printMyMap();
	Linked_Stack_Node * pHead = CreateLinkedStack();
	int x = 1, y = 1;
	WalkMap(y, x, pHead);

	DestroyLinkedStack(pHead);
	printMyMap();
	getchar();
    return 0;
}

