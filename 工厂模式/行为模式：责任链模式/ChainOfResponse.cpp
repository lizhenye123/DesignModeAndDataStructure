#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
* ������ģʽ����ʵif elseif Ҳ��һ��,ֻ�����Ѵ���Ū��һ������ȥ��,����������Ĵ����и��Ƽ�ʹ��if else ������������
* ������if else ��Ĵ�������̫��,�͸ó��һ����������if��ľ����߼���,����ά��
* ��������Ŀǰû������������Ӧ�ó���,���������п��ܲ�׼ȷ
*/

/*
* �Թ�˾������ĿΪ��
*/

template<class T>
string ConvertToString(T InValue)
{
	stringstream SS;
	SS<<InValue;
	return SS.str();
}

//��˾�쵼�ĳ���
class IManager
{
public:
	void SetSuccessor(IManager*InSuperiors)
	{
		Superiors = InSuperiors;
	}

	//��������
	virtual string HandleFeeRequest(double InFee)=0;

protected:
	IManager* Superiors=nullptr;
};

//��Ŀ����
class FProjectManager:public IManager
{
public:
	virtual string HandleFeeRequest(double InFee)override
	{
		string StrTemp = "";
		if (InFee<1000)
		{
			StrTemp = "��Ŀ����ͬ��"+ConvertToString(InFee)+"����";
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

//���ž���
class FDepartmentManager :public IManager
{
public:
	virtual string HandleFeeRequest(double InFee)override
	{
		string StrTemp = "";
		if (InFee>=1000&& InFee < 5000)
		{
			StrTemp = "���ž���ͬ��" + ConvertToString(InFee) + "����";
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

//�ϰ�
class FBossManager :public IManager
{
public:
	virtual string HandleFeeRequest(double InFee)override
	{
		string StrTemp = "";
		if (InFee>=5000)
		{
			StrTemp = "�ϰ�ͬ��" + ConvertToString(InFee) + "����";
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
	* �������,��϶�����if else ����20���оͽ����,��д��100��,���������� if else���Ը�
	* ���һ��if else ������ȥ�ܶ�,��ô����ǵ��������д,�ɶ��Ժ�ά���Զ������Ӳ���
	*/
	cout << ProjectManager->HandleFeeRequest(300) << endl;
	cout << ProjectManager->HandleFeeRequest(3000) << endl;
	cout << ProjectManager->HandleFeeRequest(30000) << endl;
	system("pause");
	return 0;
}