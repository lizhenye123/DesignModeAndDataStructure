#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
#define MAX_SIZE 10

struct FStackNode
{
	FStackNode(int InValue)
	{
		Value = InValue;
	}
	//FStackNode*NextNode=nullptr;
	//FStackNode*LastNode=nullptr;
	int Value;
};

struct FStack
{
	FStackNode*ArrNode[MAX_SIZE];
	int Length=-1;

	//入栈
	bool PushStack(int InValue);

	//出栈
	bool PopStack(int &InValue);

	//获取栈顶元素
	int GetRearValue();

	//获取长度
	int GetLength(){return Length+1;};

	//销毁栈
	void DestoryStack();

	//打印所有
	void PrintStack();

	bool IsEmpty();

	bool IsFull();
};

