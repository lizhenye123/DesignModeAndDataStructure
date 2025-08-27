#include <iostream>
using namespace std;

/*
* 模板方法：模板类实现的就是不变的方法和算法的更加,而需要变化的地方,都通过抽象方法,把实现延迟到子类来实现,还通过父类的定义来约束子类的行为
* 核心理解其实就是：即要约束子类的行为,又要为子类提供公共功能
* 在虚幻引擎中,AActor UObject其实就可以理解为是一个模板类,在关卡中不是AActor的没法实例化,这其实就是父类约束的行为,已及BeginPlay,InitialComponent等等
* BeginPlay什么时候走AActor已经给定义了,你能做的事情只是重写他的方法,而不是修改他的调用位置
*/

/*
* 本示例以虚幻引擎中的AActor为示例
*/

class AActor
{
protected:
	virtual void BeginPlay()
	{
		cout<<"父类BeginPlay执行了"<<endl;
	}

	virtual void PreInitializeComponents()=0;
	virtual void InitializeComponents()=0;
	virtual void PostInitializeComponents()=0;

public:
	//他是在Actor中的FinishSpawning中调用的,想看的可以去看看
	void PostActorConstruction()
	{
		PreInitializeComponents();
		InitializeComponents();
		PostInitializeComponents();
		//这个是在PostActorConstruction的函数内的另一个函数调用的,为了演示直接提上来了
		BeginPlay();
	}
};

//当然虚幻的继承顺序不是这样的,我只是演示
class ACharacter:public AActor
{
protected:
	virtual void BeginPlay()override
	{
		AActor::BeginPlay();
		cout<<"角色开始初始化完成,可以开始后面的操作"<<endl;
	}

	virtual void PreInitializeComponents()override
	{
		cout << "构建CapsuleComponent" << endl;
		cout<<"构建CharacterMovementComponent"<<endl;
		cout << "构建SkeleteMeshComponent" << endl;
	}

	virtual void InitializeComponents() override
	{
		cout << "初始化CapsuleComponent" << endl;
		cout << "初始化CharacterMovementComponent" << endl;
		cout << "初始化SkeleteMeshComponent" << endl;
	}

	virtual void PostInitializeComponents()override
	{
		cout << "CapsuleComponent构建完成" << endl;
		cout << "CharacterMovementComponent构建完成" << endl;
		cout << "SkeleteMeshComponent构建完成" << endl;
	}
};

//当然虚幻的继承顺序不是这样的,我只是演示
class AGrass :public AActor
{
protected:
	virtual void BeginPlay()override
	{
		AActor::BeginPlay();
		cout << "植物开始初始化完成,可以开始后面的操作" << endl;
	}

	virtual void PreInitializeComponents()override
	{
		cout << "构建StaticMeshComponent" << endl;
	}

	virtual void InitializeComponents() override
	{
		cout << "初始化StaticMeshComponent" << endl;
	}

	virtual void PostInitializeComponents()override
	{
		cout << "StaticMeshComponent构建完成" << endl;
	}
};

//把Main当成世界就可以
int main()
{
	ACharacter*Character = new ACharacter();
	//里面的操作的由父类来决定
	Character->PostActorConstruction();

	system("pause");
	return 0;
}