#include <iostream>
using namespace std;
/*
* 策略模式：是把一种行为抽象成一个类,然后让具体的实例去执行这个行为
* 在虚幻引擎中有很多这种,比如GAS中的UGameplayTask,行为树中的UBTTask_BlueprintBase,动画通知UAnimNotify
* 这些都是把行为抽象成了一个类,交给具体的实例去触发的
* 这种模式,确实灵活了很多,你可以把远程攻击给的Zombie,而不是去Zombie里在去写一个
* 如果Gunner想CloseAttack,直接把任务给他就行了,而不是在去Gunner去实现一个,
* 如果具体实现到类里数量不多没啥事,多了的话确实维护起来很难受的
*/

//任务
class ITask
{
public:
	virtual void TaskActive()=0;
	virtual void TaskEnd()=0;
};

//近战攻击任务
class UCloseAttack:public ITask
{
public:
	virtual void TaskActive()override
	{
		cout << "发起近战攻击" << endl;
	}
	virtual void TaskEnd()override
	{
		cout << "近战攻击结束" << endl;
	}
};

//远程攻击任务
class ULongAttack :public ITask
{
public:
	virtual void TaskActive()override
	{
		cout<<"发起远程攻击"<<endl;
		TaskEnd();
	}
	virtual void TaskEnd()override
	{
		cout << "远程攻击结束" << endl;
	}
};

//移动任务
class UMoveTask :public ITask
{
public:
	virtual void TaskActive()override
	{
		cout << "角色开始行至目标点" << endl;
		TaskEnd();
	}
	virtual void TaskEnd()override
	{
		cout << "角色到达目标点" << endl;
	}
};

//AI
class IAI
{
public:
	virtual	void MoveTo()=0;
	virtual void Attack()=0;
};

//近战AI
class AZombie :public IAI
{
public:
	AZombie(ITask* InMoveToTask, ITask* InAttackTask)
	{
		MoveToTask=InMoveToTask;
		AttackTask = InAttackTask;
	}
	virtual	void MoveTo()override
	{
		MoveToTask->TaskActive();
	}
	virtual void Attack()override
	{
		AttackTask->TaskActive();
	}

private:
	ITask*MoveToTask;
	ITask*AttackTask;
};

//远程AI
class AGunner :public IAI
{
public:
	AGunner(ITask* InMoveToTask, ITask* InAttackTask)
	{
		MoveToTask = InMoveToTask;
		AttackTask = InAttackTask;
	}
	virtual	void MoveTo()override
	{
		MoveToTask->TaskActive();
	}
	virtual void Attack()override
	{
		AttackTask->TaskActive();
	}

private:
	ITask* MoveToTask;
	ITask* AttackTask;
};

int main()
{
	UMoveTask*MoveTask = new UMoveTask();
	UCloseAttack*AttackTask = new UCloseAttack();
	AZombie * Zombie = new AZombie(MoveTask,AttackTask);
	Zombie->MoveTo();
	Zombie->Attack();
	system("pause");
	return 0;
}