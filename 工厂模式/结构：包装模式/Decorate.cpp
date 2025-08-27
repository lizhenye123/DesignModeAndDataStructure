#include <iostream>
#include <sstream>
using namespace std;

/*
* 包装模式：在虚幻中UI中其实就是一种包装模式,
* 当你想绘制一个UI的大厅页面时,总不在UI页面写一个可以向下滚的排行榜列表
* 当在游戏中想在线打开排行榜时在写一个可以向下滚的排行榜
* 所以会单独写一个下拉框,让他适配这些UI页面,而下拉框也要适配文本,图片等等
* 其实和组件模式差不多,在笔者的理解里就是一种东西
*/

/*
* 本示例以一个构建UI的页面为主
*/


class UView
{
public:
	virtual void Draw(){}
};

//抽象装饰类
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

//滚动框
class UScrollBars:public UWidget
{
public:
	UScrollBars(UView*InView)
	:UWidget(InView){}

protected:
	//绘制滚动条
	void DrawScrollBars()
	{
		cout<<"绘制了一个滚动条"<<endl;
	}
public:
	virtual void Draw()override
	{
		UWidget::Draw();
		DrawScrollBars();
	}
};

//绘制边框
class UBorder:public UWidget
{
public:
	UBorder(UView* InView)
		:UWidget(InView) {}
protected:
	void DrawBorder()
	{
		cout<<"绘制了一个边框"<<endl;
	}
public:
	virtual void Draw()override
	{
		UWidget::Draw();
		DrawBorder();
	}
};

//文本视图
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
		cout << "绘制了一个文本视图" << endl;
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

//绘制的窗口
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
	//窗口上可以摆放的控件
	UView* ArrView[10];
};

int main()
{
	UWindows Windos;

	UTextBlock TextBlock("这是一个文本视图");

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