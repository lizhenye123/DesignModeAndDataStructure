#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
* �۲���ģʽ�������������ʹ�û��Ǻܶ��,������������о������ǳ�˵�Ĵ���,�����ಥ�������
* A����B��״̬�Ժ�,B�����ı��֪ͨA
*/


//�۲���,���۲���״̬
class AObserver
{
public:
	virtual void Update(string InMessage)=0;
protected:
	AObserver(){};
};

//���۲���,֪ͨ�۲���״̬�ı���
class ASubject
{
public:
	virtual void AddObserver(AObserver*InObserver)=0;
	virtual void RemoveObserver(AObserver* InObserver)=0;

	//�����ʵ���ǹ㲥,���߹۲���,������鷢����,Ҫ����Ӧ������
	virtual void NoitfyObserver()=0;
protected:
	ASubject(){}
};

class ACharacter:public ASubject
{
public:
	ACharacter(){};
	virtual void AddObserver(AObserver* InObserver) override
	{
		ArrObserver.push_back(InObserver);
	}

	virtual void RemoveObserver(AObserver* InObserver)override
	{
		vector<AObserver*>::iterator Iter = find(ArrObserver.begin(), ArrObserver.end(),InObserver);
		if (Iter!= ArrObserver.end())
		{
			ArrObserver.erase(Iter);
		}
	}

	virtual void NoitfyObserver()override
	{
		for (vector<AObserver*>::iterator Iter = ArrObserver.begin(); Iter != ArrObserver.end(); Iter++) {
			(*Iter)->Update("��ɫ����,�����������");

		}
	}

private:
	vector<AObserver*>ArrObserver;
};

class ALeaderboard :public AObserver
{
public:
	ALeaderboard(){}
	virtual void Update(string InMessage)override
	{
		cout<<InMessage<<endl;
		cout<<"�������а���Ϣ,׼����ɫ�����߼�"<<endl;
	}
};

int main()
{
	ACharacter*Character =new ACharacter();
	ALeaderboard* Leaderboard = new ALeaderboard();
	
	Character->AddObserver(Leaderboard);
	Character->NoitfyObserver();

	system("pause");
	return 0;
}