#include "MinHeap.h"


FMinHeap::FMinHeap(int* InArr, int InMaxSize)
{
	Capactiy = InMaxSize>MAX_NUMBER?InMaxSize: MAX_NUMBER;
	Arr = new int[InMaxSize];
	memcpy(Arr,InArr,InMaxSize*sizeof(int));
	Size = InMaxSize;

	BuildMinHeap();
}

void FMinHeap::BuildMinHeap()
{
	if (!Arr)
	{
		cout<<"MinHeap 无效"<<endl;
		return;
	}

	for (int i =(Size / 2 - 1);i>=0; i--)
	{
		AdjustDown(i);
	}

	bIsNotSoft = false;
}

void FMinHeap::AdjustDown(int InIndex)
{
	if (InIndex>Size || InIndex<0)
	{
		cout<<"当前Index无效 超出范围或者<0"<<endl;
		return;
	}

	int CurrentValue = Arr[InIndex];
	int Parent=0,Child=0;

	//(Parent * 2 + 1)找最后一个节点的左子节点
	//Parent = Child 如果下面还有的话,要一直排下去,只到把最大的,排到最底下
	for (Parent = InIndex; (Parent * 2 + 1) < Size; Parent = Child)
	{
		//左节点
		Child = (Parent * 2 + 1);

		//右子节点有效 && 右子节点小于左子节点
		if (Child + 1 < Size &&  Arr[Child + 1] < Arr[Child])
		{
			Child++;
		}

		//如果子节点小与父节点就交互
		if (Arr[Child]< CurrentValue)
		{
			Arr[Parent] = Arr[Child];
			Arr[Child] = CurrentValue;
		}
		else
		{
			break;	
		}
	}
}

void FMinHeap::HeapSort()
{
	if (Size<=0||Capactiy<=0)
	{
		cout<<"Heap还没有初始化"<<endl;
		return;
	}

	int TempSize = Size;
	bIsNotSoft=true;
	while (Size>0)
	{
		int TempValue = Arr[0];
		Arr[0] =  Arr[Size-1];
		Arr[Size-1] = TempValue;
		Size--;

		AdjustDown(0);
	}

	Size = TempSize;
}

void FMinHeap::Insert(int InValue)
{
	if (bIsNotSoft)
	{
		BuildMinHeap();
	}

	if (Size>=Capactiy)
	{
		cout<<"插入失败,已经满了"<<endl;
		return;
	}

	int CurrentIndex = Size;
	Arr[Size] = InValue;
	Size++;
	AdjustUp(CurrentIndex);
}

void FMinHeap::AdjustUp(int InIndex)
{
	if (InIndex<0 || InIndex>Size)
	{
		cout << "当前Index无效 超出范围或者<0" << endl;
		return;
	}

	while (InIndex>=0)
	{
		int TempValue= Arr[InIndex];
		int ParentIndex = ((InIndex - 1) / 2);

		if (ParentIndex>=0)
		{
			int Value1 = Arr[ParentIndex];
			if (TempValue < Arr[ParentIndex])
			{
				Arr[InIndex] = Arr[ParentIndex];
				Arr[ParentIndex] = TempValue;
				InIndex = ParentIndex;
			}
			else
			{
				//如果当前值大于父节点就没必要继续下去了
				break;
			}
		}else
		{
			//如果是-1的话 数组现在已经越界了 不出去就奔溃了
			break;
		}
	}
}

int FMinHeap::PopTopValue()
{
	if (Size<=0)
	{
		cout<<"Heap没有初始化"<<endl;
		return -1;
	}

	//如果是反排序的话先给弄回来
	if (bIsNotSoft)
	{
		BuildMinHeap();
	}

	int ReturnValue = Arr[0];
	Arr[0] = Arr[Size-1];
	Arr[Size - 1]=0;
	Size--;

	AdjustDown(0);
	return ReturnValue;
}

int* FMinHeap::FindSpecifiedQuantityMaxValue(int InNum)
{
	if (Size <= 0 || InNum > Size)
	{
		cout << "Heap没有初始化" << endl;
		return nullptr;
	}

	int*ReturnValue = new int[InNum];

	if (!bIsNotSoft)
	{
		HeapSort();
	}

	for (int i =0;i<InNum;i++)
	{
		ReturnValue[i] = Arr[i];
	}

	BuildMinHeap();

	return ReturnValue;
}

int* FMinHeap::FindSpecifiedQuantityMinValue(int InNum)
{
	if (Size <= 0 || InNum>Size)
	{
		cout << "Heap没有初始化" << endl;
		return nullptr;
	}

	int* ReturnValue = new int[InNum];

	if (!bIsNotSoft)
	{
		HeapSort();
	}
	int LoopCount= 0;
	for (int i = Size-1; LoopCount < InNum; i--)
	{
		ReturnValue[LoopCount] = Arr[i];
		LoopCount++;
	}

	return ReturnValue;
}

bool FMinHeap::DeleteValue(int InValue)
{
	if (Size <= 0)
	{
		cout << "Heap没有初始化" << endl;
		return false;
	}

	int DeleteIndex=-1;
	for (int i =0;i<Size;i++)
	{
		if (Arr[i] == InValue)
		{
			DeleteIndex = i;
			break;
		}
	}

	if(DeleteIndex==-1)
	{
		cout<<"当前没有符合的Value"<<endl;
		return false;
	}

	Arr[DeleteIndex] = Arr[Size-1];
	Arr[Size-1]=-1;
	Size--;

	BuildMinHeap();
	return true;
}
