#include <iostream>
#include <string>
using namespace std;

/*
* ������ģʽ����Ҫ�ǰɽ�ɫ������ݽṹ���󵽷�����ȥ����,��Ҫ�����յĿ���ԭ��,ֻ��չ���޸�
* ��RPC��Ϸ�п�����������������Լ���,Ҳ������ϵͳɶ��,
* ������ȥ�޸�ԭ��ɫ��Ĵ���,������չ��һ������ȥ�����������,�е�������ģʽ�������
* ǰ����Ǳ�����Ҫ���Լ�ע�ᵽ�������в����÷�������������Щ����
*/

class FPlayer;
class FEnemy;
class FNPC;

//������
class IVisitor
{
public:
	virtual void VisitPlayer(FPlayer* InPlayer)=0;
	virtual void VisitEnemy(FEnemy* InEnemy) = 0;
	virtual void VisitNPC(FNPC* InNPC) = 0;
};

//��ɫ������
class ICharacter
{
public:
	//���������Ҫ�������������ע���Լ���
	virtual void Accept(IVisitor*InVisitor)=0;
};

//��ҽ�ɫ
class FPlayer :public ICharacter
{
public:
	virtual void Accept(IVisitor* InVisitor) override
	{
		InVisitor->VisitPlayer(this);
	}
};

//����
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
		std::cout << "��ҹ���" << std::endl;
	}

	void VisitEnemy(FEnemy* InEnemy) override
	{
		std::cout << "���˹���" << std::endl;
	}

	void VisitNPC(FNPC* InNPC) override
	{
		std::cout << "NPC�޷�����" << std::endl;
	}
}; 

class FInteractionVisitor : public IVisitor
{
public:
	virtual void VisitPlayer(FPlayer* InPlayer) override
	{
		std::cout << "��ҿ��Խ���" << std::endl;
	}

	void VisitEnemy(FEnemy* InEnemy) override
	{
		std::cout << "�����޷�����" << std::endl;
	}

	void VisitNPC(FNPC* InNPC) override
	{
		std::cout << "NPC���Խ���" << std::endl;
	}

	void Test(...)
	{
	}
};


int main()
{
	//��������
	FPlayer* Player = new FPlayer();
	FEnemy*Enemy = new FEnemy();
	FNPC* NPC = new FNPC();

	//������
	FAttackVisitor AttackVisitor;
	FInteractionVisitor InteractionVisitor;

	//ʹ�÷�����
	Player->Accept(&AttackVisitor);
	Enemy->Accept(&InteractionVisitor);

	system("pause");
	return 0;
}