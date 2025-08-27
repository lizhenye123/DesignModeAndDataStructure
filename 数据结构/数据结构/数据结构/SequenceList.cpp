#include "SequenceList.h"

FSequenceList::FSequenceList()
{
	
}

bool FSequenceList::InitList(int InMaxNumber)
{
	ArrayValue = new FSequenceValue[InMaxNumber];
	if (!ArrayValue)
	{
		cout<<"��ʼ��˳���ʧ�ܣ��ڴ治�� ����ʧ��"<<endl;
		return false;
	}
	CurrentIndex = -1;
	MaxNumber = InMaxNumber;
	return true;
}

bool FSequenceList::AddValue(const FSequenceValue& InValue)
{
	if (CurrentIndex >= MaxNumber-1)
	{
		cout << "���ʧ�ܣ�������������" << endl;
		return false;
	}

	CurrentIndex++;
	ArrayValue[CurrentIndex] = InValue;
	return true;
}

bool FSequenceList::InsertValue(const FSequenceValue& InValue, const int& InIndex)
{
	if (InIndex > CurrentIndex || InIndex >= MaxNumber)
	{
		cout << "����ʧ�ܣ�������������" << endl;
		return false;
	}

	if ((CurrentIndex+1) > MaxNumber)
	{
		cout << "����ʧ�ܣ�������������" << endl;
		return false;
	}

	for (int i = CurrentIndex; i >= InIndex; i--)
	{
		ArrayValue[i+1] = ArrayValue[i];
	}
	ArrayValue[InIndex] = InValue;
	CurrentIndex++;
	return true;
}

bool FSequenceList::DeleteValue(const FSequenceValue& InValue)
{
	int TargetIndex=-1;
	for (int i =0;i<=CurrentIndex;i++)
	{
		if (ArrayValue[i].Value == InValue.Value)
		{
			TargetIndex = i;
			break;
		}
	}

	if(TargetIndex == -1)
	{
		cout << "û�в�ѯ��ָ��������" << endl;
		return false;
	}

	for (int i = TargetIndex; i < CurrentIndex; i++)
	{
		ArrayValue[i] = ArrayValue[i+1];
	}
	CurrentIndex--;
	return true;
}

bool FSequenceList::DeleteValue(const int& InIndex)
{
	if (InIndex > CurrentIndex || InIndex >= MaxNumber)
	{
		cout << "ɾ��ʧ�� Index,������ǰ���ݻ���������С" << endl;
		return false;
	}

	for (int i = InIndex; i < CurrentIndex; i++)
	{
		ArrayValue[i] = ArrayValue[i+1];
	}
	CurrentIndex--;
	return true;
}

bool FSequenceList::GetValueByIndex(const int& InIndex, FSequenceValue& SequenceValue)
{
	if (InIndex > CurrentIndex || InIndex >= MaxNumber)
	{
		cout << "��ȡʧ�� Index,������ǰ���ݻ���������С" << endl;
		return false;
	}

	SequenceValue = ArrayValue[InIndex];
	return true;
}

int FSequenceList::FindValue(const FSequenceValue& SequenceValue)
{
	for (int i =0;i<=CurrentIndex;i++)
	{
		if (ArrayValue[i].Value == SequenceValue.Value)
		{
			return i;
		}
	}

	return -1;
}

void FSequenceList::PrintList()
{
	for (int i = 0; i <= CurrentIndex; i++)
	{
		cout<<"��ǰIndex:"<<i<<","<<"Value = "<< ArrayValue[i].Value<<endl;
	}
}
