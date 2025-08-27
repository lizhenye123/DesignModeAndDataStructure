#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* ��ͣ��ģʽ����ʵ����һ����������,����Ϸ������,Ҳʹ�ý�Ƶ����
* ����Ϸ����ʱ,��ϷҪ֪ͨ���еĽ�ɫֹͣ�˶�,�п�����Ͷ��������,�п����Ǳ��˴��㷿ˮ��������,Ͷ�������������д��GameMode��,��ɫ�򱬽�ɫ��Ҳдһ��,Ҳ��(�㲻���鷳�Ļ�)
* ������Ҫ֪ͨ������Ҫ���Ľ�����Ϊ,��Ҳ������������ҿ�����������ȥ���������߼�
* ���Ҵ���һ����������ʱ,һ����Ҽ���ʱ,���ͻ�ʹ�ù۲���ģʽ,�۲��������,�������ĵ��ý�����Ϸ,���п�����ȫ�յ���,ֻҪ���˵��õ������н�����������
* ��ͣ��ģʽ����Ϸ�����п���Ӧ���ڶ������֮���Э����ͨ�ţ��ر����ڸ��ӵ���Ϸϵͳ�С����磬�����Ϸ��ɫ֮���Э���������Ϸģ��֮���ͨ�ŵ����������ʹ�õ�ͣ��ģʽ���򻯺͹�������
* ����Գ��Ի�һ��ͼ A,B,C,D,E�����,���ǻ������õ��߻��ж���,Ȼ�����ڼӸ���������һ��,��ᷢ�־�5����
*/

class ICharacter
{
public:
	virtual void CallGameOver()=0;

	virtual void GameOverOperate()=0;

};



//���������ϵͳ,���Բ��Ƽ��Լ�д����,���������,��ô�������ͣ�߶���һ������ģʽ
class UMediatorSubsystem
{
public:
	
	static UMediatorSubsystem* GetMediatorSubsystem()
	{
		//��ֻ���ʼ��һ��Ϊ��,����������Բ�һ�� ��̬����ֻ���ʼ��һ��
		static UMediatorSubsystem* Subsystem=nullptr;
		if (Subsystem == nullptr)
		{
			Subsystem = new UMediatorSubsystem();
		}

		return Subsystem;
	}

	void GameOver()
	{
		for (vector<ICharacter*>::iterator Iter = Characters.begin();Iter!=Characters.end();Iter++)
		{
			(*Iter)->GameOverOperate();
		}
	}

	//һ�Ѳ����Լ��ֶ���,����һ������,��Ȼ�ֶ���Ҳ����,Ϊ�˼�,����������ּ���
	void AddPlayer(ICharacter*InPlayer)
	{
		Characters.push_back(InPlayer);
	}
private:
	vector<ICharacter*>Characters;
	UMediatorSubsystem(){}
};


//��Ϸ�еĽ�ɫ
class ACharacter :public ICharacter
{
public:
	ACharacter()
	{
		UMediatorSubsystem::GetMediatorSubsystem()->AddPlayer(this);
	}
	virtual void CallGameOver() override
	{
		UMediatorSubsystem::GetMediatorSubsystem()->GameOver();
	}
 
 	virtual void GameOverOperate() override
	{
		cout << "��Ϸ����ʱ��ɫҪ���������,UI�ȵ�" << endl;
	}
};

int main()
{
	ACharacter* Character = new ACharacter();
	ACharacter* Character1 = new ACharacter();
	ACharacter* Character2 = new ACharacter();
	ACharacter* Character3 = new ACharacter();
	ACharacter* Character4 = new ACharacter();


	Character->CallGameOver();

	system("pause");
	return 0;
}

