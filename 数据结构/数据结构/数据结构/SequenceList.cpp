#include "SequenceList.h"

FSequenceList::FSequenceList()
{
	
}

bool FSequenceList::InitList(int InMaxNumber)
{
	ArrayValue = new FSequenceValue[InMaxNumber];
	if (!ArrayValue)
	{
		cout<<"初始化顺序表失败，内存不足 分配失败"<<endl;
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
		cout << "添加失败，数量超出上限" << endl;
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
		cout << "插入失败，数量超出上限" << endl;
		return false;
	}

	if ((CurrentIndex+1) > MaxNumber)
	{
		cout << "插入失败，数量超出上限" << endl;
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
		cout << "没有查询到指定的数据" << endl;
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
		cout << "删除失败 Index,超出当前数据或者容器大小" << endl;
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
		cout << "获取失败 Index,超出当前数据或者容器大小" << endl;
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
		cout<<"当前Index:"<<i<<","<<"Value = "<< ArrayValue[i].Value<<endl;
	}
}
