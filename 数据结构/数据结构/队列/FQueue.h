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

	//��ȡͷָ��
	FListQueueNode* GetFrontNode();

	//��������
	FListQueueNode*PopupFront();

	//���
	bool InsertRear(FListQueueNode*InNode);

	//���
	void ClearQueue();

	//��ӡ����
	void PrintQueue();

	//�Ƿ�Ϊ��
	bool IsEmpty();

};

