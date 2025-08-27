#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <map>
using namespace std;

/*
* 原型模式 原生C++是没有UE中的UClass这种类型的东西的
* 主要的核心是new了第一个类以后由生成器去保存这个类型的实例,可以把new的这个第一个类当成是UE中的UClass,毕竟Ue的内存里也有一个UClass
* 在后期要生成怪物的时候,根据Key去查找,然后去创建出对应的实例
* 在怪物中他的核心就是那个Clone那个函数,以第一个为模板创建出与他一模一样的实例
*/

/*
* 本示例,以做一个怪物生成器为参考
*/

//int 转字符串
template<class T>
string IToStr(T Value)
{
	stringstream SS;
	SS<<Value;
	return SS.str();
}

//敌人的虚类
class IEnemy
{
public:
	virtual void Attack(IEnemy*InTarget)=0;
	virtual void HitDamage(const float &InDamage)=0;
	virtual string GetName()=0;
	//这个克隆将会主要用来根据这个模板来生成其他的怪物
	virtual IEnemy* Clone()=0;

	virtual ~IEnemy(){}
protected:
	IEnemy(){}
};

//这用A,不使F了,主要是以虚幻引擎的命名规范,不是A类没办法创建到游戏场景中
//幽灵类
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
		cout<< GetName()<<"攻击了"<< InTarget->GetName()<<endl;
		InTarget->HitDamage(AttackDamage);
	}

	virtual void HitDamage(const float& InDamage)override
	{
		Health-=InDamage;
		cout << GetName() <<"受到了"<< InDamage <<"伤害" << endl;
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

//恶魔类
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
		cout << GetName() << "攻击了" << InTarget->GetName() << endl;
		InTarget->HitDamage(AttackDamage);
	}

	virtual void HitDamage(const float& InDamage)override
	{
		Health -= InDamage;
		cout << GetName() << "受到了" << InDamage << "伤害" << endl;
	}

	virtual IEnemy* Clone()
	{
		Count++;
		ADemon*CreateDemon = new ADemon(Health, AttackDamage);
		//平常的怪物不使用这个,模板来使用创建命名
		CreateDemon->Count=-1;

		return CreateDemon;
	}

public:
	float Health = 20;
	float AttackDamage = 5;
	int Count = 0;
};

//生成器
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
	//主要是依靠一个实例来复制,虚幻中的UClass也是在,内存中new某一个U类的制造模板的
	Spawner->AddEnemyTemplate("Demon",new ADemon(50,10));
	Spawner->AddEnemyTemplate("Ghost", new AGhost(30, 20));

	IEnemy*Demon=Spawner->CreateEnemy("Demon");
	IEnemy* Ghost = Spawner->CreateEnemy("Ghost");

	Demon->Attack(Ghost);
	Ghost->Attack(Demon);
	
	system("pause");
	return 0;
}