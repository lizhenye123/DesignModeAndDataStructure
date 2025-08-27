#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/*
* 二叉搜索树
* 删除的时候要考虑多种情况,
* 如果是叶子节点,直接删除就行
* 如果是根节点,吧右边最小的弄成根节点或者吧左边最大的弄成根节点
* 如果是子节点，
*/

struct FBinarySearchTreeNode
{
	FBinarySearchTreeNode(int InValue)
	{
		Value = InValue;
	}

	int Value=0;
	FBinarySearchTreeNode*LeftChildNode=nullptr;
	FBinarySearchTreeNode*RightChildNode=nullptr;

	//插入
	bool InsertTreeNode(FBinarySearchTreeNode*InNode);

	//删除
	FBinarySearchTreeNode*DeleteNode(int InValue);

	//返回左子节点的最大值,这个是给左子节点用的
	int FindLeftMaxNode();

	//查找这个值的Node
	FBinarySearchTreeNode*FindNode(const int& InValue);

	void PrintValue();

}typedef FBinarySearchTree;

