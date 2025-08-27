#include <iostream>
#include <deque>
#include <stack>
using namespace std;

/*
* 适配器模式,在开发中的使用频率还是挺高的
* 比如在UE中,使用FString转成FName、FText、uint32啥的以及TArray转成TSet都是非常长见的一些操作
* 这次的示例,以一个插板来示例一下
* 下面会使用stl的deque和Stack做一个常见的示例
*/

//插板上的三口的插座
class FThreePhaseOutlet
{
public:
	void DoThreePhasePlug()
	{
		cout<<"三口插头接入"<<endl;
	}
};

//插板上的二口的插座
class ITwoPhaseOutlet
{
public:
	virtual void DoPlug()=0;
};

//转接器
class FOutletConverter:public ITwoPhaseOutlet
{
public:
	FOutletConverter(FThreePhaseOutlet* InThreePhase)
	{
		ThreePhase = InThreePhase;
	}
	virtual void DoPlug()override
	{
		ThreePhase->DoThreePhasePlug();
		DoConvertor();
	}
	void DoConvertor()
	{
		cout<<"正在将三口插头转换为两口插头"<<endl;
	}

private:
	FThreePhaseOutlet* ThreePhase;
};

int main()
{

	FThreePhaseOutlet* ThreePhase = new FThreePhaseOutlet();
	FOutletConverter*Converter = new FOutletConverter(ThreePhase);
	Converter->DoPlug();

	//stl中的适配
	deque<int> MyDeq(3,100);
	stack<int> MySta(MyDeq);

	system("pause");
	return 0;
}