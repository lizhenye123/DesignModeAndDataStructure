#include <iostream>
using namespace std;
/*
* ����ģʽ���ǰ�һ����Ϊ�����һ����,Ȼ���þ����ʵ��ȥִ�������Ϊ
* ������������кܶ�����,����GAS�е�UGameplayTask,��Ϊ���е�UBTTask_BlueprintBase,����֪ͨUAnimNotify
* ��Щ���ǰ���Ϊ�������һ����,���������ʵ��ȥ������
* ����ģʽ,ȷʵ����˺ܶ�,����԰�Զ�̹�������Zombie,������ȥZombie����ȥдһ��
* ���Gunner��CloseAttack,ֱ�Ӱ��������������,��������ȥGunnerȥʵ��һ��,
* �������ʵ�ֵ�������������ûɶ��,���˵Ļ�ȷʵά�����������ܵ�
*/

//����
class ITask
{
public:
	virtual void TaskActive()=0;
	virtual void TaskEnd()=0;
};

//��ս��������
class UCloseAttack:public ITask
{
public:
	virtual void TaskActive()override
	{
		cout << "�����ս����" << endl;
	}
	virtual void TaskEnd()override
	{
		cout << "��ս��������" << endl;
	}
};

//Զ�̹�������
class ULongAttack :public ITask
{
public:
	virtual void TaskActive()override
	{
		cout<<"����Զ�̹���"<<endl;
		TaskEnd();
	}
	virtual void TaskEnd()override
	{
		cout << "Զ�̹�������" << endl;
	}
};

//�ƶ�����
class UMoveTask :public ITask
{
public:
	virtual void TaskActive()override
	{
		cout << "��ɫ��ʼ����Ŀ���" << endl;
		TaskEnd();
	}
	virtual void TaskEnd()override
	{
		cout << "��ɫ����Ŀ���" << endl;
	}
};

//AI
class IAI
{
public:
	virtual	void MoveTo()=0;
	virtual void Attack()=0;
};

//��սAI
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

//Զ��AI
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