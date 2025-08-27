#include "List.h"

#define CHECK_NODE_IS_VALID(Node)\
if (!InNode)\
{\
	cout << "InNode无效插入失败" << endl;\
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
		cout<<"无法插入小于等于0的索引位置"<<endl;
		return false;
	}


	//-1是保存了当前要查找的位置的上一个,要不然没法插
	while (LastNode && CurrentIndex < (InIndex - 1))
	{
		LastNode = LastNode->NextNode;
		CurrentIndex++;
	}

	if (LastNode && CurrentIndex<=InIndex-1)
	{
		//当前要插入替换的那个Node
		FListNode* InsertNode = LastNode->NextNode;

		if (InNode->NextNode)
		{
			//当前传进来要插入的Node他的下一个有效
			FListNode*InNodeNext = InNode->NextNode;
			
			//在找插入的节点的最后一个节点
			while (InNodeNext->NextNode)
			{
				InNodeNext = InNodeNext->NextNode;
			}

			//吧原本的插入到InNode这个链表的最后面
			LastNode->NextNode = InNode;
			InNodeNext->NextNode = InsertNode;
			return true;
		}

		LastNode->NextNode = InNode;
		InNode->NextNode = InsertNode;
		return true;
	}

	cout<<"插入的索引超出已有的位置"<<endl;
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
		cout<<"当前搜索超出List的大小 当前Index = "<<CurrentIndex<<"输入的Index= "<<InIndex << endl;
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

	cout<<"没有找到符合条件的ListNode Value = "<<InValue<<endl;
	return nullptr;
}

bool FListNode::DeleteNodeByIndex(int InIndex)
{
	if (InIndex<=0)
	{
		cout<<"无法删除根节点,已经根节点以前的节点"<<endl;
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
		cout<<"删除的Index超出范围 当前Index="<<CurrentIndex<<"搜索的Index"<<InIndex<<endl;
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
		cout<<"没有查找到对应的Node"<<endl;
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

	cout<<"没有找到相应Value的Node"<<endl;
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
		cout << "没有值" << endl;
		return;
	}

	while (TempNode)
	{
		cout<<"当前Index = "<<Index<<" | Value = "<< TempNode->Value<<endl;
		TempNode=TempNode->NextNode;
		Index++;
	}
}

