#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 调停者模式：其实就是一个调度中心,在游戏开发中,也使用较频繁的
* 当游戏结束时,游戏要通知所有的角色停止运动,有可能是投降结束了,有可能是别人打爆你房水晶结束了,投降结束这个结束写在GameMode里,角色打爆角色里也写一个,也行(你不闲麻烦的话)
* 接下来要通知所有人要做的结束行为,你也许会遍历所有玩家控制器让他们去做结束的逻辑
* 当我创建一个调度中心时,一个玩家加入时,他就会使用观察者模式,观察调度中心,调度中心调用结束游戏,所有控制器全收到了,只要有人调用调度器中结束函数就行
* 调停者模式在游戏开发中可以应用于多个对象之间的协作和通信，特别是在复杂的游戏系统中。例如，多个游戏角色之间的协作、多个游戏模块之间的通信等情况都可以使用调停者模式来简化和管理交互。
* 你可以尝试画一个图 A,B,C,D,E五个类,他们互相引用的线会有多少,然后你在加个调度器画一次,你会发现就5根了
*/

class ICharacter
{
public:
	virtual void CallGameOver()=0;

	virtual void GameOverOperate()=0;

};



//虚幻中有子系统,所以不推荐自己写单例,但如果不是,那么大多数调停者都是一个单例模式
class UMediatorSubsystem
{
public:
	
	static UMediatorSubsystem* GetMediatorSubsystem()
	{
		//这只会初始化一次为空,如果不理解可以查一下 静态变量只会初始化一次
		static UMediatorSubsystem* Subsystem=nullptr;
		if (Subsystem == nullptr)
		{
			Subsystem = new UMediatorSubsystem();
		}

		return Subsystem;
	}

	void GameOver()
	{
		for (vector<ICharacter*>::iterator Iter = Characters.begin();Iter!=Characters.end();Iter++)
		{
			(*Iter)->GameOverOperate();
		}
	}

	//一把不会自己手动加,而是一个代理,当然手动加也可以,为了简单,笔者在这就手加了
	void AddPlayer(ICharacter*InPlayer)
	{
		Characters.push_back(InPlayer);
	}
private:
	vector<ICharacter*>Characters;
	UMediatorSubsystem(){}
};


//游戏中的角色
class ACharacter :public ICharacter
{
public:
	ACharacter()
	{
		UMediatorSubsystem::GetMediatorSubsystem()->AddPlayer(this);
	}
	virtual void CallGameOver() override
	{
		UMediatorSubsystem::GetMediatorSubsystem()->GameOver();
	}
 
 	virtual void GameOverOperate() override
	{
		cout << "游戏结束时角色要处理的事情,UI等等" << endl;
	}
};

int main()
{
	ACharacter* Character = new ACharacter();
	ACharacter* Character1 = new ACharacter();
	ACharacter* Character2 = new ACharacter();
	ACharacter* Character3 = new ACharacter();
	ACharacter* Character4 = new ACharacter();


	Character->CallGameOver();

	system("pause");
	return 0;
}

