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

	cout<<"û���ҵ���ӦValue��ֵ "<<InValue<<endl;
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

	cout<<"û���ҵ���Ӧ��Node Value = "<<InValue<<endl;
	return false;
}

void FHashTable::DestoryHash()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		//ɾ���������Ԫ��
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
		//ɾ��ĳһ������
		delete ArrNode[i];
		ArrNode[i]=nullptr;
	}
	//ɾ������������������ ����������������,�����Ұ��,������ʱ����������
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
			cout<<"��"<<i<<"����ϣ�����еĵ�"<< CurrentNumber<<"Value="<< TempNode->Value<<endl;
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
