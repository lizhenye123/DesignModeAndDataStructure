#pragma once
#include <iostream>
#include <stdio.h>
#define MAX_NUMBER 128

using namespace std;

/*
* ����һ��ƽ�������,��һ������ķ�ʽ��������Щֵ
* ��ȡ��ǰ�ڵ�����ӽڵ��� 2*i+1 
* ��ȡ��ǰ�ڵ�����ӽڵ��� 2*i+2
* ��ȡ��ǰ�ڵ�ĸ��ڵ��� (i-1)/2
*/

struct FMaxHeap
{
	FMaxHeap(int *InArr, int InSize);

	//ָ�������ָ��
	int*Arr;

	//��ǰ���������
	int Size;

	//���Դ�����������
	int Capacity;

	//����
	void Insert(int InValue);

	//������
	void HeapSort();

	//����ָ�����������ֵ
	int* FindSpecifiedQuantityMaxValue(int InNum);

	//����ָ����������Сֵ
	int* FindSpecifiedQuantityMinValue(int InNum);

	//�������������ֵ
	int PopMaxValue();

	//ɾ��ָ����Value
	bool DeleteValue(int InValue);

private:
	//��������
	bool BuildMaxHeap();

	//������С��������
	bool AdjustDown(int InIndex);

	//��������������,�����ʱ��ʹ��
	bool AdjustUp(int InIndex);
};

