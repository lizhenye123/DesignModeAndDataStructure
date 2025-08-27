#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#define MAX_NUMBER 10

struct FQueueNode
{
	FQueueNode(int InValue)
	{
		Value=InValue;
	}
	int Value;
};

struct FSequenceDoubeQueue
{
	FQueueNode* QueueValues[MAX_NUMBER];
	int Front=0;
	int Rear=-1;

	//获取头部数据
	FQueueNode*GetFrontNode();

	//弹出头部数据
	FQueueNode*PopupFront();

	//获取尾部数据
	FQueueNode* GetRearNode();

	//弹出尾部数据
	FQueueNode* PopupRear();

	//插入头部
	bool InsertFront(FQueueNode*InNode);

	//插入尾部
	bool InsertRear(FQueueNode* InNode);

	//清空队列
	bool ClearQueue();

	//打印队列的所有值
	void PrintQueue();

	//是否为空
	bool IsEmpty();

	//是否满了
	bool IsFull();
};

