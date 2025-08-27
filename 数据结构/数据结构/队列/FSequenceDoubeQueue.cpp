#include "FSequenceDoubeQueue.h"

FQueueNode* FSequenceDoubeQueue::GetFrontNode()
{
	if (QueueValues[Front])
	{
		return QueueValues[Front];
	}
	cout<<"��ǰͷ��ָ��Ϊ��"<<endl;
	return nullptr;
}

FQueueNode* FSequenceDoubeQueue::PopupFront()
{
	if (!QueueValues[Front])
	{
		cout << "��ǰͷ��ָ��Ϊ��" << endl;
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
		cout<<"����Ϊ��,�޷�����β����Ϣ"<<endl;
		return nullptr;
	}

	return QueueValues[Rear];
}

FQueueNode* FSequenceDoubeQueue::PopupRear()
{
	if (IsEmpty())
	{
		cout << "����Ϊ��,�޷�����β����Ϣ" << endl;
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
		cout<<"�����Node��Ч"<<endl;
		return false;
	}
	if (IsFull())
	{
		cout << "����Ķ�������" << endl;
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
		cout << "����Ķ�������" << endl;
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
		cout<<"���б������ǿյ�"<<endl;
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
			cout<<"��ǰIndex��"<<i<<"��Value="<< QueueValues[i]->Value<<endl;
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
