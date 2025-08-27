#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


//������Ķ���,�ض�����һ������,��������
//������ĸ��ڵ���û�д����κ����ݵ�,��ֻ��Ϊһ��������
struct FListNode
{
	FListNode*NextNode{nullptr};
	int Value{0};

	//ǰ�巨
	bool FrontInsert(FListNode*InNode);

	//��巨
	bool BrackInsert(FListNode*InNode);

	//���뵽ָ����λ��
	bool InsertByIndex(FListNode*InNode,int InIndex);

	//ͨ��Index��ȡValue
	bool GetValueByIndex(int InIndex,int & OutValue);

	//��Value���Ҷ�Ӧ�ڵ�
	FListNode* GetListNodeByValue(int InValue);

	//ͨ������ɾ�������е�Node
	bool DeleteNodeByIndex(int InIndex);

	//ͨ��Nodeɾ�������е�Node
	bool DeleteNodeByNode(FListNode* InNode);

	//ͨ��Valueɾ�������е�Node
	bool DeleteNodeByValue(const int& InValue);

	//����List
	void DestoryList();

	//��ӡ����List��ֵ
	void ListPrint();
	
}typedef FList;

