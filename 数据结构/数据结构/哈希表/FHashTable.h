#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
#define MAX_SIZE 3

/*
* 正常的哈希表是有一步加密的,要吧传进来的Key加密成一个16进制的东西,UE的叫FHash
* 吧16进制的这个数转成10进制,进行取余操作,锁定数组中的某一个链表,个人习惯在UE里使TMap存
* 哈希表主要用来减少搜索速度的,多分几个链表,他搜的越快,当然他的空间也就越大,有的甚至一直会没有值
* 毕竟是哈希加密过后的,有时候分配了5个 他有可能全加到第一个里去,因为哈希加密以后转成10进制取余他一直=1,哪他就全加到1的链表里去了
* 但这种情况少见
*/

struct FHashNode
{
	FHashNode(int InValue)
	{
		Value = InValue;
	}
	FHashNode*NextNode = nullptr;
	int Value;
};

struct FHashTable
{
	FHashTable()
	{
		for (int i =0;i<MAX_SIZE;i++)
		{
			ArrNode[i] = new FHashNode(-1);
		}
	}
	~FHashTable()
	{
		delete[] ArrNode;
	}

	FHashNode*ArrNode[MAX_SIZE];

	//这个就是我们要进行取余的数字了
	int MaxSize = MAX_SIZE;

	//我们这缺少一步将Hash转换成数字的,条件有限,默认已经转换成Key了
	//这将会获取Arrnode的具体某一个链表的Index
	int GetHashKey(int InValue);

	//这可以是任意类型的输入类型,具体就是要你加密成哈希,在转成Key去找,这已int为示例,不是必须是int
	//这是吧这个InValue当成解Key的,也当成了要找的具体的值
	//返回-1为没找到
	int GetNodeByValue(int InValue);

	//插入
	bool InsertValue(int InValue);

	//删除Node
	bool DeleteNode(int InValue);

	//销毁
	void DestoryHash();

	//打印所以的Hash
	void PrintHash();

	//是否有效
	bool IsValid();

	//是否为空
	bool IsEmpty();
};

