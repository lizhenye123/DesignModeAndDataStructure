#include "DoubleList.h"

#define CHECK_NODE_IS_VALID(InNode)\
if (!InNode)\
{\
	cout << "InNode��Ч����ʧ��" << endl;\
	return false;\
}

FDoubleListNode::FDoubleListNode(const int& InValue)
{
	Value = InValue;
}

bool FDoubleListNode::FrontInsert(FDoubleListNode* InNode)
{
	CHECK_NODE_IS_VALID(InNode)

	FDoubleListNode*TempNode = this->NextNode;
	
	if (InNode->NextNode)
	{	
		FDoubleListNode*InNodeNext = InNode->NextNode;
		while (InNodeNext->NextNode)
		{
			InNodeNext= InNodeNext->NextNode;
		}

		InNodeNext->NextNode = this->NextNode;
		if(this->NextNode) this->NextNode->LastNode = InNodeNext;

		this->NextNode = InNode;
		InNode->LastNode = this;
		return true;
	}
	
	InNode->NextNode = this->NextNode;
	if (this->NextNode) this->NextNode->LastNode = InNode;
	this->NextNode=InNode;
	return true;
}

bool FDoubleListNode::BrackInsert(FDoubleListNode* InNode)
{
	CHECK_NODE_IS_VALID(InNode)

	if (!this->NextNode)
	{
		this->NextNode=InNode;
		return true;
	}

	FDoubleListNode* InNodeNext = this->NextNode;

	while (InNodeNext->NextNode)
	{
		InNodeNext = InNodeNext->NextNode;
	}

	InNodeNext->NextNode = InNode;
	InNode->LastNode = InNodeNext;

	return true;
}

bool FDoubleListNode::InsertNodeByIndex(FDoubleListNode* InNode, const int& InIndex)
{
	CHECK_NODE_IS_VALID(InNode)

	if(InIndex<=0)
	{
		cout<<"�޷�����С�ڵ���0��Index"<<endl;
		return false;
	}

	FDoubleListNode*TempNode = this->NextNode;
	int CurrentIndex = 1;

	while (TempNode && CurrentIndex<InIndex)
	{
		TempNode = TempNode->NextNode;
		CurrentIndex++;
	}

	if(CurrentIndex != InIndex|| TempNode == nullptr)
	{
		cout << "����ʧ��,�o���ҵ���ǰ�ģɣ����" << endl;
		return false;
	}

	//����ҵ�������ڵ�������û�еĻ�
	if (!TempNode->NextNode)
	{
		TempNode->NextNode = InNode;
		InNode->LastNode = TempNode;
		return true;
	}

	//Ҫ������Ǹ�������滹�ж����Ļ�
	if (InNode->NextNode)
	{
		FDoubleListNode* InNodeNext = InNode->NextNode;

		while (InNodeNext->NextNode)
		{
			InNodeNext = InNodeNext->NextNode;
		}

		InNode->LastNode = TempNode->LastNode;
		TempNode->LastNode->NextNode = InNode;

		TempNode->LastNode = InNodeNext;
		InNodeNext->NextNode = TempNode;

		return true;
	}

	InNode->NextNode = TempNode;
	InNode->LastNode = TempNode->LastNode;

	TempNode->LastNode->NextNode = InNode;
	TempNode->LastNode = InNode;
	return true;
}

FDoubleListNode* FDoubleListNode::GetNodeByIndex(const int& InIndex)
{	
	if (InIndex<=0)
	{
		cout<<"�ڳ��Ի�ȡ���ڵ������Ч�ڵ�"<<endl;
		return nullptr;
	}

	FDoubleListNode*TempNode = this->NextNode;
	int CurrentIndex=1;
	while (TempNode)
	{
		if (CurrentIndex == InIndex)
		{
			return TempNode;
		}

		CurrentIndex++;
		TempNode = TempNode->NextNode;
	}

	cout<<"û���ҵ���Ӧ��Index��Node �����IndexΪ:"<<InIndex<<" ����IndexΪ��"<<CurrentIndex;
	return nullptr;
}

