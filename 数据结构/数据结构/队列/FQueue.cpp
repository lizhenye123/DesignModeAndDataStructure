#include "FQueue.h"

FListQueueNode* FListQueue::GetFrontNode()
{
	if (IsEmpty())
	{
		return nullptr;
	}
	return Front;
}

FListQueueNode* FListQueue::PopupFront()
{
	if (IsEmpty())
	{
		return nullptr;
	}

	if (Rear == Front)
	{
		Rear=nullptr;
	}

	FListQueueNode*ReturnValue = Front;
	Front=Front->NextNode;

	ReturnValue->NextNode=nullptr;

	return ReturnValue;
}

bool FListQueue::InsertRear(FListQueueNode* InNode)
{
	if (!InNode)
	{
		cout<<"插入的节点无效"<<endl;
		return false;
	}

	if (IsEmpty())
	{
		Front = InNode;

		if (InNode->NextNode != nullptr)
		{
			FListQueueNode* TempNode = InNode->NextNode;
			while (TempNode->NextNode)
			{
				TempNode = TempNode->NextNode;
			}

			Rear = TempNode;
			return true;
		}

		Rear = InNode;
		return true;
	}

	Rear->NextNode = InNode;
	if (InNode->NextNode != nullptr)
	{
		FListQueueNode*TempNode = InNode->NextNode;
		while (TempNode->NextNode)
		{
			TempNode = TempNode->NextNode;
		}
		Rear = TempNode;
		return true;
	}

	Rear=InNode;
	return true;
}

void FListQueue::ClearQueue()
{
	if (IsEmpty())
	{
		cout<<"队列本来就为空"<<endl;
		return;
	}

	FListQueueNode*DeleteNode = Front;

	while (DeleteNode)
	{
		FListQueueNode* TempDeleteNode = DeleteNode->NextNode == nullptr ? nullptr: DeleteNode->NextNode;
		delete DeleteNode;
		DeleteNode = TempDeleteNode;
	}

	Front = nullptr;
	Rear = nullptr;
}

void FListQueue::PrintQueue()
{	
	FListQueueNode* TempNode = Front;
	int CurrentIndex=0;
	while (TempNode)
	{
		cout<<"当前Index为："<<CurrentIndex<<"的Value = "<<TempNode->Value<<endl;
		TempNode=TempNode->NextNode;
		CurrentIndex++;
	}
}

bool FListQueue::IsEmpty()
{
	if (Front==nullptr)
	{
		return true;
	}
	return false;
}
