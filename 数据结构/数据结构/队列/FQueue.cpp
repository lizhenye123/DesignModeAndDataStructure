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
		cout<<"����Ľڵ���Ч"<<endl;
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
		cout<<"���б�����Ϊ��"<<endl;
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
		cout<<"��ǰIndexΪ��"<<CurrentIndex<<"��Value = "<<TempNode->Value<<endl;
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
