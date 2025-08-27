#include <iostream>
#include <vector>
using namespace std;

/*
* 命令模式：在虚幻中增强输入其实就是个差不多的意思,但增强输入比原本的命令模式要复杂很多,涉及了不少其他东西
* 在输入系统中,但按下鼠标左键攻击,但现在我想改成键盘中的1键,总不能把攻击代码从鼠标迁到键盘的1键去吧
* 所以改键,当前类是监听鼠标左键,然后你改成了这个类监听1键,这个类就是一个监听输入的类
* 和观察者有些相似,但观察者是一对多
* 命令模式主要用于封装操作请求，将请求发起者和请求执行者解耦。它通常用于实现撤销、重做、队列等功能，以及将操作参数化传递
*/

class ICommand
{
public:
	virtual~ICommand(){};
	virtual void Execute()=0;
	virtual void Undo()=0;
};

//攻击的命令
class UAttackCommand : public ICommand
{
public:
	virtual void Execute()override
	{
		cout << "攻击命令执行" << std::endl;
	}
	virtual void Undo()
	{
		cout << "攻击命令撤销注册" << std::endl;
	}
};

//跳跃的命令
class UJumpCommand : public ICommand
{
public:
	virtual void Execute()override
	{
		cout << "跳跃命令执行" << std::endl;
	}
	virtual void Undo()
	{
		cout << "跳跃命令撤销注册" << std::endl;
	}
};

//玩家
class ULocalPlayer
{
public:
	void SetMouseLeftKeyCommand(ICommand*InCommand)
	{
		MouseLeftKeyCommand = InCommand;
	}

	void SetSpaceKeyCommand(ICommand* InCommand)
	{
		SpaceKeyCommand = InCommand;
	}

	void MouseLeftKeyPressed()
	{
		if (MouseLeftKeyCommand)
		{
			MouseLeftKeyCommand->Execute();
		}
	}

	void SpaceKeyPressed(ICommand* InCommand)
	{
		if (MouseLeftKeyCommand)
		{
			MouseLeftKeyCommand->Execute();
		}
	}

	void UndoMouseLeftKeyCommand()
	{
		MouseLeftKeyCommand->Undo();
		MouseLeftKeyCommand=nullptr;
	}

	void UndoSpaceKeyCommand()
	{
		SpaceKeyCommand->Undo();
		SpaceKeyCommand = nullptr;
	}

private:
	//一般来说储存执行命令的是一个优先级队列,有时候一个按键会绑定多个命令,按优先级最高的执行,或者一次性全部执行
	ICommand*MouseLeftKeyCommand=nullptr;
	ICommand*SpaceKeyCommand = nullptr;
};

int main()
{
	UAttackCommand* AttackCommand = new UAttackCommand();
	UJumpCommand * JumpCommand = new UJumpCommand();

	//我按下的键还是那些键,但行为确不一样了,在写游戏改键的时候
	//因为虚幻引擎已经封装好了,直接改Mapping里的键就行了,可以吧Mapping理解成一个命令的合集,里面是所有的你填写的按键
	ULocalPlayer*Player = new ULocalPlayer();
	Player->SetMouseLeftKeyCommand(AttackCommand);
	Player->SetSpaceKeyCommand(JumpCommand);
	Player->MouseLeftKeyPressed();
	system("pause");
	return 0;
}