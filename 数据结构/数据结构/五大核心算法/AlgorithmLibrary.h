#pragma once
#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct FItem
{
	FItem(int InWeight, int InValue)
	{
		Weight=InWeight;
		Value = InValue;
	}
	int Weight;
	int Value;
};

class FAlgorithmLibrary
{
public:

	/*
	* �����㷨,�������������õ�
	* 1.�ֽ⣺��ԭ����ֽ�����ɸ���ģС,�໥����,��ԭ������ʽ��ͬ��������
	* 2.��������������С��ֱ�ӽ��,����ݹ�Ľ��������
	* 3.�ϲ��������ɸ�������ϲ���Դ����Ľ�
	*/
	static int BinarySearch(int* InArr, int InMinIndex, int InMaxIndex, int InTarget);

	//��̬�滮�㷨
	//��쳲���������
	//��������������Ľ�,�������������Ľ�
	static int Fibonacci(int InNumber);

	/*
	* ���ݷ�
	* ���ҵ�ǰ��������û����ȷ��·��
	* �����ǵݹ����,���Ҳ���������һ��������ѯ
	*/
	static bool HasPath(const char*InMatrix,int InRows,int InCols,const char*InStrValue);

	/*
	* ̰���㷨
	* ģ�ⱳ������װ�ص�����
	* ���ݵ�ǰ��ֱ,һֱװ,ֱ��װ����Ϊֹ
	*/
	static bool GreedyAlgorithm(vector<FItem>&InItems,int InCapacity,vector<FItem>&OutItems);



private:
	//���ݷ����ӷ���
	static bool HasPathCore(const char*InMatrix,int InRows,int InCols,int InRow,int InCol,const char*InStrValue,int &PathLength,bool *Visited);

	//̰���㷨���ӷ���,�ڱȽ��Ǹ���
	static bool CompareItems(FItem InItem1,FItem InItem2);

};



