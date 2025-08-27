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

	//��ȡͷ������
	FQueueNode*GetFrontNode();

	//����ͷ������
	FQueueNode*PopupFront();

	//��ȡβ������
	FQueueNode* GetRearNode();

	//����β������
	FQueueNode* PopupRear();

	//����ͷ��
	bool InsertFront(FQueueNode*InNode);

	//����β��
	bool InsertRear(FQueueNode* InNode);

	//��ն���
	bool ClearQueue();

	//��ӡ���е�����ֵ
	void PrintQueue();

	//�Ƿ�Ϊ��
	bool IsEmpty();

	//�Ƿ�����
	bool IsFull();
};

