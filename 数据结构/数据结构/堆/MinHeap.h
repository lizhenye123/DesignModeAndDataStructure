#pragma once
#include <iostream>
#include <stdio.h>
#define MAX_NUMBER 128
/*
* 堆是一个平衡二叉树,已一个数组的方式来储存这些值 核心的公式其实就是下面的三个
* 获取当前节点的左子节点是 2*i+1
* 获取当前节点的右子节点是 2*i+2
* 获取当前节点的父节点是 (i-1)/2
*/

/*
* 当然循环检索堆时,是先找到最后一个节点的父节点,用当前的父节点去比较下面的子节点,然后挪动位置
* 当检索完一个父节点后,继续查找下一个,例如当前父节点是Index是5,那下一个检索的应该是4
* 至于父节点的父节点,因为循环是--的 他自然会处理到父节点的父节点的
*/

using namespace std;

struct FMinHeap
{
	FMinHeap(int*InArr,int InMaxSize);

	int *Arr;
	//当前大小
	int Size=0;

	//最的数量
	int Capactiy=0;

	//构建最小堆
	void BuildMinHeap();

	//向下调整
	void AdjustDown(int InIndex);

	//堆排序,把大的排到最上面
	void HeapSort();

	//插入
	void Insert(int InValue);

	//从尾部向上调整,给插入的使用
	void AdjustUp(int InIndex);

	//弹出顶部的值
	int PopTopValue();

	//返回指定数量的最大值
	int* FindSpecifiedQuantityMaxValue(int InNum);

	//返回指定数量的最小值
	int* FindSpecifiedQuantityMinValue(int InNum);

	//删除指定的Value
	bool DeleteValue(int InValue);

private:
	//是否反排序了
	bool bIsNotSoft=false;
};

