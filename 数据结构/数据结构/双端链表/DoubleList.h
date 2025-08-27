#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//双链表
struct FDoubleListNode
{
	FDoubleListNode(){}
	FDoubleListNode(const int&InValue);
	
	FDoubleListNode*LastNode=nullptr;
	FDoubleListNode*NextNode=nullptr;

	int Value=-1;

	//前插法
	bool FrontInsert(FDoubleListNode*InNode);

	//后插法
	bool BrackInsert(FDoubleListNode* InNode);

	//根据Index插入
	bool InsertNodeByIndex(FDoubleListNode* InNode,const int & InIndex);

	//通过Index获取Node
	FDoubleListNode* GetNodeByIndex(const int &InIndex);

	//用Value查找对应节点
	FDoubleListNode* GetNodeByValue(const int& InValue);

	//通过索引删除链表中的Node
	bool DeleteNodeByIndex(const int& InIndex);

	//通过Node删除链表中的Node
	bool DeleteNodeByNode(FDoubleListNode* InNode);

	//通过Value删除链表中的Node
	bool DeleteNodeByValue(const int& InValue);

	//销毁List
	void DestoryList();

	//打印所有List的值
	void ListPrint();

}typedef FDoubleList;

