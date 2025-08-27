#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
* 观察者模式：在虚幻引擎中使用还是很多的,他在虚幻引擎中就是我们常说的代理,单播多播代理就是
* A监听B的状态以后,B发生改变会通知A
*/


//观察者,检测观察者状态
class AObserver
{
public:
	virtual void Update(string InMessage)=0;
protected:
	AObserver(){};
};

//被观察者,通知观察者状态改变了
class ASubject
{
public:
	virtual void AddObserver(AObserver*InObserver)=0;
	virtual void RemoveObserver(AObserver* InObserver)=0;

	//这个其实就是广播,告诉观察者,这个事情发生了,要做对应的事了
	virtual void NoitfyObserver()=0;
protected:
	ASubject(){}
};

class ACharacter:public ASubject
{
public:
	ACharacter(){};
	virtual void AddObserver(AObserver* InObserver) override
	{
		ArrObserver.push_back(InObserver);
	}

	virtual void RemoveObserver(AObserver* InObserver)override
	{
		vector<AObserver*>::iterator Iter = find(ArrObserver.begin(), ArrObserver.end(),InObserver);
		if (Iter!= ArrObserver.end())
		{
			ArrObserver.erase(Iter);
		}
	}

	virtual void NoitfyObserver()override
	{
		for (vector<AObserver*>::iterator Iter = ArrObserver.begin(); Iter != ArrObserver.end(); Iter++) {
			(*Iter)->Update("角色死亡,添加死亡计数");

		}
	}

private:
	vector<AObserver*>ArrObserver;
};

class ALeaderboard :public AObserver
{
public:
	ALeaderboard(){}
	virtual void Update(string InMessage)override
	{
		cout<<InMessage<<endl;
		cout<<"更新排行榜信息,准备角色重生逻辑"<<endl;
	}
};

int main()
{
	ACharacter*Character =new ACharacter();
	ALeaderboard* Leaderboard = new ALeaderboard();
	
	Character->AddObserver(Leaderboard);
	Character->NoitfyObserver();

	system("pause");
	return 0;
}