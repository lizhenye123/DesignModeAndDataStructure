#include <iostream>
#include <string>
using namespace std;

/*
* 访问者模式：主要是吧角色里的数据结构抽象到访问者去操作,主要是依照的开闭原则,只扩展不修改
* 在RPC游戏中可以用来计算各种属性计算,也有任务系统啥的,
* 尽量不去修改原角色里的代码,而是扩展出一个新类去处理这个功能,有点像门面模式或者组件
* 前提就是被访者要吧自己注册到访问者中才能让访问者来处理这些事情
*/

class FPlayer;
class FEnemy;
class FNPC;

//访问者
class IVisitor
{
public:
	virtual void VisitPlayer(FPlayer* InPlayer)=0;
	virtual void VisitEnemy(FEnemy* InEnemy) = 0;
	virtual void VisitNPC(FNPC* InNPC) = 0;
};

//角色的虚类
class ICharacter
{
public:
	//这个函数主要是用来向访问者注册自己的
	virtual void Accept(IVisitor*InVisitor)=0;
};

//玩家角色
class FPlayer :public ICharacter
{
public:
	virtual void Accept(IVisitor* InVisitor) override
	{
		InVisitor->VisitPlayer(this);
	}
};

//敌人
class FEnemy :public ICharacter
{
public:
	virtual void Accept(IVisitor* InVisitor) override
	{
		InVisitor->VisitEnemy(this);
	}
};

//NPC
class FNPC :public ICharacter
{
public:
	virtual void Accept(IVisitor* InVisitor) override
	{
		InVisitor->VisitNPC(this);
	}
};

class FAttackVisitor : public IVisitor 
{
public:
	virtual void VisitPlayer(FPlayer* InPlayer) override
	{
		std::cout << "玩家攻击" << std::endl;
	}

	void VisitEnemy(FEnemy* InEnemy) override
	{
		std::cout << "敌人攻击" << std::endl;
	}

	void VisitNPC(FNPC* InNPC) override
	{
		std::cout << "NPC无法攻击" << std::endl;
	}
}; 

class FInteractionVisitor : public IVisitor
{
public:
	virtual void VisitPlayer(FPlayer* InPlayer) override
	{
		std::cout << "玩家可以交互" << std::endl;
	}

	void VisitEnemy(FEnemy* InEnemy) override
	{
		std::cout << "敌人无法交互" << std::endl;
	}

	void VisitNPC(FNPC* InNPC) override
	{
		std::cout << "NPC可以交互" << std::endl;
	}

	void Test(...)
	{
	}
};


int main()
{
	//被访问者
	FPlayer* Player = new FPlayer();
	FEnemy*Enemy = new FEnemy();
	FNPC* NPC = new FNPC();

	//访问者
	FAttackVisitor AttackVisitor;
	FInteractionVisitor InteractionVisitor;

	//使用访问者
	Player->Accept(&AttackVisitor);
	Enemy->Accept(&InteractionVisitor);

	system("pause");
	return 0;
}