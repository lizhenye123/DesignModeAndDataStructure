#pragma once
#include <iostream>
#include <stdio.h>
#define MAX_NUMBER 128
/*
* ����һ��ƽ�������,��һ������ķ�ʽ��������Щֵ ���ĵĹ�ʽ��ʵ�������������
* ��ȡ��ǰ�ڵ�����ӽڵ��� 2*i+1
* ��ȡ��ǰ�ڵ�����ӽڵ��� 2*i+2
* ��ȡ��ǰ�ڵ�ĸ��ڵ��� (i-1)/2
*/

/*
* ��Ȼѭ��������ʱ,�����ҵ����һ���ڵ�ĸ��ڵ�,�õ�ǰ�ĸ��ڵ�ȥ�Ƚ�������ӽڵ�,Ȼ��Ų��λ��
* ��������һ�����ڵ��,����������һ��,���統ǰ���ڵ���Index��5,����һ��������Ӧ����4
* ���ڸ��ڵ�ĸ��ڵ�,��Ϊѭ����--�� ����Ȼ�ᴦ�����ڵ�ĸ��ڵ��
*/

using namespace std;

struct FMinHeap
{
	FMinHeap(int*InArr,int InMaxSize);

	int *Arr;
	//��ǰ��С
	int Size=0;

	//�������
	int Capactiy=0;

	//������С��
	void BuildMinHeap();

	//���µ���
	void AdjustDown(int InIndex);

	//������,�Ѵ���ŵ�������
	void HeapSort();

	//����
	void Insert(int InValue);

	//��β�����ϵ���,�������ʹ��
	void AdjustUp(int InIndex);

	//����������ֵ
	int PopTopValue();

	//����ָ�����������ֵ
	int* FindSpecifiedQuantityMaxValue(int InNum);

	//����ָ����������Сֵ
	int* FindSpecifiedQuantityMinValue(int InNum);

	//ɾ��ָ����Value
	bool DeleteValue(int InValue);

private:
	//�Ƿ�������
	bool bIsNotSoft=false;
};

