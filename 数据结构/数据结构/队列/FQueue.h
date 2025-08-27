#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

struct FListQueueNode
{
	FListQueueNode(int InValue)
	{
		Value=InValue;
	}
	int Value;
	FListQueueNode*NextNode=nullptr;
}typedef FList;

struct FListQueue
{
	FList* List=nullptr;
	FListQueueNode*Front =nullptr;
	FListQueueNode*Rear=nullptr;

	//获取头指针
	FListQueueNode* GetFrontNode();

	//弹出队列
	FListQueueNode*PopupFront();

	//入队
	bool InsertRear(FListQueueNode*InNode);

	//清空
	void ClearQueue();

	//打印所有
	void PrintQueue();

	//是否为空
	bool IsEmpty();

};

