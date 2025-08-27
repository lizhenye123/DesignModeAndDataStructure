#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/*
* ����������
* ɾ����ʱ��Ҫ���Ƕ������,
* �����Ҷ�ӽڵ�,ֱ��ɾ������
* ����Ǹ��ڵ�,���ұ���С��Ū�ɸ��ڵ���߰��������Ū�ɸ��ڵ�
* ������ӽڵ㣬
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

	//����
	bool InsertTreeNode(FBinarySearchTreeNode*InNode);

	//ɾ��
	FBinarySearchTreeNode*DeleteNode(int InValue);

	//�������ӽڵ�����ֵ,����Ǹ����ӽڵ��õ�
	int FindLeftMaxNode();

	//�������ֵ��Node
	FBinarySearchTreeNode*FindNode(const int& InValue);

	void PrintValue();

}typedef FBinarySearchTree;

