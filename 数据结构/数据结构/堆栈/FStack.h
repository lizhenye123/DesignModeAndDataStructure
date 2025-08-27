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

	//��ջ
	bool PushStack(int InValue);

	//��ջ
	bool PopStack(int &InValue);

	//��ȡջ��Ԫ��
	int GetRearValue();

	//��ȡ����
	int GetLength(){return Length+1;};

	//����ջ
	void DestoryStack();

	//��ӡ����
	void PrintStack();

	bool IsEmpty();

	bool IsFull();
};

