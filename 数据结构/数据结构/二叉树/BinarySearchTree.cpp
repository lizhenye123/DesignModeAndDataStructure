#include "BinarySearchTree.h"

bool FBinarySearchTreeNode::InsertTreeNode(FBinarySearchTreeNode* InNode)
{
	if (!InNode)
	{
		cout << "InNode��Ч" << endl;
		return false;
	}

	FBinarySearchTreeNode*TempNode=this;
	FBinarySearchTreeNode*ParentNode = nullptr;

	//�ҵ�����Ľڵ�λ��
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
	//���If�����Ҷ�Ӧ��ֵ
	//����ҵ����Ǹ��ڵ���û���ӽڵ�,�����ҵ�������ڵ��Ǹ��ڵ�����ӽڵ�,��ô������ڵ��������ӽڵ�,���͵��ǿյ���,��Ϊ�ҵ�������ڵ��Ѿ�û���ӽڵ���
	//���ֻ�����е�ĳһ���ڵ�,��ô�ҵ�������ڵ�ĸ��ڵ�,Ӧ��Ҫ���ҵ�������ڵ���ӽڵ�����,Ҫ��Ȼ���ͶϿ���
	//���������������ô,���Է������ӽڵ������� �� ���ӽڵ���С��,��������Ӱ�����Ľṹ
	if (Value > InValue)
	{
		if(LeftChildNode==nullptr)
		{
			cout<<"û���ҵ���ǰ���ϵ�ǰֵ��Value"<<endl;
			return this;
		}
		
		LeftChildNode = LeftChildNode->DeleteNode(InValue);
		return this;
	
	}
	else if (Value<InValue)
	{
		if (RightChildNode == nullptr)
		{
			cout << "û���ҵ���ǰ���ϵ�ǰֵ��Value" << endl;
			return this;
		}

		RightChildNode = RightChildNode->DeleteNode(InValue);
		return this;
	}

	//����Ļ�,���Ѿ��ҵ�ֵ��

	//���ҽڵ㶼������ʱ
	if (LeftChildNode==nullptr && RightChildNode == nullptr)
	{
		delete this;
		return nullptr;
	}

	//��ڵ����ʱ
	if (LeftChildNode!=nullptr && RightChildNode==nullptr)
	{
		FBinarySearchTreeNode* ReturnNode = LeftChildNode;
		delete this;
		return ReturnNode;
	}

	//�ҽڵ����ʱ
	if (LeftChildNode == nullptr && RightChildNode!=nullptr)
	{
		FBinarySearchTreeNode* ReturnNode = RightChildNode;
		delete this;
		return ReturnNode;
	}

	//���Ҷ�����ʱ,�ҵ����ӽڵ�����ֵ
	int TempValue = LeftChildNode->FindLeftMaxNode();
	Value = TempValue;
	//�ѵ���ԭ�����ڵ����ֵ��ɾ��,Ҫ��Ȼ�ͳ�������һ������
	LeftChildNode->DeleteNode(TempValue);
	return this;
}

int FBinarySearchTreeNode::FindLeftMaxNode()
{
	//�Ҷ�Ϊ����,�����Լ��϶�����������
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
			cout << "û���ҵ���ǰ���ϵ�ǰֵ��Value" << endl;
			return nullptr;
		}
		return RightChildNode->FindNode(InValue);
	}
	else if (InValue<Value)
	{
		if (LeftChildNode == nullptr)
		{
			cout << "û���ҵ���ǰ���ϵ�ǰֵ��Value" << endl;
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
