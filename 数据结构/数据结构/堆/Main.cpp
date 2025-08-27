#pragma once
#include "MaxHeap.h"
#include "MinHeap.h"


int main()
{
	int Values[] = { 87,93,82,92,86,95,1,2,3};
	FMinHeap MaxHeap(Values,sizeof(Values)/sizeof(Values[0]));
	MaxHeap.Insert(4);
	MaxHeap.HeapSort();

	//int TempValue = MaxHeap.PopTopValue();
	MaxHeap.DeleteValue(4);

	for (int i = 0; i < MaxHeap.Size; i++)
	{
		cout << " " << MaxHeap.Arr[i];
	}



	system("pause");
	return 0;
}