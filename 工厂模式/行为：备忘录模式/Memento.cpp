#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* ����¼ģʽ������Ϸ��Ӧ�õĵط��Ǵ浵,����������ṩ�Ĵ浵���߲�û���ҵ�������,���Ǳ������һ��Saved����ļ�
* ����һЩ����Ӧ�ó���,Git���ύ�ͻص�,Ҳ�Ǳ���¼��һ��,������Ϸ�Ļ���Ҳ��
*/

//����¼,��������ɵ�����Ϸ���ĳһ���浵
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

//��ǰ�����е���Ϸ
class Game
{
public:
	
	void SetState(const string&InState)
	{
		CurrentState = InState;
	}

	//���浱ǰ����Ϸ״̬
	USaveGame*SaveGameToMemento()
	{
		return new USaveGame(CurrentState);
	}

	//������ǰ����Ĵ浵
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

//��Ϸ�浵�Ĺ�����,�������������Ϸ�������һ�Ŵ浵�б�
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
			cout<<"û���ҵ�����浵"<<endl;
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
	CurrentGame->SetState("��ǰ�ǵ�һ��");
	CurrentGame->Print();
	USaveGameManager* SaveGameManager = new USaveGameManager();
	//�ѵ�һ�����ݱ��浽������
	SaveGameManager->Save(CurrentGame->SaveGameToMemento());

	CurrentGame->SetState("��ǰ�ǵڶ���");
	CurrentGame->Print();

	CurrentGame->SetState("��ǰ�ǵ�����");
	CurrentGame->Print();

	//�˻ص�һ��
	CurrentGame->RestoreFromMemento(SaveGameManager->Load(0));
	CurrentGame->Print();
	system("pause");
	return 0;
}