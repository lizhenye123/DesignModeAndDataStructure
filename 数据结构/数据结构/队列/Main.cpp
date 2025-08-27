#pragma once
#include "FSequenceDoubeQueue.h"
#include "FQueue.h"

int main()
{
	/*FSequenceDoubeQueue*DoubleQueue = new FSequenceDoubeQueue();

	for (int i=0;i<5;i++)
	{
		FQueueNode* Node = new FQueueNode(i);
		DoubleQueue->InsertRear(Node);
	}

	FQueueNode*TempNode = DoubleQueue->GetFrontNode();
	TempNode = DoubleQueue->GetRearNode();
	DoubleQueue->PopupFront();
	DoubleQueue->PopupRear();
	DoubleQueue->ClearQueue()

	DoubleQueue->PrintQueue();*/

	FListQueue* ListQueue = new FListQueue();

	for (int i =0;i<5;i++)
	{
		ListQueue->InsertRear(new FListQueueNode(i));
	}
	FListQueueNode*Node = new FListQueueNode(10);
	FListQueueNode* Node1 = new FListQueueNode(11);
	Node->NextNode = Node1;
	ListQueue->InsertRear(Node);

	Node1 = ListQueue->GetFrontNode();
	Node1 = ListQueue->PopupFront();

	ListQueue->ClearQueue();

	ListQueue->PrintQueue();

	system("pause");
	return 0;
}