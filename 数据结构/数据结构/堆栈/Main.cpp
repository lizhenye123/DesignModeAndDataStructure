#pragma once
#include <iostream>
#include <string>
#include "FStack.h"
using namespace std;

int main()
{
	FStack*Stack = new FStack();

	for (int i =0;i<5;i++)
	{
		Stack->PushStack(i);
	}

	int Value=-1;
	Stack->PopStack(Value);
	Value=Stack->GetRearValue();
	Stack->DestoryStack();

	Stack->PrintStack();
	
	system("pause");
	return 0;
}