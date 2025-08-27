#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
#define MAX_SIZE 3

/*
* �����Ĺ�ϣ������һ�����ܵ�,Ҫ�ɴ�������Key���ܳ�һ��16���ƵĶ���,UE�Ľ�FHash
* ��16���Ƶ������ת��10����,����ȡ�����,���������е�ĳһ������,����ϰ����UE��ʹTMap��
* ��ϣ����Ҫ�������������ٶȵ�,��ּ�������,���ѵ�Խ��,��Ȼ���Ŀռ�Ҳ��Խ��,�е�����һֱ��û��ֵ
* �Ͼ��ǹ�ϣ���ܹ����,��ʱ�������5�� ���п���ȫ�ӵ���һ����ȥ,��Ϊ��ϣ�����Ժ�ת��10����ȡ����һֱ=1,������ȫ�ӵ�1��������ȥ��
* ����������ټ�
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

	//�����������Ҫ����ȡ���������
	int MaxSize = MAX_SIZE;

	//������ȱ��һ����Hashת�������ֵ�,��������,Ĭ���Ѿ�ת����Key��
	//�⽫���ȡArrnode�ľ���ĳһ�������Index
	int GetHashKey(int InValue);

	//��������������͵���������,�������Ҫ����ܳɹ�ϣ,��ת��Keyȥ��,����intΪʾ��,���Ǳ�����int
	//���ǰ����InValue���ɽ�Key��,Ҳ������Ҫ�ҵľ����ֵ
	//����-1Ϊû�ҵ�
	int GetNodeByValue(int InValue);

	//����
	bool InsertValue(int InValue);

	//ɾ��Node
	bool DeleteNode(int InValue);

	//����
	void DestoryHash();

	//��ӡ���Ե�Hash
	void PrintHash();

	//�Ƿ���Ч
	bool IsValid();

	//�Ƿ�Ϊ��
	bool IsEmpty();
};

