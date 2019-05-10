// WalkMap.cpp : Defines the entry point for the console application.
// 用递归的思想去在地图中搜寻路径，用栈来保存走过的点，当前点push来入栈，要退回上一个点就pop，然后尝试pop出来的点

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
地图里：1——障碍；2——死路；0——空闲
固定起点：<1,1>
走过的点：-1
终点：地图上标-3
*/
//打印地图
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
			AMap[y][x] = -1;//标记当前点为已走
		PushLinkedStack(pHead, x, y);//入栈，表示加入路径当中
		//从4个方向逐步去试探下一步
		if ((AMap[y - 1][x] == 0)||(AMap[y - 1][x] == -3))
		{
			//上
			WalkMap(y - 1, x, pHead);
		}
		else if ((AMap[y][x+1] == 0)||(AMap[y][x + 1] == -3))
		{
			//右
			WalkMap(y, x + 1, pHead);
		}
		else if ((AMap[y + 1][x] == 0)||(AMap[y + 1][x] == -3))
		{
			//下
			WalkMap(y + 1, x, pHead);
		}
		else if ((AMap[y][x - 1] == 0)||(AMap[y][x - 1] == -3))
		{
			//左
			WalkMap(y, x - 1, pHead);
		}
		else
		{
			//四个方向都走不下去
			AMap[y][x] = 2;//标记当前点为死路
			int ly, lx;
			PopLinkedStack(pHead, &ly, &lx);
			PopLinkedStack(pHead, &ly, &lx);
			WalkMap(ly, lx, pHead);
		}
	}
	if (AMap[y][x] == -3)
	{
		printf("\n到达终点\n");
	}
	if ((x == 1) && (y == 1) && (AMap[y][x] == 2))
	{
		printf("\n无法找到路径\n");
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

