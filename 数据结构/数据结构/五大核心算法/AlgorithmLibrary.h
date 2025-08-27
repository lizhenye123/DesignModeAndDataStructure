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
	* 分治算法,数组必须是排序好的
	* 1.分解：将原问题分解成若干个规模小,相互独立,与原问题形式相同的子问题
	* 2.解决：若子问题较小就直接解决,否则递归的解决子问题
	* 3.合并：将若干个子问题合并成源问题的解
	*/
	static int BinarySearch(int* InArr, int InMinIndex, int InMaxIndex, int InTarget);

	//动态规划算法
	//求斐波那契数列
	//核心是用子问题的解,求出其他子问题的解
	static int Fibonacci(int InNumber);

	/*
	* 回溯法
	* 查找当前矩阵中有没有正确的路径
	* 核心是递归查找,查找不到返回上一级继续查询
	*/
	static bool HasPath(const char*InMatrix,int InRows,int InCols,const char*InStrValue);

	/*
	* 贪心算法
	* 模拟背包可以装载的数量
	* 根据当前的直,一直装,直到装不下为止
	*/
	static bool GreedyAlgorithm(vector<FItem>&InItems,int InCapacity,vector<FItem>&OutItems);



private:
	//回溯法的子方法
	static bool HasPathCore(const char*InMatrix,int InRows,int InCols,int InRow,int InCol,const char*InStrValue,int &PathLength,bool *Visited);

	//贪心算法的子方法,在比较那个大
	static bool CompareItems(FItem InItem1,FItem InItem2);

};



