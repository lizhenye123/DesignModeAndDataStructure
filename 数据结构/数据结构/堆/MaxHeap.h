#pragma once
#include <iostream>
#include <stdio.h>
#define MAX_NUMBER 128

using namespace std;

/*
* 堆是一个平衡二叉树,已一个数组的方式来储存这些值
* 获取当前节点的左子节点是 2*i+1 
* 获取当前节点的右子节点是 2*i+2
* 获取当前节点的父节点是 (i-1)/2
*/

struct FMaxHeap
{
	FMaxHeap(int *InArr, int InSize);

	//指向数组的指针
	int*Arr;

	//当前储存的数量
	int Size;

	//可以储存的最大数量
	int Capacity;

	//插入
	void Insert(int InValue);

	//堆排序
	void HeapSort();

	//返回指定数量的最大值
	int* FindSpecifiedQuantityMaxValue(int InNum);

	//返回指定数量的最小值
	int* FindSpecifiedQuantityMinValue(int InNum);

	//弹出顶部的最大值
	int PopMaxValue();

	//删除指定的Value
	bool DeleteValue(int InValue);

private:
	//构建最大堆
	bool BuildMaxHeap();

	//调整最小的往下排
	bool AdjustDown(int InIndex);

	//调整最大的往上排,插入的时候使的
	bool AdjustUp(int InIndex);
};

