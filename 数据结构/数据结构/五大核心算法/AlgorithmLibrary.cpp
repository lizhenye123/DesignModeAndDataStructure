#include "AlgorithmLibrary.h"
#include <vector>
#include <algorithm>

int FAlgorithmLibrary::BinarySearch(int* InArr, int InMinIndex, int InMaxIndex, int InTarget)
{
	if (InMinIndex > InMaxIndex || InMinIndex<0 || InMaxIndex>sizeof(InArr)/sizeof(int))
	{
		cout << "����������Χ" << endl;
		return -1;
	}

	//�����Ҫ�ҵ��м����������ʽ�������ĺ���
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
	// ���ڱ���������Ľ�
	vector<int> Arr(InNumber+1,0);
	// ��ʼ��ǰ����쳲�������
	Arr[1]=1;
	Arr[2]=1;

	for (int i =3;i<=InNumber;i++)
	{
		// ״̬ת�Ʒ���,��������Ľ�,������һ��������Ľ�
		Arr[i] = Arr[i-1]+Arr[i-2];
	}
	//��������������쳲���������ֵ
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

	//���������е�ÿ����,��Ϊ��㿪ʼ����
	for (int row=0;row<InRows;row++)
	{
		for (int col = 0;col<InCols;col++)
		{
			//���ڵݹ����,��ǰֱ�����������ܲ����������InStrValue �ַ�����
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
	sort(InItems.begin(), InItems.end(), CompareItems);//������һ��

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
	//������
	if (InStrValue[PathLength]=='\0')
	{
		return true;
	}

	bool bHasPath = false;
	//InMatrix[InRow*InCols + InCol]==InStrValue[PathLength] ���������,�ڱȽ�����ַ����е�һ��ֵ����������е�һ��ֵ�Ƿ����
	if (InRow>=0 && InRow<InRows &&InCol>=0 &&InCol<InCols && InMatrix[InRow*InCols + InCol]==InStrValue[PathLength] && !Visited[InRow*InCols + InCol])
	{
		++PathLength;
		Visited[InRow * InCols + InCol]=true;

		//���������ֵ���������ҿ�ʼ��,�����ܲ��ܺ͵�ǰ�ַ�ƥ���
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
