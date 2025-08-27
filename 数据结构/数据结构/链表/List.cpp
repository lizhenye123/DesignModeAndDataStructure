#include "List.h"

#define CHECK_NODE_IS_VALID(Node)\
if (!InNode)\
{\
	cout << "InNode��Ч����ʧ��" << endl;\
	return false;\
}

bool FListNode::FrontInsert(FListNode* InNode)
{
	CHECK_NODE_IS_VALID(InNode)

	if (InNode->NextNode)
	{
		FListNode*InNodeNext = InNode->NextNode;
		while (InNodeNext->NextNode)
		{
			InNodeNext = InNodeNext->NextNode;
		}
		InNodeNext->NextNode = NextNode;
		this->NextNode = InNode;

		return true;
	}

	InNode->NextNode = NextNode;
	NextNode = InNode;

	return true;
}

bool FListNode::BrackInsert(FListNode* InNode)
{
	CHECK_NODE_IS_VALID(InNode)

	FListNode*TempNode=this;

	while (TempNode->NextNode)
	{
		TempNode = TempNode->NextNode;
	}

	TempNode->NextNode = InNode;

	return true;
}

bool FListNode::InsertByIndex(FListNode* InNode, int InIndex)
{
	CHECK_NODE_IS_VALID(InNode)

	int CurrentIndex = 0;
	FListNode*LastNode = this;

	if (InIndex<=0)
	{
		cout<<"�޷�����С�ڵ���0������λ��"<<endl;
		return false;
	}


	//-1�Ǳ����˵�ǰҪ���ҵ�λ�õ���һ��,Ҫ��Ȼû����
	while (LastNode && CurrentIndex < (InIndex - 1))
	{
		LastNode = LastNode->NextNode;
		CurrentIndex++;
	}

	if (LastNode && CurrentIndex<=InIndex-1)
	{
		//��ǰҪ�����滻���Ǹ�Node
		FListNode* InsertNode = LastNode->NextNode;

		if (InNode->NextNode)
		{
			//��ǰ������Ҫ�����Node������һ����Ч
			FListNode*InNodeNext = InNode->NextNode;
			
			//���Ҳ���Ľڵ�����һ���ڵ�
			while (InNodeNext->NextNode)
			{
				InNodeNext = InNodeNext->NextNode;
			}

			//��ԭ���Ĳ��뵽InNode�������������
			LastNode->NextNode = InNode;
			InNodeNext->NextNode = InsertNode;
			return true;
		}

		LastNode->NextNode = InNode;
		InNode->NextNode = InsertNode;
		return true;
	}

	cout<<"����������������е�λ��"<<endl;
	return false;
}

bool FListNode::GetValueByIndex(int InIndex, int& OutValue)
{	
	int CurrentIndex=0;
	FListNode*TempNode = this;
	OutValue=-1;

	while (TempNode&& CurrentIndex < InIndex)
	{
		TempNode = TempNode->NextNode;
		CurrentIndex++;
	}

	if (TempNode==nullptr)
	{
		cout<<"��ǰ��������List�Ĵ�С ��ǰIndex = "<<CurrentIndex<<"�����Index= "<<InIndex << endl;
		return false;
	}

	OutValue = TempNode->Value;

	return true;
}

FListNode* FListNode::GetListNodeByValue(int InValue)
{
	FListNode* TempNode = this->NextNode;

	while (TempNode)
	{
		if (TempNode->Value == InValue)
		{
			return TempNode;
		}
		TempNode = TempNode->NextNode;
	}

	cout<<"û���ҵ�����������ListNode Value = "<<InValue<<endl;
	return nullptr;
}

bool FListNode::DeleteNodeByIndex(int InIndex)
{
	if (InIndex<=0)
	{
		cout<<"�޷�ɾ�����ڵ�,�Ѿ����ڵ���ǰ�Ľڵ�"<<endl;
		return false;
	}

	int CurrentIndex = 0;
	FListNode*LastNode = this;

	while (LastNode->NextNode && CurrentIndex< InIndex-1)
	{
		LastNode = LastNode->NextNode;
		CurrentIndex++;
	}

	if (!LastNode->NextNode)
	{
		cout<<"ɾ����Index������Χ ��ǰIndex="<<CurrentIndex<<"������Index"<<InIndex<<endl;
		return false;
	}
	FListNode*DeleteNode= LastNode->NextNode;
	LastNode->NextNode = DeleteNode->NextNode;

	delete DeleteNode;
	DeleteNode=nullptr;
	return true;
}

bool FListNode::DeleteNodeByNode(FListNode* InNode)
{
	CHECK_NODE_IS_VALID(InNode)

	if (InNode==this)
	{
		DestoryList();
		return true;
	}

	FListNode* TempNode = this;

	while (TempNode->NextNode)
	{
		if (InNode == TempNode->NextNode)
		{
			break;
		}
		TempNode=TempNode->NextNode;
	}

	if (!TempNode->NextNode)
	{
		cout<<"û�в��ҵ���Ӧ��Node"<<endl;
		return false;
	}

	TempNode->NextNode = InNode->NextNode;
	delete InNode;
	InNode=nullptr;

	return true;

}

bool FListNode::DeleteNodeByValue(const int& InValue)
{
	FListNode* TempNode = this->NextNode;

	if (this->NextNode->Value == InValue)
	{
		this->NextNode = TempNode->NextNode;

		delete TempNode;
		TempNode =nullptr;
		return true;
	}

	while (TempNode->NextNode)
	{
		if (TempNode->NextNode->Value == InValue)
		{
			FListNode* DeleteNode = TempNode->NextNode;
			TempNode->NextNode = DeleteNode->NextNode;

			delete DeleteNode;
			DeleteNode=nullptr;
			return true;
		}

		TempNode = TempNode->NextNode;
	}

	cout<<"û���ҵ���ӦValue��Node"<<endl;
	return false;
}

void FListNode::DestoryList()
{
	FListNode* ListNode = this->NextNode;

	while (ListNode)
	{
		FListNode*DestoryNode = ListNode;
		ListNode = ListNode->NextNode;

		delete DestoryNode;
		DestoryNode=nullptr;
	}

	this->NextNode=nullptr;
}

void FListNode::ListPrint()
{	
	FListNode*TempNode = this->NextNode;
	int Index = 1;

	if (TempNode==nullptr)
	{
		cout << "û��ֵ" << endl;
		return;
	}

	while (TempNode)
	{
		cout<<"��ǰIndex = "<<Index<<" | Value = "<< TempNode->Value<<endl;
		TempNode=TempNode->NextNode;
		Index++;
	}
}

