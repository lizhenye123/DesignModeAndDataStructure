#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* ״̬ģʽ������Ϸ�кܳ�����һ��ģʽ,��������еĶ�����ͼ�е�״̬��,����һ��״̬ģʽ
* ��Ҫ�ǰ�һ����ɫ��ǰ��״̬�����һ������ִ��,���źͲ���ģʽ����
* ״̬ģʽ��ע����Ĳ�ͬ״̬�µ���Ϊ�л���������ģʽ��ע��ͬ���㷨�����֮��Ļ����滻��
*/

/*
* ��ʵ��չʾ�Ķ�����ͼ��״̬���е��,�����������,״̬֮���ת���漰�˷ǳ��������
*/

//���涯����״̬���ڵ�
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
		cout<<"���߶�������"<<endl;
	}
	virtual void Deactivate()override
	{
		cout<<"���߶�������"<<endl;
	}
};

class UJumpAnimState : public IPlayerAnimState
{
public:
	virtual void Active()override
	{
		cout << "��Ծ��������" << endl;
	}
	virtual void Deactivate()override
	{
		cout << "��Ծ��������" << endl;
	}
};

class UAttackAnimState : public IPlayerAnimState
{
public:
	virtual void Active()override
	{
		cout << "������������" << endl;
	}
	virtual void Deactivate()override
	{
		cout << "������������" << endl;
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
	//��������״̬��
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