#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*
* ��ʾ����ʵ��Ŀ����һ�������˵�������
* �����˵����ݣ�
* ������|�˶�����|����ID|���ѽ��|������
* �ֳ�����,����Ϊ,������������ڲ�ͬ�������п���һ��
*/


//������д����,�����ַ���
/*template<class T>
string ConvertToString(T InValue)
{
	stringstream SS;
	SS<<InValue;
	return SS.str();
}

//�˵���ͷ,������ | �˶�����
class FExportHeaderModel
{
public:	
	FExportHeaderModel(string InStrDepId,string InStrExportData)
	{
		StrDepId = InStrDepId;
		StrExportData = InStrExportData;
	}

	inline string GetDepId(){return StrDepId;}

	inline string GetExportData(){ return StrExportData;};

private:
	//����˵���������
	string StrDepId;

	//�˵�������
	string StrExportData;
};

//�˵��� ����ID | ���ѽ��
class FExportDataModel
{
public:
	FExportDataModel(string InStrTransId, double InQuantity)
	{
		StrTransId = InStrTransId;
		Quantity = InQuantity;
	}

public:
	inline string GetStrTransId() { return StrTransId; }

	inline double GetQuantity() { return Quantity; };

private:
	//����ID 
	string StrTransId;

	//���ѽ��
	double Quantity;
};

//�˵��� ������
class FExportFooterModel {
public:
	FExportFooterModel(string InStrExportUser)
	{
		StrExportUser = InStrExportUser;
	}

	inline string getExportUser() {return StrExportUser;}
private:
	//����������
	string StrExportUser;
};

//���ǵ���һ����������,�����ж�ʽ���,ʹ��Vector
//���˵�������txt
class FExportToTxtHelper
{
public:
	void DoExport(FExportHeaderModel&EHM,vector<FExportDataModel*>& EDMCollection,FExportFooterModel&EFM)
	{
		string StrTemp="";

		StrTemp += EHM.GetDepId()+","+EHM.GetExportData() + "\n";

		for (vector<FExportDataModel*>::iterator Iter = EDMCollection.begin(); Iter !=EDMCollection.end(); Iter++)
		{
			StrTemp+=(*Iter)->GetStrTransId() + ":" + ConvertToString((*Iter)->GetQuantity()) + "\n";
		}

		StrTemp+=EFM.getExportUser()+"\n";
		cout<<StrTemp;
	}
};

//������Xml
class FExportToXmlHelper
{
public:
	void DoExport(FExportHeaderModel& EHM, vector<FExportDataModel*>& EDMCollection, FExportFooterModel& EFM)
	{
		string StrTemp = "";
		//ͷ
		StrTemp.append("<?xml version='1.0' encoding='utf-8'>\n");
		StrTemp.append("<Receipt>\n");
		StrTemp.append("	<Header>\n");
		StrTemp.append("		<DepId>");
		StrTemp.append(EHM.GetDepId()+"</Depid>\n");
		StrTemp.append("		<ExportDate>"+EHM.GetExportData()+"</ExportDate>\n");
		StrTemp.append("	</Header>\n");

		//������
		StrTemp.append("	<Body>\n");
		for (vector<FExportDataModel*>::iterator Iter = EDMCollection.begin(); Iter!=EDMCollection.end(); Iter++)
		{
			StrTemp.append("		<ID>"+ (*Iter)->GetStrTransId() + "</ID>\n");
			StrTemp.append("		<Amount>" + ConvertToString((*Iter)->GetQuantity()) + "</Amount>\n");
		}
		StrTemp.append("	</Body>\n");

		//β��
		StrTemp.append("	<Footer>\n");
		StrTemp.append("		<ExportUser>" + EFM.getExportUser() + "</ExportUser>\n");
		StrTemp.append("	</Footer>\n</Receipt>\n");
		cout<<StrTemp;
	}
};

int main()
{
	FExportHeaderModel* pEhm = new FExportHeaderModel("�Ͼ�1֧��", "6��1��");
	FExportDataModel* pEdm = new FExportDataModel("1", 10000.00f);
	FExportDataModel* pEdm2 = new FExportDataModel("2", 20000.00f);

	vector<FExportDataModel*>MyVec;
	MyVec.push_back(pEdm);
	MyVec.push_back(pEdm2);
	FExportFooterModel*PEfm = new FExportFooterModel("lzy");

	//FExportToTxtHelper Helper;
	FExportToXmlHelper Helper;
	Helper.DoExport(*pEhm,MyVec,*PEfm);
}*/