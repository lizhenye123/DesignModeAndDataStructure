#include <iostream>
#include <string>
using namespace std;

/*
* 本示例以一个服务器 的代理层来展示
*/

//服务器的接口
class IAbstactServer
{
public:
	virtual void Request()=0;
protected:
	IAbstactServer(){}
};

//真实的服务器
class FRealServer:public IAbstactServer
{
public:
	virtual void Request()override
	{
		cout<<"服务器启动！"<<endl;
	}
};

//个人理解 这层其实就相当于访问服务器时的一个网关
//在访问服务器的时候又套了一层,不至于说是直接找到服务器,造成一些不必要的麻烦
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
			cout<<"请求成功"<<endl;
			cout<<"代理服务器正在启动"<<endl;
			InstanceServer->Request();
			cout<<"服务器请求完成"<<endl;
		}else
		{
			cout << "服务器请求失败" << endl;
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
