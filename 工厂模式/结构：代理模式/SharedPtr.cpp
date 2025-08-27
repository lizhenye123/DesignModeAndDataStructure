#include <iostream>
using namespace std;

/*
* ����ģʽ��,���õľ����������ָ����,ʹ������ָ��,����ԭ����ָ��������һЩ�������
* ʵ�ʵ�ָ��ͼ���������һ�����������,������ָ�����һ��������Ӧ��
*/

template<class T>
class TSharedPtr;

//����ָ������ü�����
template<class T>
class FRefCounter
{
	friend TSharedPtr;
private:
	//ʵ�ʵ�ָ��
	T* InstancePtr;
	//���ü���
	size_t RefCount;
	TSharedRef(T*P)
	{
		InstancePtr = P;
		RefCount++;
		cout << "TSharedRef���캯������" << endl;
	}

	virtual ~TSharedRef()
	{
		if (InstancePtr)
		{
			cout << "��TSharedRef()������������" << endl;
			delete InstancePtr;
			InstancePtr = nullptr;
			RefCount = 0;
		}
	}
};

//����ָ��
template<class T>
class TSharedPtr
{
public:
	TSharedPtr()
	{
		RefCounter=nullptr;
	}

	TSharedPtr(T*InPtr)
	{
		RefCounter = new FRefCounter<T>(InPtr);
		cout<<"����ָ���TSharedPtr(T*Ptr)���캯������"<<endl;
	}

	TSharedPtr(TSharedPtr<T>& InOther)
	{
		RefCounter = InOther.RefCounter;
		++(RefCounter->RefCount);
		cout<< "TSharedPtr(& InOther)�������캯������" << endl;
	}

	TSharedPtr<T>& operator=(TSharedPtr& InOther)
	{
		//���ü�������1
		++(InOther.RefCounter->RefCount);

		//��������Ҫָ���µĶ���,���԰ɵ�ǰ������ü���������
		if (RefCounter)
		{
			if (--(RefCounter->RefCount)==0)
			{
				delete RefCounter;
			}
		}

		RefCounter = InOther.RefCounter;
	}

	T& operator*()
	{
		return *(RefCounter->InstancePtr);
	}

	T* operator->()
	{
		return (RefCounter->InstancePtr);
	}

	~TSharedPtr()
	{
		cout<<"~TSharedPtr() ������������"<<endl;
		if ((--RefCounter->RefCount) == 0)
		{
			cout<<"ɾ�������ָ��"<<endl;
			delete RefCounter;
			RefCounter=nullptr;
		}
	}
private:
	FRefCounter<T>*RefCounter;
};

int main()
{
	TSharedPtr<int>*Ptr = nullptr;
	{
		TSharedPtr<int> Ptr0;
		{
			TSharedPtr<int> Ptr1(new int(4));
			cout<<*Ptr1<<endl;
			//��������С��Ptr1��ֵ�������ڸ����Ptr0;
			Ptr0=Ptr1;
		}

		//new int(4)û������
		TSharedPtr<int> Ptr2(new int(3));

		//Ptr0 ָ�� �µ�����ָ�� 
		Ptr0 = Ptr2;

		//ptr��ָ��,˵���˾��Ǵ���һ������ָ��
		Ptr = &Ptr2;
		cout << *(*Ptr) << endl;
	}

	system("pause");
	return 0;
}