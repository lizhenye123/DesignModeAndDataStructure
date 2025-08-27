#include "FStack.h"

bool FStack::PushStack(int InValue)
{
	if (IsFull())
	{
		cout<<"ջ�Ѿ�����"<<endl;
		return false;
	}

	FStackNode*TempNode = new FStackNode(InValue);
	Length++;
	ArrNode[Length] = TempNode;
	return true;
}

bool FStack::PopStack(int& InValue)
{
	if (IsEmpty())
	{
		cout<<"ջΪ��"<<endl;
		return false;
	}

	InValue = ArrNode[Length]->Value;
	delete ArrNode[Length];
	ArrNode[Length] = nullptr;
	Length--;

	return true;
}

int FStack::GetRearValue()
{
	if (IsEmpty())
	{
		cout << "ջΪ��" << endl;
		return false;
	}

	return ArrNode[Length]->Value;
}

void FStack::DestoryStack()
{
	for (int i =0;i<=Length;i++)
	{
		delete ArrNode[i];
		ArrNode[i]=nullptr;
	}
	delete[] ArrNode;
	Length = -1;
}

void FStack::PrintStack()
{
	for (int i = 0; i <= Length; i++)
	{
		cout<<"��ǰIndex:"<<i<<"��Value = "<<ArrNode[i]->Value<<endl;
	}
}

bool FStack::IsEmpty()
{
	if (Length==-1)
	{
		return true;
	}
	return false;
}

bool FStack::IsFull()
{
	if (Length == MAX_SIZE-1)
	{
		return true;
	}

	return false;
}
