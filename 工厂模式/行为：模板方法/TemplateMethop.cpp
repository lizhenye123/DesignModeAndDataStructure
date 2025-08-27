#include <iostream>
using namespace std;

/*
* ģ�巽����ģ����ʵ�ֵľ��ǲ���ķ������㷨�ĸ���,����Ҫ�仯�ĵط�,��ͨ�����󷽷�,��ʵ���ӳٵ�������ʵ��,��ͨ������Ķ�����Լ���������Ϊ
* ���������ʵ���ǣ���ҪԼ���������Ϊ,��ҪΪ�����ṩ��������
* �����������,AActor UObject��ʵ�Ϳ������Ϊ��һ��ģ����,�ڹؿ��в���AActor��û��ʵ����,����ʵ���Ǹ���Լ������Ϊ,�Ѽ�BeginPlay,InitialComponent�ȵ�
* BeginPlayʲôʱ����AActor�Ѿ���������,������������ֻ����д���ķ���,�������޸����ĵ���λ��
*/

/*
* ��ʾ������������е�AActorΪʾ��
*/

class AActor
{
protected:
	virtual void BeginPlay()
	{
		cout<<"����BeginPlayִ����"<<endl;
	}

	virtual void PreInitializeComponents()=0;
	virtual void InitializeComponents()=0;
	virtual void PostInitializeComponents()=0;

public:
	//������Actor�е�FinishSpawning�е��õ�,�뿴�Ŀ���ȥ����
	void PostActorConstruction()
	{
		PreInitializeComponents();
		InitializeComponents();
		PostInitializeComponents();
		//�������PostActorConstruction�ĺ����ڵ���һ���������õ�,Ϊ����ʾֱ����������
		BeginPlay();
	}
};

//��Ȼ��õļ̳�˳����������,��ֻ����ʾ
class ACharacter:public AActor
{
protected:
	virtual void BeginPlay()override
	{
		AActor::BeginPlay();
		cout<<"��ɫ��ʼ��ʼ�����,���Կ�ʼ����Ĳ���"<<endl;
	}

	virtual void PreInitializeComponents()override
	{
		cout << "����CapsuleComponent" << endl;
		cout<<"����CharacterMovementComponent"<<endl;
		cout << "����SkeleteMeshComponent" << endl;
	}

	virtual void InitializeComponents() override
	{
		cout << "��ʼ��CapsuleComponent" << endl;
		cout << "��ʼ��CharacterMovementComponent" << endl;
		cout << "��ʼ��SkeleteMeshComponent" << endl;
	}

	virtual void PostInitializeComponents()override
	{
		cout << "CapsuleComponent�������" << endl;
		cout << "CharacterMovementComponent�������" << endl;
		cout << "SkeleteMeshComponent�������" << endl;
	}
};

//��Ȼ��õļ̳�˳����������,��ֻ����ʾ
class AGrass :public AActor
{
protected:
	virtual void BeginPlay()override
	{
		AActor::BeginPlay();
		cout << "ֲ�￪ʼ��ʼ�����,���Կ�ʼ����Ĳ���" << endl;
	}

	virtual void PreInitializeComponents()override
	{
		cout << "����StaticMeshComponent" << endl;
	}

	virtual void InitializeComponents() override
	{
		cout << "��ʼ��StaticMeshComponent" << endl;
	}

	virtual void PostInitializeComponents()override
	{
		cout << "StaticMeshComponent�������" << endl;
	}
};

//��Main��������Ϳ���
int main()
{
	ACharacter*Character = new ACharacter();
	//����Ĳ������ɸ���������
	Character->PostActorConstruction();

	system("pause");
	return 0;
}