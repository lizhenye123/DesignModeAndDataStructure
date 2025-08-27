#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <map>
using namespace std;

/*
* ԭ��ģʽ ԭ��C++��û��UE�е�UClass�������͵Ķ�����
* ��Ҫ�ĺ�����new�˵�һ�����Ժ���������ȥ����������͵�ʵ��,���԰�new�������һ���൱����UE�е�UClass,�Ͼ�Ue���ڴ���Ҳ��һ��UClass
* �ں���Ҫ���ɹ����ʱ��,����Keyȥ����,Ȼ��ȥ��������Ӧ��ʵ��
* �ڹ��������ĺ��ľ����Ǹ�Clone�Ǹ�����,�Ե�һ��Ϊģ�崴��������һģһ����ʵ��
*/

/*
* ��ʾ��,����һ������������Ϊ�ο�
*/

//int ת�ַ���
template<class T>
string IToStr(T Value)
{
	stringstream SS;
	SS<<Value;
	return SS.str();
}

//���˵�����
class IEnemy
{
public:
	virtual void Attack(IEnemy*InTarget)=0;
	virtual void HitDamage(const float &InDamage)=0;
	virtual string GetName()=0;
	//�����¡������Ҫ�����������ģ�������������Ĺ���
	virtual IEnemy* Clone()=0;

	virtual ~IEnemy(){}
protected:
	IEnemy(){}
};

//����A,��ʹF��,��Ҫ�����������������淶,����A��û�취��������Ϸ������
//������
class AGhost :public IEnemy
{
public:
	AGhost(){}

	AGhost(float InHealth,float InAttackDamage)
	{
		Health = InHealth;
		AttackDamage = InAttackDamage;
	}

	virtual void Attack(IEnemy* InTarget)override
	{
		cout<< GetName()<<"������"<< InTarget->GetName()<<endl;
		InTarget->HitDamage(AttackDamage);
	}

	virtual void HitDamage(const float& InDamage)override
	{
		Health-=InDamage;
		cout << GetName() <<"�ܵ���"<< InDamage <<"�˺�" << endl;
	}

	virtual string GetName()override
	{
		string Name = "Ghost"+ Count;
		return Name;
	}

	virtual IEnemy* Clone()
	{
		Count++;
		return new AGhost(Health, AttackDamage);
	}

public:
	float Health=20;
	float AttackDamage=5;
	int Count=0;
};

//��ħ��
class ADemon :public IEnemy
{
public:
	ADemon() {}

	virtual string GetName()override
	{
		string Name = "Demon";
		return Name;
	}

	ADemon(float InHealth, float InAttackDamage)
	{
		Health = InHealth;
		AttackDamage = InAttackDamage;
	}

	virtual void Attack(IEnemy* InTarget)override
	{
		cout << GetName() << "������" << InTarget->GetName() << endl;
		InTarget->HitDamage(AttackDamage);
	}

	virtual void HitDamage(const float& InDamage)override
	{
		Health -= InDamage;
		cout << GetName() << "�ܵ���" << InDamage << "�˺�" << endl;
	}

	virtual IEnemy* Clone()
	{
		Count++;
		ADemon*CreateDemon = new ADemon(Health, AttackDamage);
		//ƽ���Ĺ��ﲻʹ�����,ģ����ʹ�ô�������
		CreateDemon->Count=-1;

		return CreateDemon;
	}

public:
	float Health = 20;
	float AttackDamage = 5;
	int Count = 0;
};

//������
class ASpawner
{
public:
	void AddEnemyTemplate(const string & EnmeyName,IEnemy*InEnemy)
	{
		EnemyList.emplace(EnmeyName,InEnemy);
	}

	IEnemy*CreateEnemy(const string & EnemyName)
	{
		if (EnemyList.find(EnemyName)!= EnemyList.end())
		{
			return EnemyList.find(EnemyName)->second->Clone();
		}
	}
private:
	std::map<string, IEnemy*> EnemyList;
};

int main()
{
	ASpawner*Spawner = new ASpawner();
	//��Ҫ������һ��ʵ��������,����е�UClassҲ����,�ڴ���newĳһ��U�������ģ���
	Spawner->AddEnemyTemplate("Demon",new ADemon(50,10));
	Spawner->AddEnemyTemplate("Ghost", new AGhost(30, 20));

	IEnemy*Demon=Spawner->CreateEnemy("Demon");
	IEnemy* Ghost = Spawner->CreateEnemy("Ghost");

	Demon->Attack(Ghost);
	Ghost->Attack(Demon);
	
	system("pause");
	return 0;
}