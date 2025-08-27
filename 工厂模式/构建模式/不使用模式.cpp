#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*
* 本示例的实现目标是一个银行账单的数据
* 银行账单内容：
* 银行名|核对日期|交易ID|消费金额|操作人
* 分成三组,是因为,各个组的数据在不同的银行有可能一样
*/


//把数据写入流,返回字符串
/*template<class T>
string ConvertToString(T InValue)
{
	stringstream SS;
	SS<<InValue;
	return SS.str();
}

//账单的头,银行名 | 核对日期
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
	//这个账单的银行名
	string StrDepId;

	//账单的日期
	string StrExportData;
};

//账单的 交易ID | 消费金额
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
	//交易ID 
	string StrTransId;

	//消费金额
	double Quantity;
};

//账单的 交易人
class FExportFooterModel {
public:
	FExportFooterModel(string InStrExportUser)
	{
		StrExportUser = InStrExportUser;
	}

	inline string getExportUser() {return StrExportUser;}
private:
	//交易人姓名
	string StrExportUser;
};

//考虑到在一个对账周期,可能有多笔交易,使用Vector
//把账单导出成txt
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

//导出成Xml
class FExportToXmlHelper
{
public:
	void DoExport(FExportHeaderModel& EHM, vector<FExportDataModel*>& EDMCollection, FExportFooterModel& EFM)
	{
		string StrTemp = "";
		//头
		StrTemp.append("<?xml version='1.0' encoding='utf-8'>\n");
		StrTemp.append("<Receipt>\n");
		StrTemp.append("	<Header>\n");
		StrTemp.append("		<DepId>");
		StrTemp.append(EHM.GetDepId()+"</Depid>\n");
		StrTemp.append("		<ExportDate>"+EHM.GetExportData()+"</ExportDate>\n");
		StrTemp.append("	</Header>\n");

		//数据体
		StrTemp.append("	<Body>\n");
		for (vector<FExportDataModel*>::iterator Iter = EDMCollection.begin(); Iter!=EDMCollection.end(); Iter++)
		{
			StrTemp.append("		<ID>"+ (*Iter)->GetStrTransId() + "</ID>\n");
			StrTemp.append("		<Amount>" + ConvertToString((*Iter)->GetQuantity()) + "</Amount>\n");
		}
		StrTemp.append("	</Body>\n");

		//尾部
		StrTemp.append("	<Footer>\n");
		StrTemp.append("		<ExportUser>" + EFM.getExportUser() + "</ExportUser>\n");
		StrTemp.append("	</Footer>\n</Receipt>\n");
		cout<<StrTemp;
	}
};

int main()
{
	FExportHeaderModel* pEhm = new FExportHeaderModel("南京1支行", "6月1日");
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