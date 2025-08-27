
#include <iostream>
#include <string>
using namespace std;
/*
* �Ž�ģʽ������Ϸ�����е��������,Ŀǰ���߰�����������һ�ֶ���
* ���ģʽ����ҪĿ���Ǽ�����֮�����ϣ�������󲿷ֺ�ʵ�ֲ��ֶ�������չ
* ����ȷ����ڲ�ͬ�Ĺؿ���,����ʹ��ͬһ��AI,��AI����Ϊ����������ͬ,�������������ֱ�����в�ͬ����Ϊ������,��AIController����Ӳ�ͬ����Ϊ���������
* ��ʵ����,�Ҵ�ĳ���ؿ�,�һ��AIController��Ӳ�ͬ����Ϊ�����
*/

/*
* ��ʾ����һ�����ԺͲ���ϵͳΪ��,Ӧ�ø����������
*/

//����ϵͳ������
class IOS
{
public:
	IOS() {}
	virtual ~IOS(){}
	virtual void Run() = 0;
};

class FWindows :public IOS
{
public:
	virtual void Run()override
	{
		cout << "Windows ��������" << endl;
	}
};

class FLinux :public IOS
{
public:
	virtual void Run()override
	{
		cout << "Linux ��������" << endl;
	}
};


//���Ե�����
class IComputer
{
public:
	virtual void Install(IOS* InOS) = 0;
	virtual void RunOS()=0;
	virtual ~IComputer(){}
};

class FLenvo :public IComputer {
public:
	virtual void Install(IOS* InOS)override 
	{
		cout << "Lenvo ���ڰ�װ����ϵͳ" << endl;
		OS = InOS;
	}
	virtual void RunOS() override
	{
		OS->Run();
	}
private:
	IOS*OS;
};

class FDell :public IComputer {
public:
	virtual void Install(IOS* InOS)override
	{
		cout << "Dell ���ڰ�װ����ϵͳ" << endl;
		OS = InOS;
	}
	virtual void RunOS() override
	{
		OS->Run();
	}
private:
	IOS* OS;
};

int main()
{
	IOS*TempWindows = new FWindows();
	IOS* TempLinux = new FLinux();

	IComputer*TempComputer = new FLenvo();
	/*
	* ��һ����ʵ���� ������������������Ĳ���
	*/
	TempComputer->Install(TempWindows);
	/*
	* Ϊʲô��ֱ�ӵ��ò���ϵͳ����,�мǵ�����ԭ��,��Ҫ���ⲿ֪������ڲ��ṹ,ֻΪ�ϲ��ṩ�ӿ�
	* ���˾��飺�ŶӺ����д�������ǲ�����֪����������������ʲô,����ֻ��֪������������Ը�ʲô
	* ���������ֱ��ָ����������������ֻ��о����鷳,һ��Ҫ��ס��װ����Ҫ��,������ֱ�Ӹ����ϲ����Աȥ�����������е�����е�ʲôʲô����,���Ǹ���������������е�ĳһ������
	*/
	TempComputer->RunOS();

	system("pause");
	return 0;
}