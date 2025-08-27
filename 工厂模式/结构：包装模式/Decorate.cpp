#include <iostream>
#include <sstream>
using namespace std;

/*
* ��װģʽ���������UI����ʵ����һ�ְ�װģʽ,
* ���������һ��UI�Ĵ���ҳ��ʱ,�ܲ���UIҳ��дһ���������¹������а��б�
* ������Ϸ�������ߴ����а�ʱ��дһ���������¹������а�
* ���Իᵥ��дһ��������,����������ЩUIҳ��,��������ҲҪ�����ı�,ͼƬ�ȵ�
* ��ʵ�����ģʽ���,�ڱ��ߵ���������һ�ֶ���
*/

/*
* ��ʾ����һ������UI��ҳ��Ϊ��
*/


class UView
{
public:
	virtual void Draw(){}
};

//����װ����
class UWidget :public UView
{
public:
	UWidget(){}
	UWidget(UView*InView)
	{
		View=InView;
	}

	virtual void Draw() override
	{
		View->Draw();
	}

private:
	UView*View;
};

//������
class UScrollBars:public UWidget
{
public:
	UScrollBars(UView*InView)
	:UWidget(InView){}

protected:
	//���ƹ�����
	void DrawScrollBars()
	{
		cout<<"������һ��������"<<endl;
	}
public:
	virtual void Draw()override
	{
		UWidget::Draw();
		DrawScrollBars();
	}
};

//���Ʊ߿�
class UBorder:public UWidget
{
public:
	UBorder(UView* InView)
		:UWidget(InView) {}
protected:
	void DrawBorder()
	{
		cout<<"������һ���߿�"<<endl;
	}
public:
	virtual void Draw()override
	{
		UWidget::Draw();
		DrawBorder();
	}
};

//�ı���ͼ
class UTextBlock:public UWidget
{
public:
	UTextBlock(string InText)
	{
		SetWindowText(InText);
	}
protected:
	void DrawTextView()
	{
		cout << "������һ���ı���ͼ" << endl;
	}

	string Text;

public:
	virtual void Draw()override
	{
		UWidget::Draw();
		DrawTextView();
	}

	void SetWindowText(string InText)
	{
		Text= InText;
	}

	string GetWindowText()
	{
		return Text;
	}
};

//���ƵĴ���
class UWindows
{
public:
	UWindows()
	{
		ZeroMemory(ArrView, sizeof(UView*) * 10);
	}

	void Draw()
	{
		for (int i =0;i<10;i++)
		{
			if (ArrView[i]!=nullptr)
			{
				ArrView[i]->Draw();
			}
		}
	}

	void AddWidget(UView*InView)
	{
		for (int i =0;i<10;i++)
		{
			if (ArrView[i]==nullptr)
			{
				ArrView[i] = InView;
				return;
			}
		}
	}

	void RemoveWidget(UView* InView)
	{
		for (int i = 0; i < 10; i++)
		{
			if (ArrView[i] == InView)
			{
				ArrView[i] = nullptr;
				return;
			}
		}
	}

private:
	//�����Ͽ��԰ڷŵĿؼ�
	UView* ArrView[10];
};

int main()
{
	UWindows Windos;

	UTextBlock TextBlock("����һ���ı���ͼ");

	Windos.AddWidget(&TextBlock);
	Windos.Draw();
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	Windos.RemoveWidget(&TextBlock);

	UScrollBars*Scroll = new UScrollBars(&TextBlock);
	Windos.AddWidget(Scroll);
	Windos.Draw();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	Windos.RemoveWidget(Scroll);

	system("pause");
	return 0;
}