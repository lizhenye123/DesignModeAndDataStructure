#include "FHashTable.h"

int FHashTable::GetHashKey(int InValue)
{
	return InValue%MaxSize;
}

int FHashTable::GetNodeByValue(int InValue)
{
	int Key= GetHashKey(InValue);
	
	FHashNode*TempNode= ArrNode[Key]->NextNode;

	while (TempNode)
	{
		if (TempNode->Value == InValue)
		{
			return TempNode->Value;
		}
	}

	cout<<"没有找到对应Value的值 "<<InValue<<endl;
	return -1;
}

bool FHashTable::InsertValue(int InValue)
{
	int Key = GetHashKey(InValue);
	FHashNode* TempNode = ArrNode[Key]->NextNode;

	if (!TempNode)
	{
		ArrNode[Key]->NextNode = new FHashNode(InValue);
		return true;
	}

	while (TempNode->NextNode)
	{
		TempNode=TempNode->NextNode;
	}
	TempNode->NextNode = new FHashNode(InValue);

	return true;
}

bool FHashTable::DeleteNode(int InValue)
{
	int Key = GetHashKey(InValue);
	FHashNode* TempNode = ArrNode[Key];

	while (TempNode->NextNode)
	{
		if (TempNode->NextNode->Value == InValue)
		{
			FHashNode*DeleteNextNode = TempNode->NextNode;
			TempNode->NextNode = DeleteNextNode->NextNode;

			delete DeleteNextNode;
			DeleteNextNode=nullptr;
			return true;
		}
	}

	cout<<"没有找到对应的Node Value = "<<InValue<<endl;
	return false;
}

void FHashTable::DestoryHash()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		//删除链表里的元素
		if (ArrNode[i]->NextNode != nullptr)
		{
			FHashNode* TempNode = ArrNode[i]->NextNode;
			while (TempNode)
			{
				FHashNode*DeleteNextNode = TempNode;
				TempNode = TempNode->NextNode;

				delete DeleteNextNode;
				DeleteNextNode=nullptr;
			}
		}
		//删除某一个链表
		delete ArrNode[i];
		ArrNode[i]=nullptr;
	}
	//删除储存链表的这个数组 如果这销毁这个数组,数组就野了,析构的时候在销毁他
	//delete[] ArrNode;
}

void FHashTable::PrintHash()
{
	if(!IsValid()) return;


	for (int i = 0; i < MAX_SIZE; i++)
	{
		FHashNode* TempNode = ArrNode[i]->NextNode;
		int CurrentNumber=0;
		while (TempNode)
		{
			cout<<"第"<<i<<"个哈希链表中的第"<< CurrentNumber<<"Value="<< TempNode->Value<<endl;
			TempNode=TempNode->NextNode;
			CurrentNumber++;
		}
	}
}

bool FHashTable::IsValid()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (ArrNode[i]==nullptr)
		{
			return false;
		}
	}

	return true;
}	

bool FHashTable::IsEmpty()
{
	for (int i =0;i<MAX_SIZE;i++)
	{
		if (ArrNode[i]->NextNode!=nullptr)
		{
			return false;
		}
	}
	return true;
}
