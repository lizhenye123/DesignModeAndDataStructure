#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* 状态模式：在游戏中很常见的一种模式,虚幻引擎中的动画蓝图中的状态机,就是一种状态模式
* 主要是吧一个角色当前的状态抽象成一个类来执行,听着和策略模式很像
* 状态模式关注对象的不同状态下的行为切换，而策略模式关注不同的算法或策略之间的互相替换。
*/

/*
* 本实例展示的动画蓝图的状态机有点简单,在虚幻引擎中,状态之间的转换涉及了非常多的条件
*/

//储存动画的状态机节点
class IPlayerAnimState
{
public:
	virtual void Active()=0;
	virtual void Deactivate()=0;
};

class URunAnimState: public IPlayerAnimState
{
public:
	virtual void Active()override
	{
		cout<<"行走动画播放"<<endl;
	}
	virtual void Deactivate()override
	{
		cout<<"行走动画结束"<<endl;
	}
};

class UJumpAnimState : public IPlayerAnimState
{
public:
	virtual void Active()override
	{
		cout << "跳跃动画播放" << endl;
	}
	virtual void Deactivate()override
	{
		cout << "跳跃动画结束" << endl;
	}
};

class UAttackAnimState : public IPlayerAnimState
{
public:
	virtual void Active()override
	{
		cout << "攻击动画播放" << endl;
	}
	virtual void Deactivate()override
	{
		cout << "攻击动画结束" << endl;
	}
};

class APlayer
{
public:
	APlayer()
	{
		AnimStates.emplace(0,new URunAnimState());
		AnimStates.emplace(1,new UJumpAnimState());
		AnimStates.emplace(2,new UAttackAnimState());
	}

	void RunKeyParssed()
	{
		SwitchAnimState(0);
	}

	void JumpKeyParssed()
	{
		SwitchAnimState(1);
	}

	void AttackKeyParssed()
	{
		SwitchAnimState(2);
	}


	void SwitchAnimState(int InKey)
	{
		if (CurrentAnimState)
		{
			CurrentAnimState->Deactivate();
		}
		
		AnimStates.find(InKey)->second->Active();
		CurrentAnimState = AnimStates.find(InKey)->second;
	}
private:
	IPlayerAnimState*CurrentAnimState=nullptr;
	//这个假设成状态机
	map<int,IPlayerAnimState*>AnimStates;
};


int main(void)
{
	APlayer*Player = new APlayer();
	Player->AttackKeyParssed();
	Player->JumpKeyParssed();
	system("pause");
	return 0;
}