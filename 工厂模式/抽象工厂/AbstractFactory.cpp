#include <iostream>
using namespace std;

//��Ӧ��ƽ̨��Ҫ�ķֱ���
class IFrameAPI
{
public:
	virtual void Draw()=0;
protected:
	IFrameAPI(){};
};

//PCƽ̨��UI���ֱַ���
class FComputerFrame :public IFrameAPI
{
public:
	FComputerFrame(int InPins)
	{
		M_Pins = InPins;
	}

	virtual void Draw()override
	{
		cout << "������PC��ƽ̨,���õķֱ����ǣ�" << M_Pins << endl;
	}

private:
	int M_Pins;
};

//�ƶ���ƽ̨��UI���ֱַ���
class FMobileFrame :public IFrameAPI
{
public:
	FMobileFrame(int InPins)
	{
		M_Pins = InPins;
	}

	virtual void Draw()override
	{
		cout << "�������ƶ���ƽ̨,���õķֱ����ǣ�" << M_Pins << endl;
	}

private:
	int M_Pins;
};

//�ֱ��ʵĲ�����
class ILayoutAPI
{
public:
	virtual void InstallFrame()=0;

protected:
	ILayoutAPI(){}
};

//�߷ֱ�������
class FHightLayout:public ILayoutAPI
{
public:
	FHightLayout(int InFrameAdpaterPins)
	{
		M_FrameAdpaterPins = InFrameAdpaterPins;
	}

	virtual void InstallFrame()override
	{
		cout<<"����ʹ�õĸ߷ֱ�������,�ֱ��ʣ�"<<M_FrameAdpaterPins<<endl;
	}

private:
	int M_FrameAdpaterPins;
};

//�ͷֱ�������
class FLowLayout:public ILayoutAPI
{
public:
	FLowLayout(int InFrameAdpaterPins)
	{
		M_FrameAdpaterPins = InFrameAdpaterPins;
	}
	
	virtual void InstallFrame()override
	{
		cout<<"����ʹ�õͷֱ��ʵ�����,�ֱ��ʣ�"<<M_FrameAdpaterPins<<endl;
	}
private:
	int M_FrameAdpaterPins;
};

//���󹤳�
//��ǰʾ����Ҫԭ������ �����˵ľ���UI�� �� �����˵ķֱ�������
//����������ֻ�ᴦ������Ӧ�Ļ���,�������������
//���磺��ֻ�ᴴ��������Ҫ�����,��������ȥ������װ�����������
class IAbstractFactory
{
public:
	virtual IFrameAPI*CreateFrameAPI()=0;
	virtual ILayoutAPI*CreateLayoutAPI()=0;
protected:
	IAbstractFactory(){}
};

//PC��ƽ̨Ҫ������UI��
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

//�ֻ���Ҫ������UI��
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

//�ۺ���,ʹ��Windows �� Iphoneʱ
//��ǰ�����ֻ����Ŀ��̶�ƽ̨�Ĳ���
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
