#include "MaxHeap.h"

FMaxHeap::FMaxHeap(int *InArr, int InSize)
{
	Capacity = InSize> MAX_NUMBER ? InSize: MAX_NUMBER;

	//�ȷ����ڿ���,Ҫ��Ȼû��ַ,���ڿ���ʲô
	Arr = new int[Capacity];
	memcpy(Arr,InArr, Capacity*sizeof(int));
	Size = InSize;

	BuildMaxHeap();
}

bool FMaxHeap::BuildMaxHeap()
{
	if (!Arr)
	{
		cout<<"����������Ч,����ʧ��"<<endl;
		return false;
	}

	//(Size / 2 - 1) �ҵ����һ���ڵ�ĸ��ڵ�
	//i-- ���ҵ���������һ���ڵ�ĸ��ڵ���ֵܽڵ�,������ͬ����,Ȼ���ڱ�һ��˭�������ȥ
	for (int i = (Size / 2 - 1); i >= 0; i--)
	{
		AdjustDown(i);
	}
	return true;
}

bool FMaxHeap::AdjustDown(int InIndex)
{
	//��������ڵ��ֵ,���ύ����ʱ��ʹ��
	int CurrentIndexValue = Arr[InIndex];
	int Parent,Child;

	//(Parent * 2 + 1) < Size ���������Parent�������ӽڵ������
	//Parent = Child ѭ�����Ժ� ���ڵ���ӽڵ㻹���ӽڵ�,��ô�������±ȶ� Ȼ������
	for (Parent = InIndex; (Parent * 2 + 1) < Size; Parent = Child)
	{
		//���ӽڵ��Index
		Child = (Parent * 2 + 1);

		//���ӽڵ��Ƿ����          ���ӽڵ��ֵ�������ӽڵ���
		if ((Child + 1) < Size && (Arr[Child] < Arr[Child + 1]))
		{
			Child++;
		}

		//���ڵ��ֵ���� �ӽڵ������ֵ��
		if (CurrentIndexValue>= Arr[Child])
		{
			break;
		}
		else
		{
			//��ǰ���ӽڵ���ڸ��ڵ� �ͽ���
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
		cout<<"�ռ��Ѿ�����"<<endl;
		return;
	}

	int CurrentIndex = Size;
	Arr[Size] = InValue;
	Size++;
	AdjustUp(CurrentIndex);
}

bool FMaxHeap::AdjustUp(int InIndex)
{
	//Index>=size��ʱ��,�Ѿ�Խ����
	if (InIndex < 0 || InIndex >= Size)
	{
		return false;
	}
	//��֤Index�ڷ�Χ��
	while (InIndex > 0)
	{
		int Temp = Arr[InIndex];
		int ParentIndex = (InIndex - 1) / 2;

		//һ������˼��֤���ڵ�����Ч�ķ�Χ��
		if (ParentIndex >= 0)
		{
			if (Temp > Arr[ParentIndex])
			{
				//����λ��
				Arr[InIndex] = Arr[ParentIndex];
				Arr[ParentIndex] = Temp;
				//����������
				InIndex = ParentIndex;
			}
			else
			{
				//��������ֵС�ڸ��ڵ��û��Ҫ������
				break;
			}
		}
		else
		{
			//Index<0�Ͳ�����
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
		//�����Ķ���������
		Arr[0] = Arr[Size-1];
		Arr[Size-1] = TempValue;
		Size--;

		//�ڰ����Ū���������µ���,���ҳ��ڶ������
		AdjustDown(0);
	}
	Size = TempSize;

	//�����Ū������С����ǰ��,�����С���ں��� ��ѭ��������
}

int* FMaxHeap::FindSpecifiedQuantityMaxValue(int InNum)
{
	if (InNum <=0 || InNum >=Size)
	{
		cout<<"InNum������Χ,������Ч"<<endl;
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
		//�����ļ��������ȥ
		ReturnArr[Count] = TempMaxValue;
		Count++;

		//����Ѿ����������͵���
		if (Count>=InNum) break;

		AdjustDown(0);
	}

	//��ԭ
	Size = TempSize;
	BuildMaxHeap();

	return ReturnArr;

}

int* FMaxHeap::FindSpecifiedQuantityMinValue(int InNum)
{
	if (InNum <= 0 || InNum >= Size)
	{
		cout << "InNum������Χ,������Ч" << endl;
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
		cout<<"��û�г�ʼ���޷����ض�����ֵ"<<endl;
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
		cout<<"û���ҵ����ʵ�Value"<<endl;
		return false;
	}

	Arr[CurrentIndex] = Arr[Size-1];
	Arr[Size-1] = -1;
	Size--;

	BuildMaxHeap();
	return true;
}



