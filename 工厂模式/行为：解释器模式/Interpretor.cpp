
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
* ������ģʽ�����ģʽ�Ҳ�û���뵽�����Ծ���ɵ�ʲô,�������ϵ����ϸĵ�,��Ҽ򵥿�һ��
* �Ͼ��г������� ��������ɹ��Ͼ��г������� Ҳ���� ���� �Ͼ��г� ������
* ��ʵ���Ǹ���һ��ָ��,������ָ����ʲô �ڷ����ϲ�
*/

// ������ʽ�ӿ�
class IExpression 
{
public:
	//��������ַ��Ƿ���ȷ
	virtual bool Interpret(const string& context) = 0;
};

//�ս�����ʽ
class FTerminalExpression:public IExpression
{
public:
	FTerminalExpression(const string&InData)
	{
		Data = InData;
	}

	virtual bool Interpret(const string& InContext)override
	{
		//find����ʧ�ܾͻ᷵��npos
		return InContext.find(Data) != string::npos;
	}

private:
	string Data;
};

//���ս�����ʽ
class FAndExpression :public IExpression
{
public:
	FAndExpression(IExpression* InExpression0, IExpression* InExpression1)
	{
		Expression0 = InExpression0;
		Expression1 = InExpression1;
	}
	//���InContext����������� 0��1 �������
	virtual bool Interpret(const string& InContext)override
	{
		return Expression0->Interpret(InContext) && Expression1->Interpret(InContext);
	}
private:
	IExpression* Expression0;
	IExpression* Expression1;
};

//���ս�����ʽ
class FOrExpression :public IExpression
{
public:
	FOrExpression(IExpression* InExpression0, IExpression* InExpression1)
	{
		Expression0 = InExpression0;
		Expression1 = InExpression1;
	}
	//���InContext����������� 0����1 ���������
	virtual bool Interpret(const string& InContext)override
	{
		return Expression0->Interpret(InContext) || Expression1->Interpret(InContext);
	}
private:
	IExpression* Expression0;
	IExpression* Expression1;
};

//��������
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
	//��
	FTerminalExpression HasSword("Sword");
	//����
	FTerminalExpression HasShield("Shield");
	
	//�е��Ͷ�����
	FAndExpression HasBoth(&HasSword,&HasShield);
	//������һ����
	FOrExpression HasEither(&HasSword,&HasShield);

	string PlayerInput;
	cout<<"������(�ö��ŷָ�����Ʒ):";
	cin>>PlayerInput;

	FTaskContext Context(PlayerInput);
	cout<<"���н��Ͷ���?"<<(Context.Evaluate(&HasBoth)?"Yes":"No");
	cout << "���н������?" << (Context.Evaluate(&HasEither)?"Yes":"No");

	system("pause");
	return 0;
}