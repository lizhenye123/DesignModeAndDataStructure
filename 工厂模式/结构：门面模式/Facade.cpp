#include <iostream>
using namespace std;

/*
* 门面模式,主要就是迪米特法则
* 这个和组件的区别其实就是,组件是有一部分通用性的,这项目做了一个移动组件,可以到别的项目继续使
* 而门面模式是针对于这个类的一种分化,让程序员去维护,相关的一类代码
* 迪米特法则:一个类和一个类对话时,应该只知道对方,不知道对方的组件什么的
*/

/*
* 本示例以一个相机来作为示例演示
*/

//相机的灯光
class ULightFacade
{
public:
	void TurnOn() {
		cout << "照明灯开启" << endl;
	}
	void TurnOff() {
		cout << "照明灯关闭" << endl;
	}
};

//相机的传感器
class USensorFacade
{
public:
	void Active() 
	{
		cout << "传感器启动" << endl;
	}
	void Deactive() 
	{
		cout << "传感器关闭" << endl;
	}
};

//报警器
class UAlarm 
{
public:
	void Active() 
	{
		cout << "报警器启动" << endl;
	}
	void Deactive() 
	{
		cout << " 报警器关闭" << endl;
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
		cout<<"开始拍照"<<endl;
		Sensor->Active();
		Light->TurnOff();
	}

	void CameraError()
	{
		cout << "相机出问题了" << endl;
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