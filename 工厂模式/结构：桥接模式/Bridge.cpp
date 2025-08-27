
#include <iostream>
#include <string>
using namespace std;
/*
* 桥接模式：和游戏引擎中的组件很像,目前笔者把他们理解成了一种东西
* 这个模式的主要目的是减少类之间的耦合，允许抽象部分和实现部分独立地扩展
* 打个比方：在不同的关卡中,我想使用同一个AI,但AI的行为我想让他不同,在虚幻引擎中是直接运行不同的行为树就行,在AIController中添加不同的行为树组件即可
* 其实就是,我打开某个关卡,我会给AIController添加不同的行为树组件
*/

/*
* 本示例以一个电脑和操作系统为列,应该更加容易理解
*/

//操作系统的虚类
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
		cout << "Windows 正在运行" << endl;
	}
};

class FLinux :public IOS
{
public:
	virtual void Run()override
	{
		cout << "Linux 正在运行" << endl;
	}
};


//电脑的虚类
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
		cout << "Lenvo 正在安装操作系统" << endl;
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
		cout << "Dell 正在安装操作系统" << endl;
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
	* 这一步其实就是 在虚幻引擎中添加组件的操作
	*/
	TempComputer->Install(TempWindows);
	/*
	* 为什么不直接调用操作系统来跑,切记迪米特原则,不要让外部知道你的内部结构,只为上层提供接口
	* 个人经验：团队合作中大多数人是不会想知道这个函数里面干了什么,他们只想知道这个函数可以干什么
	* 如果你在这直接指个组件出来大多数人只会感觉到麻烦,一定要记住封装的重要性,而不是直接告诉上层的人员去操作这个类的中的组件中的什么什么函数,而是告诉他操作这个类中的某一个函数
	*/
	TempComputer->RunOS();

	system("pause");
	return 0;
}