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
		cout<<"MinHeap ��Ч"<<endl;
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
		cout<<"��ǰIndex��Ч ������Χ����<0"<<endl;
		return;
	}

	int CurrentValue = Arr[InIndex];
	int Parent=0,Child=0;

	//(Parent * 2 + 1)�����һ���ڵ�����ӽڵ�
	//Parent = Child ������滹�еĻ�,Ҫһֱ����ȥ,ֻ��������,�ŵ������
	for (Parent = InIndex; (Parent * 2 + 1) < Size; Parent = Child)
	{
		//��ڵ�
		Child = (Parent * 2 + 1);

		//���ӽڵ���Ч && ���ӽڵ�С�����ӽڵ�
		if (Child + 1 < Size &&  Arr[Child + 1] < Arr[Child])
		{
			Child++;
		}

		//����ӽڵ�С�븸�ڵ�ͽ���
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
		cout<<"Heap��û�г�ʼ��"<<endl;
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
		cout<<"����ʧ��,�Ѿ�����"<<endl;
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
		cout << "��ǰIndex��Ч ������Χ����<0" << endl;
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
				//�����ǰֵ���ڸ��ڵ��û��Ҫ������ȥ��
				break;
			}
		}else
		{
			//�����-1�Ļ� ���������Ѿ�Խ���� ����ȥ�ͱ�����
			break;
		}
	}
}

int FMinHeap::PopTopValue()
{
	if (Size<=0)
	{
		cout<<"Heapû�г�ʼ��"<<endl;
		return -1;
	}

	//����Ƿ�����Ļ��ȸ�Ū����
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
		cout << "Heapû�г�ʼ��" << endl;
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
		cout << "Heapû�г�ʼ��" << endl;
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
		cout << "Heapû�г�ʼ��" << endl;
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
		cout<<"��ǰû�з��ϵ�Value"<<endl;
		return false;
	}

	Arr[DeleteIndex] = Arr[Size-1];
	Arr[Size-1]=-1;
	Size--;

	BuildMinHeap();
	return true;
}
