#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
* 责任链模式：其实if elseif 也是一种,只不过把代码弄到一个类里去了,在体量不大的代码中更推荐使用if else 而不是责任链
* 如果这个if else 里的代码体量太大,就该抽出一个类来但个if里的具体逻辑了,便于维护
* 不过笔者目前没有遇到过这种应用场景,所以描述有可能不准确
*/

/*
* 以公司报销数目为例
*/

template<class T>
string ConvertToString(T InValue)
{
	stringstream SS;
	SS<<InValue;
	return SS.str();
}

//公司领导的抽象
class IManager
{
public:
	void SetSuccessor(IManager*InSuperiors)
	{
		Superiors = InSuperiors;
	}

	//报销费用
	virtual string HandleFeeRequest(double InFee)=0;

protected:
	IManager* Superiors=nullptr;
};

//项目经理
class FProjectManager:public IManager
{
public:
	virtual string HandleFeeRequest(double InFee)override
	{
		string StrTemp = "";
		if (InFee<1000)
		{
			StrTemp = "项目经理同意"+ConvertToString(InFee)+"费用";
			return StrTemp;
		}else
		{
			if (Superiors)
			{
				return Superiors->HandleFeeRequest(InFee);
			}
		}
		return StrTemp;
	}
};

//部门经理
class FDepartmentManager :public IManager
{
public:
	virtual string HandleFeeRequest(double InFee)override
	{
		string StrTemp = "";
		if (InFee>=1000&& InFee < 5000)
		{
			StrTemp = "部门经理同意" + ConvertToString(InFee) + "费用";
			return StrTemp;
		}
		else
		{
			if (Superiors)
			{
				return Superiors->HandleFeeRequest(InFee);
			}
		}
		return StrTemp;
	}
};

//老板
class FBossManager :public IManager
{
public:
	virtual string HandleFeeRequest(double InFee)override
	{
		string StrTemp = "";
		if (InFee>=5000)
		{
			StrTemp = "老板同意" + ConvertToString(InFee) + "费用";
			return StrTemp;
		}
		return StrTemp;
	}
};

int main(void) {
	
	IManager* ProjectManager = new FProjectManager();
	IManager* DepartmentManager = new FDepartmentManager();
	IManager* Boss = new FBossManager();

	ProjectManager->SetSuccessor(DepartmentManager);
	DepartmentManager->SetSuccessor(Boss);
	/*
	* 看完这个,你肯定在想if else 顶天20几行就解决了,我写了100行,轻量级代码 if else可以搞
	* 如果一个if else 里塞进去很多,那么最好是单独抽出来写,可读性和维护性都会增加不少
	*/
	cout << ProjectManager->HandleFeeRequest(300) << endl;
	cout << ProjectManager->HandleFeeRequest(3000) << endl;
	cout << ProjectManager->HandleFeeRequest(30000) << endl;
	system("pause");
	return 0;
}