FDoubleListNode* FDoubleListNode::GetNodeByValue(const int& InValue)
{
	FDoubleListNode* TempNode = this->NextNode;

	while (TempNode)
	{
		if (TempNode->Value == InValue)
		{
			return TempNode;
		}
		TempNode=TempNode->NextNode;
	}

	cout<<"û���ҵ�ValueΪ"<<InValue<<"��Node"<<endl;
	return nullptr;
}

bool FDoubleListNode::DeleteNodeByIndex(const int& InIndex)
{
	if (InIndex <= 0)
	{
		cout << "�ڳ���ɾ�����ڵ������Ч�ڵ�,���ڵ���ʹ������" << endl;
		return false;
	}

	FDoubleListNode* TempNode = this->NextNode;
	int CurrentIndex = 1;

	while (TempNode)
	{
		if (CurrentIndex == InIndex)
		{
			TempNode->LastNode->NextNode = TempNode->NextNode;
			if (TempNode->NextNode) TempNode->NextNode->LastNode = TempNode->LastNode;

			delete TempNode;
			TempNode = nullptr;
			return true;
		}
		CurrentIndex++;
		TempNode= TempNode->NextNode;
	}

	cout << "û���ҵ���Ӧ��Index��Node �����IndexΪ:" << InIndex << " ����IndexΪ��" << CurrentIndex;
	return false;
}

bool FDoubleListNode::DeleteNodeByNode(FDoubleListNode* InNode)
{
	CHECK_NODE_IS_VALID(InNode)

	if (InNode == this)
	{
		cout << "�ڳ���ɾ�����ڵ������Ч�ڵ�,���ڵ���ʹ������" << endl;
		return false;
	}

	FDoubleListNode* TempNode = this->NextNode;
	while (TempNode)
	{
		if (TempNode == InNode)
		{
			TempNode->LastNode->NextNode = TempNode->NextNode;
			if(TempNode->NextNode) TempNode->NextNode->LastNode = TempNode->LastNode;
			
			delete TempNode;
			TempNode=nullptr;
			InNode=nullptr;
			return true;
		}
		TempNode= TempNode->NextNode;
	}

	cout<<"�ڵ�ǰ������û���ҵ����Node"<<endl;
	return false;
}

bool FDoubleListNode::DeleteNodeByValue(const int& InValue)
{
	FDoubleListNode* TempNode = this->NextNode;

	while (TempNode)
	{
		if (TempNode->Value == InValue)
		{
			TempNode->LastNode->NextNode = TempNode->NextNode;
			if(TempNode->NextNode) TempNode->NextNode->LastNode = TempNode->LastNode;

			delete TempNode;
			TempNode = nullptr;
			return true;
		}
		TempNode = TempNode->NextNode;
	}

	cout << "û���ҵ�ValueΪ" << InValue << "��Node" << endl;
	return false;
}

void FDoubleListNode::DestoryList()
{	
	FDoubleListNode* TempNode = this->NextNode->NextNode;
	while (TempNode)
	{
		if (TempNode->LastNode)
		{
			delete TempNode->LastNode;
			TempNode->LastNode=nullptr;
		}
		TempNode=TempNode->NextNode;
	}
	this->NextNode =nullptr;
	cout<<"�����Ѿ����,�������ʹ�ô�����������ⲿɾ������"<<endl;
}


void FDoubleListNode::ListPrint()
{
	FDoubleListNode* TempNode = this->NextNode;
	int CurrentIndex=1;
	while (TempNode)
	{
		cout<<"IndexΪ:"<<CurrentIndex<<" ��ValueΪ:"<<TempNode->Value<<endl;
		TempNode = TempNode->NextNode;
		CurrentIndex++;
	}
}
