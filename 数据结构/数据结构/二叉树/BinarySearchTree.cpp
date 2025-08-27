#include "BinarySearchTree.h"

bool FBinarySearchTreeNode::InsertTreeNode(FBinarySearchTreeNode* InNode)
{
	if (!InNode)
	{
		cout << "InNode无效" << endl;
		return false;
	}

	FBinarySearchTreeNode*TempNode=this;
	FBinarySearchTreeNode*ParentNode = nullptr;

	//找到插入的节点位置
	while (TempNode!=nullptr)
	{
		ParentNode = TempNode;

		if (InNode->Value < TempNode->Value)
		{
			TempNode = TempNode->LeftChildNode;
		}else
		{
			TempNode = TempNode->RightChildNode;
		}
	}


	if (InNode->Value<ParentNode->Value)
	{
		ParentNode->LeftChildNode = InNode;
	}else
	{
		ParentNode->RightChildNode = InNode;
	}
	return true;

}

FBinarySearchTreeNode* FBinarySearchTreeNode::DeleteNode(int InValue)
{
	//这个If是在找对应的值
	//如果找到的那个节点他没有子节点,假设找到的这个节点是父节点的右子节点,那么这个父节点的这个右子节点,他就的是空的了,因为找到的这个节点已经没有子节点了
	//如果只有其中的某一个节点,那么找到的这个节点的父节点,应该要吧找到的这个节点的子节点链接,要不然树就断开了
	//如果两个都存在那么,可以返回左子节点中最大的 或 右子节点最小的,这样不会影响树的结构
	if (Value > InValue)
	{
		if(LeftChildNode==nullptr)
		{
			cout<<"没有找到当前符合当前值的Value"<<endl;
			return this;
		}
		
		LeftChildNode = LeftChildNode->DeleteNode(InValue);
		return this;
	
	}
	else if (Value<InValue)
	{
		if (RightChildNode == nullptr)
		{
			cout << "没有找到当前符合当前值的Value" << endl;
			return this;
		}

		RightChildNode = RightChildNode->DeleteNode(InValue);
		return this;
	}

	//到这的话,就已经找到值了

	//左右节点都不存在时
	if (LeftChildNode==nullptr && RightChildNode == nullptr)
	{
		delete this;
		return nullptr;
	}

	//左节点存在时
	if (LeftChildNode!=nullptr && RightChildNode==nullptr)
	{
		FBinarySearchTreeNode* ReturnNode = LeftChildNode;
		delete this;
		return ReturnNode;
	}

	//右节点存在时
	if (LeftChildNode == nullptr && RightChildNode!=nullptr)
	{
		FBinarySearchTreeNode* ReturnNode = RightChildNode;
		delete this;
		return ReturnNode;
	}

	//左右都存在时,找到左子节点最大的值
	int TempValue = LeftChildNode->FindLeftMaxNode();
	Value = TempValue;
	//把底下原本存在的这个值给删掉,要不然就出现两个一样的了
	LeftChildNode->DeleteNode(TempValue);
	return this;
}

int FBinarySearchTreeNode::FindLeftMaxNode()
{
	//右都为空了,那他自己肯定就是最大的了
	if (RightChildNode==nullptr)
	{
		return Value;
	}
	return RightChildNode->FindLeftMaxNode();
}

FBinarySearchTreeNode* FBinarySearchTreeNode::FindNode(const int& InValue)
{
	if (InValue>Value)
	{
		if (RightChildNode == nullptr)
		{
			cout << "没有找到当前符合当前值的Value" << endl;
			return nullptr;
		}
		return RightChildNode->FindNode(InValue);
	}
	else if (InValue<Value)
	{
		if (LeftChildNode == nullptr)
		{
			cout << "没有找到当前符合当前值的Value" << endl;
			return nullptr;
		}
		return LeftChildNode->FindNode(InValue);
	}

	return this;
}

void FBinarySearchTreeNode::PrintValue()
{
	cout<<Value<<" ";
	if (RightChildNode)
	{
		RightChildNode->PrintValue();
	}
	if (LeftChildNode)
	{
		LeftChildNode->PrintValue();
	}
}
