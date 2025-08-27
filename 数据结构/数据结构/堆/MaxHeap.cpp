#include "MaxHeap.h"

FMaxHeap::FMaxHeap(int *InArr, int InSize)
{
	Capacity = InSize> MAX_NUMBER ? InSize: MAX_NUMBER;

	//先分配在拷贝,要不然没地址,你在拷贝什么
	Arr = new int[Capacity];
	memcpy(Arr,InArr, Capacity*sizeof(int));
	Size = InSize;

	BuildMaxHeap();
}

bool FMaxHeap::BuildMaxHeap()
{
	if (!Arr)
	{
		cout<<"数组数据无效,构建失败"<<endl;
		return false;
	}

	//(Size / 2 - 1) 找到最后一个节点的父节点
	//i-- 是找到了这个最后一个节点的父节点的兄弟节点,他两是同级的,然后在比一下谁最大排上去
	for (int i = (Size / 2 - 1); i >= 0; i--)
	{
		AdjustDown(i);
	}
	return true;
}

bool FMaxHeap::AdjustDown(int InIndex)
{
	//储存这个节点的值,待会交换的时候使用
	int CurrentIndexValue = Arr[InIndex];
	int Parent,Child;

	//(Parent * 2 + 1) < Size 这个条件是Parent他的左子节点存在吗
	//Parent = Child 循环完以后 父节点的子节点还有子节点,那么继续往下比对 然后排序
	for (Parent = InIndex; (Parent * 2 + 1) < Size; Parent = Child)
	{
		//左子节点的Index
		Child = (Parent * 2 + 1);

		//右子节点是否存在          右子节点的值大于左子节点吗
		if ((Child + 1) < Size && (Arr[Child] < Arr[Child + 1]))
		{
			Child++;
		}

		//父节点的值大于 子节点中最大值吗
		if (CurrentIndexValue>= Arr[Child])
		{
			break;
		}
		else
		{
			//当前的子节点大于父节点 就交换
			Arr[Parent] = Arr[Child];
			Arr[Child] = CurrentIndexValue;
		}
	}

	return true;
}

void FMaxHeap::Insert(int InValue)
{
	if(Size ==Capacity)
	{
		cout<<"空间已经满了"<<endl;
		return;
	}

	int CurrentIndex = Size;
	Arr[Size] = InValue;
	Size++;
	AdjustUp(CurrentIndex);
}

bool FMaxHeap::AdjustUp(int InIndex)
{
	//Index>=size的时候,已经越界了
	if (InIndex < 0 || InIndex >= Size)
	{
		return false;
	}
	//保证Index在范围内
	while (InIndex > 0)
	{
		int Temp = Arr[InIndex];
		int ParentIndex = (InIndex - 1) / 2;

		//一样的意思保证父节点在有效的范围内
		if (ParentIndex >= 0)
		{
			if (Temp > Arr[ParentIndex])
			{
				//交互位置
				Arr[InIndex] = Arr[ParentIndex];
				Arr[ParentIndex] = Temp;
				//继续向上找
				InIndex = ParentIndex;
			}
			else
			{
				//如果插入的值小于父节点就没必要向上了
				break;
			}
		}
		else
		{
			//Index<0就不找了
			break;
		}
	}

	return true;
}

void FMaxHeap::HeapSort()
{
	if (Size<0)return;
	int TempSize = Size;
	while (Size>0)
	{
		int TempValue =  Arr[0];
		//吧最后的顶到最上面
		Arr[0] = Arr[Size-1];
		Arr[Size-1] = TempValue;
		Size--;

		//在吧这个弄上来的向下调整,在找出第二个大的
		AdjustDown(0);
	}
	Size = TempSize;

	//这最后弄出来是小的在前面,如果想小的在后面 反循环就行了
}

int* FMaxHeap::FindSpecifiedQuantityMaxValue(int InNum)
{
	if (InNum <=0 || InNum >=Size)
	{
		cout<<"InNum超出范围,或者无效"<<endl;
		return nullptr;
	}
	BuildMaxHeap();

	int* ReturnArr = new int[InNum];
	int Count = 0;
	int TempSize = Size;

	while (Size >0)
	{
		int TempMaxValue = Arr[0];
		Arr[0] = Arr[Size-1];
		Arr[Size-1] = TempMaxValue;

		Size--;
		//把最大的几个都存进去
		ReturnArr[Count] = TempMaxValue;
		Count++;

		//如果已经到了数量就弹出
		if (Count>=InNum) break;

		AdjustDown(0);
	}

	//复原
	Size = TempSize;
	BuildMaxHeap();

	return ReturnArr;

}

int* FMaxHeap::FindSpecifiedQuantityMinValue(int InNum)
{
	if (InNum <= 0 || InNum >= Size)
	{
		cout << "InNum超出范围,或者无效" << endl;
		return nullptr;
	}

	HeapSort();

	int* ReturnArr = new int[InNum];
	for (int i =0;i<InNum;i++)
	{
		ReturnArr[i] = Arr[i];
	}

	BuildMaxHeap();

	return ReturnArr;
}

int FMaxHeap::PopMaxValue()
{
	if (Size<1)
	{
		cout<<"堆没有初始化无法返回顶部的值"<<endl;
		return -1;
	}
	int ReturnValue = Arr[0];

	Arr[0] = Arr[Size-1];
	Size--;
	BuildMaxHeap();

	return  ReturnValue;
}

bool FMaxHeap::DeleteValue(int InValue)
{
	int CurrentIndex=-1;

	for (int i =0;i<Size;i++)
	{
		if (Arr[i]==InValue)
		{
			CurrentIndex=i;
			break;
		}
	}
	if(CurrentIndex == -1)
	{
		cout<<"没有找到合适的Value"<<endl;
		return false;
	}

	Arr[CurrentIndex] = Arr[Size-1];
	Arr[Size-1] = -1;
	Size--;

	BuildMaxHeap();
	return true;
}



