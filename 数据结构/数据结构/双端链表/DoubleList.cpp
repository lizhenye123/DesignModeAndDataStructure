#include "DoubleList.h"

#define CHECK_NODE_IS_VALID(InNode)\
if (!InNode)\
{\
	cout << "InNode无效插入失败" << endl;\
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
		cout<<"无法插入小于等于0的Index"<<endl;
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
		cout << "插入失敗,無法找到當前的Ｉｎｄｅｘ" << endl;
		return false;
	}

	//如果找到的这个节点他后面没有的话
	if (!TempNode->NextNode)
	{
		TempNode->NextNode = InNode;
		InNode->LastNode = TempNode;
		return true;
	}

	//要插入的那个链表后面还有东西的话
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
		cout<<"在尝试获取根节点或者无效节点"<<endl;
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

	cout<<"没有找到对应的Index的Node 输入的Index为:"<<InIndex<<" 最大的Index为："<<CurrentIndex;
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

	cout<<"没有找到Value为"<<InValue<<"的Node"<<endl;
	return nullptr;
}

bool FDoubleListNode::DeleteNodeByIndex(const int& InIndex)
{
	if (InIndex <= 0)
	{
		cout << "在尝试删除根节点或者无效节点,根节点请使用销毁" << endl;
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

	cout << "没有找到对应的Index的Node 输入的Index为:" << InIndex << " 最大的Index为：" << CurrentIndex;
	return false;
}

bool FDoubleListNode::DeleteNodeByNode(FDoubleListNode* InNode)
{
	CHECK_NODE_IS_VALID(InNode)

	if (InNode == this)
	{
		cout << "在尝试删除根节点或者无效节点,根节点请使用销毁" << endl;
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

	cout<<"在当前链表中没有找到这个Node"<<endl;
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

	cout << "没有找到Value为" << InValue << "的Node" << endl;
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
	cout<<"链表已经清空,如果不想使用此链表可以在外部删除链表"<<endl;
}


void FDoubleListNode::ListPrint()
{
	FDoubleListNode* TempNode = this->NextNode;
	int CurrentIndex=1;
	while (TempNode)
	{
		cout<<"Index为:"<<CurrentIndex<<" 的Value为:"<<TempNode->Value<<endl;
		TempNode = TempNode->NextNode;
		CurrentIndex++;
	}
}
