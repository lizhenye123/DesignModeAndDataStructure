#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* 备忘录模式：在游戏中应用的地方是存档,但虚幻引擎提供的存档笔者并没有找到管理类,而是保存成了一个Saved里的文件
* 还有一些其他应用场景,Git的提交和回档,也是备忘录的一种,棋类游戏的悔棋也是
*/

//备忘录,可以想象成单机游戏里的某一个存档
class USaveGame
{
public:
	USaveGame(const string&InSaveMessage)
	{
		SaveMessage = InSaveMessage;
	}

	string GetSaveMessage()
	{
		return SaveMessage;
	}

private:
	string SaveMessage;
};

//当前在运行的游戏
class Game
{
public:
	
	void SetState(const string&InState)
	{
		CurrentState = InState;
	}

	//保存当前的游戏状态
	USaveGame*SaveGameToMemento()
	{
		return new USaveGame(CurrentState);
	}

	//返回以前保存的存档
	void RestoreFromMemento(USaveGame* InSaveGame)
	{
		CurrentState = InSaveGame->GetSaveMessage();
	}

	void Print()
	{
		cout<< CurrentState<<endl;
	}

private:
	string CurrentState;
};

//游戏存档的管理器,可以想象成玩游戏保存的那一排存档列表
class USaveGameManager
{
public:
	void Save(USaveGame*InSaveGame)
	{
		AllSaveGames.push_back(InSaveGame);
	}

	USaveGame* Load(int InIndex)
	{
		if (InIndex>=0 && InIndex< AllSaveGames.size())
		{
			return AllSaveGames[InIndex];
		} else
		{
			cout<<"没有找到这个存档"<<endl;
			return nullptr;
		}
		return nullptr;
	}
private:
	vector<USaveGame*>AllSaveGames;
};

int main()
{
	Game*CurrentGame = new Game();
	CurrentGame->SetState("当前是第一关");
	CurrentGame->Print();
	USaveGameManager* SaveGameManager = new USaveGameManager();
	//把第一关数据保存到管理器
	SaveGameManager->Save(CurrentGame->SaveGameToMemento());

	CurrentGame->SetState("当前是第二关");
	CurrentGame->Print();

	CurrentGame->SetState("当前是第三关");
	CurrentGame->Print();

	//退回第一关
	CurrentGame->RestoreFromMemento(SaveGameManager->Load(0));
	CurrentGame->Print();
	system("pause");
	return 0;
}