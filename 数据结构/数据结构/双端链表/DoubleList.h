#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//˫����
struct FDoubleListNode
{
	FDoubleListNode(){}
	FDoubleListNode(const int&InValue);
	
	FDoubleListNode*LastNode=nullptr;
	FDoubleListNode*NextNode=nullptr;

	int Value=-1;

	//ǰ�巨
	bool FrontInsert(FDoubleListNode*InNode);

	//��巨
	bool BrackInsert(FDoubleListNode* InNode);

	//����Index����
	bool InsertNodeByIndex(FDoubleListNode* InNode,const int & InIndex);

	//ͨ��Index��ȡNode
	FDoubleListNode* GetNodeByIndex(const int &InIndex);

	//��Value���Ҷ�Ӧ�ڵ�
	FDoubleListNode* GetNodeByValue(const int& InValue);

	//ͨ������ɾ�������е�Node
	bool DeleteNodeByIndex(const int& InIndex);

	//ͨ��Nodeɾ�������е�Node
	bool DeleteNodeByNode(FDoubleListNode* InNode);

	//ͨ��Valueɾ�������е�Node
	bool DeleteNodeByValue(const int& InValue);

	//����List
	void DestoryList();

	//��ӡ����List��ֵ
	void ListPrint();

}typedef FDoubleList;

