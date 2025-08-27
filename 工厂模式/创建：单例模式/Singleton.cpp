#include <afxwin.h>
#include <iostream>
#include <stdio.h>
using namespace std;

//临界区
CRITICAL_SECTION g_cs;

//单例的构造一定是私有的,你能让外边new,那你也不是单例了
class USingleton
{
private:
	USingleton()
	{
		Singer =nullptr;
	}

	static USingleton* Singer;

public:
	static USingleton*GetSingleton()
	{
		if (Singer == nullptr)
		{
			//进来的时候上锁
			EnterCriticalSection(&g_cs);
			//这第一次进来是空的,但当多线程访问的时候,他们被阻挡到上面的临界区,如果第一个线程已经进来new了,他们会又new一个
			if(Singer == nullptr)
			{
				Singer = new USingleton();
				LeaveCriticalSection(&g_cs);
			}
		}
		return Singer;
	}
};

UINT Func(LPVOID) 
{
	printf("%x\n", USingleton::getInstance());
	return 0;
}
USingleton* USingleton::Singer = NULL;//new Singleton; 在C++中构造函数不是线程安全的
int main(void) 
{
	//你可以多线程运行一下,不加锁看看他会给你new出多少个地址来
	::InitializeCriticalSection(&g_cs);
	for (int i = 0; i < 10; i++) {
		AfxBeginThread(Func, NULL);
	}
	::DeleteCriticalSection(&g_cs);
	system("pause");
	return 0;
}