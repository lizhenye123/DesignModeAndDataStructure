#include <iostream>
using namespace std;

/*
* ����ģʽ,��Ҫ���ǵ����ط���
* ����������������ʵ����,�������һ����ͨ���Ե�,����Ŀ����һ���ƶ����,���Ե������Ŀ����ʹ
* ������ģʽ�������������һ�ַֻ�,�ó���Աȥά��,��ص�һ�����
* �����ط���:һ�����һ����Ի�ʱ,Ӧ��ֻ֪���Է�,��֪���Է������ʲô��
*/

/*
* ��ʾ����һ���������Ϊʾ����ʾ
*/

//����ĵƹ�
class ULightFacade
{
public:
	void TurnOn() {
		cout << "�����ƿ���" << endl;
	}
	void TurnOff() {
		cout << "�����ƹر�" << endl;
	}
};

//����Ĵ�����
class USensorFacade
{
public:
	void Active() 
	{
		cout << "����������" << endl;
	}
	void Deactive() 
	{
		cout << "�������ر�" << endl;
	}
};

//������
class UAlarm 
{
public:
	void Active() 
	{
		cout << "����������" << endl;
	}
	void Deactive() 
	{
		cout << " �������ر�" << endl;
	}
};

class UCamera
{
public:
	UCamera()
	{
		Light=new ULightFacade();
		Sensor=new USensorFacade();
		Alarm=new UAlarm();
	}
	void Photograph()
	{
		cout<<"��ʼ����"<<endl;
		Sensor->Active();
		Light->TurnOff();
	}

	void CameraError()
	{
		cout << "�����������" << endl;
		Alarm->Deactive();
	}

private:
	ULightFacade*Light;
	USensorFacade* Sensor;
	UAlarm * Alarm;
};


int main()
{
	UCamera*Camera = new UCamera();
	Camera->Photograph();

	system("pause");
	return 0;
}