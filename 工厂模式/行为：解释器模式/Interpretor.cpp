
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
* 解释器模式：这个模式我并没有想到他可以具体干点什么,根据网上的资料改的,大家简单看一下
* 南京市长江大桥 你可以理解成功南京市长江大桥 也可以 理解成 南京市长 江大桥
* 其实就是给你一个指令,你吧这个指令翻译成什么 在返回上层
*/

// 抽象表达式接口
class IExpression 
{
public:
	//解释这个字符是否正确
	virtual bool Interpret(const string& context) = 0;
};

//终结符表达式
class FTerminalExpression:public IExpression
{
public:
	FTerminalExpression(const string&InData)
	{
		Data = InData;
	}

	virtual bool Interpret(const string& InContext)override
	{
		//find查找失败就会返回npos
		return InContext.find(Data) != string::npos;
	}

private:
	string Data;
};

//与终结符表达式
class FAndExpression :public IExpression
{
public:
	FAndExpression(IExpression* InExpression0, IExpression* InExpression1)
	{
		Expression0 = InExpression0;
		Expression1 = InExpression1;
	}
	//这个InContext里面的内容在 0和1 里存在吗
	virtual bool Interpret(const string& InContext)override
	{
		return Expression0->Interpret(InContext) && Expression1->Interpret(InContext);
	}
private:
	IExpression* Expression0;
	IExpression* Expression1;
};

//与终结符表达式
class FOrExpression :public IExpression
{
public:
	FOrExpression(IExpression* InExpression0, IExpression* InExpression1)
	{
		Expression0 = InExpression0;
		Expression1 = InExpression1;
	}
	//这个InContext里面的内容在 0或者1 里面存在吗
	virtual bool Interpret(const string& InContext)override
	{
		return Expression0->Interpret(InContext) || Expression1->Interpret(InContext);
	}
private:
	IExpression* Expression0;
	IExpression* Expression1;
};

//上下文类
class FTaskContext
{
public:	
	FTaskContext(const string&InInputData)
	{
		InputData = InInputData;
	}

	bool Evaluate(IExpression* InExpression)
	{
		return InExpression->Interpret(InputData);
	}

private:
	string InputData;
};

int main()
{
	//刀
	FTerminalExpression HasSword("Sword");
	//盾牌
	FTerminalExpression HasShield("Shield");
	
	//有刀和盾牌吗
	FAndExpression HasBoth(&HasSword,&HasShield);
	//有其中一个吗
	FOrExpression HasEither(&HasSword,&HasShield);

	string PlayerInput;
	cout<<"输入库存(用逗号分隔的物品):";
	cin>>PlayerInput;

	FTaskContext Context(PlayerInput);
	cout<<"你有剑和盾吗?"<<(Context.Evaluate(&HasBoth)?"Yes":"No");
	cout << "你有剑或盾吗?" << (Context.Evaluate(&HasEither)?"Yes":"No");

	system("pause");
	return 0;
}