#include <afxwin.h>
#include <iostream>
#include <stdio.h>
using namespace std;

//�ٽ���
CRITICAL_SECTION g_cs;

//�����Ĺ���һ����˽�е�,���������new,����Ҳ���ǵ�����
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
			//������ʱ������
			EnterCriticalSection(&g_cs);
			//���һ�ν����ǿյ�,�������̷߳��ʵ�ʱ��,���Ǳ��赲��������ٽ���,�����һ���߳��Ѿ�����new��,���ǻ���newһ��
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
USingleton* USingleton::Singer = NULL;//new Singleton; ��C++�й��캯�������̰߳�ȫ��
int main(void) 
{
	//����Զ��߳�����һ��,�����������������new�����ٸ���ַ��
	::InitializeCriticalSection(&g_cs);
	for (int i = 0; i < 10; i++) {
		AfxBeginThread(Func, NULL);
	}
	::DeleteCriticalSection(&g_cs);
	system("pause");
	return 0;
}