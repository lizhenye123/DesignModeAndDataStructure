#include <iostream>
using namespace std;

/*
* 代理模式中,常用的就是这个智能指针了,使用智能指针,来对原生的指针来进行一些管理操作
* 实际的指针和计数器是另一个类来管理的,而智能指针就是一个代理层的应用
*/

template<class T>
class TSharedPtr;

//智能指针的引用计数器
template<class T>
class FRefCounter
{
	friend TSharedPtr;
private:
	//实际的指针
	T* InstancePtr;
	//引用计数
	size_t RefCount;
	TSharedRef(T*P)
	{
		InstancePtr = P;
		RefCount++;
		cout << "TSharedRef构造函数调用" << endl;
	}

	virtual ~TSharedRef()
	{
		if (InstancePtr)
		{
			cout << "～TSharedRef()析构函数调用" << endl;
			delete InstancePtr;
			InstancePtr = nullptr;
			RefCount = 0;
		}
	}
};

//智能指针
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
		cout<<"智能指针的TSharedPtr(T*Ptr)构造函数调用"<<endl;
	}

	TSharedPtr(TSharedPtr<T>& InOther)
	{
		RefCounter = InOther.RefCounter;
		++(RefCounter->RefCount);
		cout<< "TSharedPtr(& InOther)拷贝构造函数调用" << endl;
	}

	TSharedPtr<T>& operator=(TSharedPtr& InOther)
	{
		//引用计数器加1
		++(InOther.RefCounter->RefCount);

		//由于现在要指向新的对象,所以吧当前存的引用计数器减少
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
		cout<<"~TSharedPtr() 析构函数调用"<<endl;
		if ((--RefCounter->RefCount) == 0)
		{
			cout<<"删除保存的指针"<<endl;
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
			//将生存期小的Ptr1赋值给生存期更大的Ptr0;
			Ptr0=Ptr1;
		}

		//new int(4)没有销毁
		TSharedPtr<int> Ptr2(new int(3));

		//Ptr0 指向 新的智能指针 
		Ptr0 = Ptr2;

		//ptr是指针,说白了就是存了一个二级指针
		Ptr = &Ptr2;
		cout << *(*Ptr) << endl;
	}

	system("pause");
	return 0;
}