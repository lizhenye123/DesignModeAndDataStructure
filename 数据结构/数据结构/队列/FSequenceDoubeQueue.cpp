#include "FSequenceDoubeQueue.h"

FQueueNode* FSequenceDoubeQueue::GetFrontNode()
{
	if (QueueValues[Front])
	{
		return QueueValues[Front];
	}
	cout<<"当前头部指针为空"<<endl;
	return nullptr;
}

FQueueNode* FSequenceDoubeQueue::PopupFront()
{
	if (!QueueValues[Front])
	{
		cout << "当前头部指针为空" << endl;
		return nullptr;
	}

	FQueueNode* ReturnValue = QueueValues[Front];
	
	for (int i =Front;i<=Rear;i++)
	{
		QueueValues[i] = QueueValues[i+1];
	}
	QueueValues[Rear] = nullptr;
	Rear--;
	return ReturnValue;

}

FQueueNode* FSequenceDoubeQueue::GetRearNode()
{
	if (IsEmpty())
	{
		cout<<"队列为空,无法弹出尾部消息"<<endl;
		return nullptr;
	}

	return QueueValues[Rear];
}

FQueueNode* FSequenceDoubeQueue::PopupRear()
{
	if (IsEmpty())
	{
		cout << "队列为空,无法弹出尾部消息" << endl;
		return nullptr;
	}

	FQueueNode* ReturnValue = QueueValues[Rear];

	QueueValues[Rear]=nullptr;
	Rear--;

	return ReturnValue;
}

bool FSequenceDoubeQueue::InsertFront(FQueueNode* InNode)
{
	if (!InNode)
	{
		cout<<"插入的Node无效"<<endl;
		return false;
	}
	if (IsFull())
	{
		cout << "插入的队列满了" << endl;
		return false;
	}

	if (IsEmpty())
	{
		QueueValues[Front] = InNode;
		Rear++;
		return true;
	}

	for (int i = Rear;i>=0;i--)
	{
		QueueValues[i+1] = QueueValues[i];
	}

	QueueValues[Front] = InNode;
	Rear++;

	return true;
}

bool FSequenceDoubeQueue::InsertRear(FQueueNode* InNode)
{
	if (IsFull())
	{
		cout << "插入的队列满了" << endl;
		return false;
	}

	if (IsEmpty())
	{
		QueueValues[Front] = InNode;
		Rear++;
		return true;
	}

	Rear++;
	QueueValues[Rear] = InNode;
	return true;
}

bool FSequenceDoubeQueue::ClearQueue()
{
	if (IsEmpty())
	{
		cout<<"队列本来就是空的"<<endl;
		return true;
	}

	for (int i = 0;i<=Rear;i++)
	{
		if (QueueValues[i])
		{
			delete QueueValues[i];
			QueueValues[i]=nullptr;
		}
	}

	Rear=-1;
	return true;
}

void FSequenceDoubeQueue::PrintQueue()
{
	for (int i =0;i<=Rear;i++)
	{
		if (QueueValues[i])
		{
			cout<<"当前Index："<<i<<"的Value="<< QueueValues[i]->Value<<endl;
		}
	}
}

bool FSequenceDoubeQueue::IsEmpty()
{
	if (QueueValues[Front]==nullptr)
	{
		return true;
	}
	return false;
}

bool FSequenceDoubeQueue::IsFull()
{
	if (Rear == MAX_NUMBER - 1)
	{
		return true;
	}
	return false;
}
