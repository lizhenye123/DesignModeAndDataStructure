#include <iostream>
#include <string>
using namespace std;

/*
* ��ʾ����һ�������� �Ĵ������չʾ
*/

//�������Ľӿ�
class IAbstactServer
{
public:
	virtual void Request()=0;
protected:
	IAbstactServer(){}
};

//��ʵ�ķ�����
class FRealServer:public IAbstactServer
{
public:
	virtual void Request()override
	{
		cout<<"������������"<<endl;
	}
};

//������� �����ʵ���൱�ڷ��ʷ�����ʱ��һ������
//�ڷ��ʷ�������ʱ��������һ��,������˵��ֱ���ҵ�������,���һЩ����Ҫ���鷳
class FProxyServer:public IAbstactServer
{
public:
	FProxyServer(string InName,string InPwd)
	{
		Name=InName;
		Pwd = InPwd;
		InstanceServer=new FRealServer();
	}

	virtual void Request()override
	{
		if ("lzy"==Name && "123456"==Pwd)
		{
			cout<<"����ɹ�"<<endl;
			cout<<"�����������������"<<endl;
			InstanceServer->Request();
			cout<<"�������������"<<endl;
		}else
		{
			cout << "����������ʧ��" << endl;
		}
	}
private:
	string Name;
	string Pwd;
	IAbstactServer* InstanceServer;
};

//int main()
//{
//	IAbstactServer*Proxy = new FProxyServer("lzy","123456");
//	Proxy->Request();
//
//	system("pause");
//	return 0;
//}
