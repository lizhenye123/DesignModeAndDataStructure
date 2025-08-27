#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


//单链表的定义,重定义了一个链表,方便区分
//单链表的根节点是没有储存任何数据的,他只作为一个根存在
struct FListNode
{
	FListNode*NextNode{nullptr};
	int Value{0};

	//前插法
	bool FrontInsert(FListNode*InNode);

	//后插法
	bool BrackInsert(FListNode*InNode);

	//插入到指定的位置
	bool InsertByIndex(FListNode*InNode,int InIndex);

	//通过Index获取Value
	bool GetValueByIndex(int InIndex,int & OutValue);

	//用Value查找对应节点
	FListNode* GetListNodeByValue(int InValue);

	//通过索引删除链表中的Node
	bool DeleteNodeByIndex(int InIndex);

	//通过Node删除链表中的Node
	bool DeleteNodeByNode(FListNode* InNode);

	//通过Value删除链表中的Node
	bool DeleteNodeByValue(const int& InValue);

	//销毁List
	void DestoryList();

	//打印所有List的值
	void ListPrint();
	
}typedef FList;

