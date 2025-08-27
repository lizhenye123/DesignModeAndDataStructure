#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
#define MAX_NUMBER 10

//˳������ֵ
struct FSequenceValue
{
	FSequenceValue(){}
	FSequenceValue(int InValue)
	{
		Value = InValue;
	}
	int Value;
};

//˳���
struct FSequenceList
{

private:
	FSequenceValue* ArrayValue=nullptr;

public:
	FSequenceList();

	//��ǰ����
	int CurrentIndex;

	//�������
	int MaxNumber;

	//��ʼ������
	bool InitList(int InMaxNumber);

	//�������
	bool AddValue(const FSequenceValue & InValue);

	//��������
	bool InsertValue(const FSequenceValue&InValue,const int& InIndex);

	//����ֵɾ��
	bool DeleteValue(const FSequenceValue& InValue);

	//����Indexɾ��
	bool DeleteValue(const int & InIndex);

	//ͨ��ID��ȡValue
	bool GetValueByIndex(const int& InIndex, FSequenceValue&SequenceValue);

	//��ǰֵ�Ƿ����,�����ڷ���-1
	int FindValue(const FSequenceValue& SequenceValue);

	//��ӡ����ֵ
	void PrintList();
};
