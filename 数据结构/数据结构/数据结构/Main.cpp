#pragma once
#include <iostream>
#include <string>
#include "SequenceList.h"
using namespace std;

int main()
{

	FSequenceList List;
	List.InitList(5);

	//ÃÌº” ß∞‹ «’‚
	for (int i =0;i<6;i++)
	{
		List.AddValue(FSequenceValue(i));
	}
	List.InsertValue(FSequenceValue(5),4);

	List.DeleteValue(0);

	List.DeleteValue(FSequenceValue(5));

	int Index =List.FindValue(FSequenceValue(4));
	cout << "Find Index =" <<Index<< endl;

	FSequenceValue TempValue;
	List.GetValueByIndex(Index, TempValue);
	cout << "GetValueByIndex =" << TempValue.Value << endl;

	cout<<"--------------------------------------"<<endl;

	List.PrintList();

	system("pause");
	return 0;
}