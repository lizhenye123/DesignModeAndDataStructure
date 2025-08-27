#include <iostream>
#include <vector>
using namespace std;

/*
* ����ģʽ�����������ǿ������ʵ���Ǹ�������˼,����ǿ�����ԭ��������ģʽҪ���Ӻܶ�,�漰�˲�����������
* ������ϵͳ��,����������������,����������ĳɼ����е�1��,�ܲ��ܰѹ�����������Ǩ�����̵�1��ȥ��
* ���Ըļ�,��ǰ���Ǽ���������,Ȼ����ĳ�����������1��,��������һ�������������
* �͹۲�����Щ����,���۲�����һ�Զ�
* ����ģʽ��Ҫ���ڷ�װ�������󣬽��������ߺ�����ִ���߽����ͨ������ʵ�ֳ��������������еȹ��ܣ��Լ�����������������
*/

class ICommand
{
public:
	virtual~ICommand(){};
	virtual void Execute()=0;
	virtual void Undo()=0;
};

//����������
class UAttackCommand : public ICommand
{
public:
	virtual void Execute()override
	{
		cout << "��������ִ��" << std::endl;
	}
	virtual void Undo()
	{
		cout << "���������ע��" << std::endl;
	}
};

//��Ծ������
class UJumpCommand : public ICommand
{
public:
	virtual void Execute()override
	{
		cout << "��Ծ����ִ��" << std::endl;
	}
	virtual void Undo()
	{
		cout << "��Ծ�����ע��" << std::endl;
	}
};

//���
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
	//һ����˵����ִ���������һ�����ȼ�����,��ʱ��һ��������󶨶������,�����ȼ���ߵ�ִ��,����һ����ȫ��ִ��
	ICommand*MouseLeftKeyCommand=nullptr;
	ICommand*SpaceKeyCommand = nullptr;
};

int main()
{
	UAttackCommand* AttackCommand = new UAttackCommand();
	UJumpCommand * JumpCommand = new UJumpCommand();

	//�Ұ��µļ�������Щ��,����Ϊȷ��һ����,��д��Ϸ�ļ���ʱ��
	//��Ϊ��������Ѿ���װ����,ֱ�Ӹ�Mapping��ļ�������,���԰�Mapping����һ������ĺϼ�,���������е�����д�İ���
	ULocalPlayer*Player = new ULocalPlayer();
	Player->SetMouseLeftKeyCommand(AttackCommand);
	Player->SetSpaceKeyCommand(JumpCommand);
	Player->MouseLeftKeyPressed();
	system("pause");
	return 0;
}