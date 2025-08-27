#pragma once
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
#define MAX_NUMBER 10

//顺序表里的值
struct FSequenceValue
{
	FSequenceValue(){}
	FSequenceValue(int InValue)
	{
		Value = InValue;
	}
	int Value;
};

//顺序表
struct FSequenceList
{

private:
	FSequenceValue* ArrayValue=nullptr;

public:
	FSequenceList();

	//当前数量
	int CurrentIndex;

	//最大数量
	int MaxNumber;

	//初始化链表
	bool InitList(int InMaxNumber);

	//添加数据
	bool AddValue(const FSequenceValue & InValue);

	//插入数据
	bool InsertValue(const FSequenceValue&InValue,const int& InIndex);

	//根据值删除
	bool DeleteValue(const FSequenceValue& InValue);

	//根据Index删除
	bool DeleteValue(const int & InIndex);

	//通过ID获取Value
	bool GetValueByIndex(const int& InIndex, FSequenceValue&SequenceValue);

	//当前值是否存在,不存在返回-1
	int FindValue(const FSequenceValue& SequenceValue);

	//打印所有值
	void PrintList();
};
