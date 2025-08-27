#include <iostream>
using namespace std;

//对应的平台需要的分辨率
class IFrameAPI
{
public:
	virtual void Draw()=0;
protected:
	IFrameAPI(){};
};

//PC平台的UI布局分辨率
class FComputerFrame :public IFrameAPI
{
public:
	FComputerFrame(int InPins)
	{
		M_Pins = InPins;
	}

	virtual void Draw()override
	{
		cout << "现在是PC机平台,适用的分辨率是：" << M_Pins << endl;
	}

private:
	int M_Pins;
};

//移动端平台的UI布局分辨率
class FMobileFrame :public IFrameAPI
{
public:
	FMobileFrame(int InPins)
	{
		M_Pins = InPins;
	}

	virtual void Draw()override
	{
		cout << "现在是移动端平台,适用的分辨率是：" << M_Pins << endl;
	}

private:
	int M_Pins;
};

//分辨率的布局器
class ILayoutAPI
{
public:
	virtual void InstallFrame()=0;

protected:
	ILayoutAPI(){}
};

//高分辨率主题
class FHightLayout:public ILayoutAPI
{
public:
	FHightLayout(int InFrameAdpaterPins)
	{
		M_FrameAdpaterPins = InFrameAdpaterPins;
	}

	virtual void InstallFrame()override
	{
		cout<<"现在使用的高分辨率配置,分辨率："<<M_FrameAdpaterPins<<endl;
	}

private:
	int M_FrameAdpaterPins;
};

//低分辨率主题
class FLowLayout:public ILayoutAPI
{
public:
	FLowLayout(int InFrameAdpaterPins)
	{
		M_FrameAdpaterPins = InFrameAdpaterPins;
	}
	
	virtual void InstallFrame()override
	{
		cout<<"现在使用低分辨率的配置,分辨率："<<M_FrameAdpaterPins<<endl;
	}
private:
	int M_FrameAdpaterPins;
};

//抽象工厂
//当前示例主要原来处理 各个端的具体UI类 和 各个端的分辨率设置
//工厂类大多数只会处理创建对应的环境,而不是组合他们
//列如：他只会创建电脑需要的零件,但他不会去处理组装电脑这个事情
class IAbstractFactory
{
public:
	virtual IFrameAPI*CreateFrameAPI()=0;
	virtual ILayoutAPI*CreateLayoutAPI()=0;
protected:
	IAbstractFactory(){}
};

//PC的平台要创建的UI类
class FWindows : public IAbstractFactory
{
public:
	virtual IFrameAPI* CreateFrameAPI()override
	{
		return new FComputerFrame(1024);
	}

	virtual ILayoutAPI* CreateLayoutAPI()override
	{
		return new FHightLayout(1024);
	}
};

//手机端要创建的UI类
class FIphone :public IAbstractFactory
{
public:
	virtual IFrameAPI* CreateFrameAPI()override
	{
		return new FComputerFrame(800);
	}

	virtual ILayoutAPI* CreateLayoutAPI()override
	{
		return new FHightLayout(800);
	}
};

//聚合类,使用Windows 或 Iphone时
//当前这个类只处理，目标固定平台的操作
class FAdvancedGuiEngineer
{
public:
	void PrepareMaterials(IAbstractFactory* InFactory)
	{
		Frame = InFactory->CreateFrameAPI();
		Layout = InFactory->CreateLayoutAPI();
		Frame->Draw();
		Layout->InstallFrame();
	}
private:
	IFrameAPI* Frame;
	ILayoutAPI* Layout;
};

int main()
{
	FAdvancedGuiEngineer * Engine=new FAdvancedGuiEngineer();
	Engine->PrepareMaterials(new FWindows());

	system("pause");
	return 0;
}
