#include "AlgorithmLibrary.h"
#include <vector>
#include <algorithm>

int FAlgorithmLibrary::BinarySearch(int* InArr, int InMinIndex, int InMaxIndex, int InTarget)
{
	if (InMinIndex > InMaxIndex || InMinIndex<0 || InMaxIndex>sizeof(InArr)/sizeof(int))
	{
		cout << "索引超出范围" << endl;
		return -1;
	}

	//计算出要找的中间数，这个公式就是他的核心
	int ReturnIndex = (InMinIndex + InMaxIndex) / 2;
	if (InArr[ReturnIndex] == InTarget)
	{
		return ReturnIndex;
	}
	else if (InArr[ReturnIndex] < InTarget)
	{
		return BinarySearch(InArr, ReturnIndex - 1, InMaxIndex, InTarget);
	}
	else if (InArr[ReturnIndex] > InTarget)
	{
		return BinarySearch(InArr, InMinIndex, ReturnIndex - 1, InTarget);
	}

	return -1;
}

int FAlgorithmLibrary::Fibonacci(int InNumber)
{
	// 用于保存子问题的解
	vector<int> Arr(InNumber+1,0);
	// 初始化前两个斐波那契数
	Arr[1]=1;
	Arr[2]=1;

	for (int i =3;i<=InNumber;i++)
	{
		// 状态转移方程,以子问题的解,计算下一个子问题的解
		Arr[i] = Arr[i-1]+Arr[i-2];
	}
	//返回这个求出来的斐波那契数列值
	return Arr[InNumber];
}

bool FAlgorithmLibrary::HasPath(const char* InMatrix, int InRows, int InCols, const char* InStrValue)
{
	if (InMatrix==nullptr || InRows<1 || InCols<1 || InStrValue == nullptr)
	{
		return false;
	}

	bool *TempVisited = new bool[InRows*InCols];
	memset(TempVisited,0,InRows*InCols);

	int PathLength=0;

	//遍历矩阵中的每个点,做为起点开始搜索
	for (int row=0;row<InRows;row++)
	{
		for (int col = 0;col<InCols;col++)
		{
			//这在递归查找,当前直的上下左右能不能连出这个InStrValue 字符串来
			if (HasPathCore(InMatrix,InRows,InCols,row,col,InStrValue,PathLength, TempVisited))
			{
				return true;
			}
		}
	}

	delete[] TempVisited;
	return false;
}

bool FAlgorithmLibrary::GreedyAlgorithm(vector<FItem>& InItems, int InCapacity,vector<FItem>& OutItems)
{
	sort(InItems.begin(), InItems.end(), CompareItems);//排序了一下

	double TotalValue=0;
	double CurrentWeight=0;

	for (const FItem& Item:InItems)
	{
		if (CurrentWeight + Item.Weight <=InCapacity)
		{
			TotalValue+=Item.Value;
			CurrentWeight+= Item.Weight;
			OutItems.push_back(Item);
		}
		else
		{
			int RemainingCapacity = InCapacity - CurrentWeight;
			TotalValue += static_cast<double>(RemainingCapacity)*Item.Value / Item.Weight;
			OutItems.push_back(FItem(RemainingCapacity,Item.Value));
			break;
		}
	}
	return TotalValue;
}

bool FAlgorithmLibrary::HasPathCore(const char* InMatrix, int InRows, int InCols, int InRow, int InCol, const char* InStrValue, int& PathLength, bool* Visited)
{
	//找完了
	if (InStrValue[PathLength]=='\0')
	{
		return true;
	}

	bool bHasPath = false;
	//InMatrix[InRow*InCols + InCol]==InStrValue[PathLength] 核心是这个,在比较这个字符串中的一个值和这个矩阵中的一个值是否相等
	if (InRow>=0 && InRow<InRows &&InCol>=0 &&InCol<InCols && InMatrix[InRow*InCols + InCol]==InStrValue[PathLength] && !Visited[InRow*InCols + InCol])
	{
		++PathLength;
		Visited[InRow * InCols + InCol]=true;

		//这是向这个值的上下左右开始找,看看能不能和当前字符匹配的
		bHasPath = HasPathCore(InMatrix, InRows, InCols, InRow, InCol-1, InStrValue, PathLength, Visited)
			|| HasPathCore(InMatrix, InRows, InCols, InRow, InCol + 1, InStrValue, PathLength, Visited)
			|| HasPathCore(InMatrix, InRows, InCols, InRow-1, InCol, InStrValue, PathLength, Visited)
			|| HasPathCore(InMatrix, InRows, InCols, InRow+1, InCol, InStrValue, PathLength, Visited);

		if (!bHasPath)
		{
			--PathLength;
			Visited[InRow * InCols + InCol] = false;
		}
	}
	return bHasPath;
}

bool FAlgorithmLibrary::CompareItems(FItem InItem1, FItem InItem2)
{
	double Ratio1 = static_cast<double>(InItem1.Value) / InItem1.Weight;
	double Ratio2 = static_cast<double>(InItem2.Value) / InItem2.Weight;
	return Ratio1>Ratio2;
}
