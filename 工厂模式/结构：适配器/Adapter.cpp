#include <iostream>
#include <deque>
#include <stack>
using namespace std;

/*
* ������ģʽ,�ڿ����е�ʹ��Ƶ�ʻ���ͦ�ߵ�
* ������UE��,ʹ��FStringת��FName��FText��uint32ɶ���Լ�TArrayת��TSet���Ƿǳ�������һЩ����
* ��ε�ʾ��,��һ�������ʾ��һ��
* �����ʹ��stl��deque��Stack��һ��������ʾ��
*/

//����ϵ����ڵĲ���
class FThreePhaseOutlet
{
public:
	void DoThreePhasePlug()
	{
		cout<<"���ڲ�ͷ����"<<endl;
	}
};

//����ϵĶ��ڵĲ���
class ITwoPhaseOutlet
{
public:
	virtual void DoPlug()=0;
};

//ת����
class FOutletConverter:public ITwoPhaseOutlet
{
public:
	FOutletConverter(FThreePhaseOutlet* InThreePhase)
	{
		ThreePhase = InThreePhase;
	}
	virtual void DoPlug()override
	{
		ThreePhase->DoThreePhasePlug();
		DoConvertor();
	}
	void DoConvertor()
	{
		cout<<"���ڽ����ڲ�ͷת��Ϊ���ڲ�ͷ"<<endl;
	}

private:
	FThreePhaseOutlet* ThreePhase;
};

int main()
{

	FThreePhaseOutlet* ThreePhase = new FThreePhaseOutlet();
	FOutletConverter*Converter = new FOutletConverter(ThreePhase);
	Converter->DoPlug();

	//stl�е�����
	deque<int> MyDeq(3,100);
	stack<int> MySta(MyDeq);

	system("pause");
	return 0;
}