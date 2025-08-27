#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*
* 本示例的实现目标是一个银行账单的数据
* 银行账单内容：
* 银行名|核对日期|交易ID|消费金额|操作人
* 分成三组,是因为,各个组的数据在不同的银行有可能不一样
*/

/*
* 其主要结构,是一个构建类,以及客户端要使用的合成加工类
* 以导出.txt和.xml文件格式为列
* txt|xml 在其内部实现吧数据转换成对应格式的操作
* 在以一个外部的合成类,来吧里面的数据组合起来,
* 如果不是太多,个人感觉没必要怎么做,类太多了,
*/

//把数据写入流,返回字符串
template<class T>
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
//相当于一个格式生成器
class IBuilder
{
public:
	virtual void BuilderHeader(FExportHeaderModel&EHM)=0;
	virtual void BuilderBody(vector<FExportDataModel*>&EDMCollection)=0;
	virtual void BuilderFoot(FExportFooterModel&EFM)=0;
	virtual string GetResult()=0;
protected:
	IBuilder(){}
};


//把账单导出成txt
class FTxtBuilder:public IBuilder
{
public:
	virtual void BuilderHeader(FExportHeaderModel& EHM)override
	{
		StrResult.append(EHM.GetDepId()+","+EHM.GetExportData()+"\n");
	}

	virtual void BuilderBody(vector<FExportDataModel*>& EDMCollection)override
	{
		for (vector<FExportDataModel*>::iterator Iter = EDMCollection.begin(); Iter!=EDMCollection.end(); Iter++)
		{
			StrResult+= (*Iter)->GetStrTransId()+":"+ConvertToString((*Iter)->GetQuantity()) + "/n";
		}
		
	}

	virtual void BuilderFoot(FExportFooterModel& EFM)override
	{
		StrResult+= EFM.getExportUser()+"\n";
	}

	virtual string GetResult()override
	{
		return StrResult;
	}
private:
	string StrResult="";
};

//导出成Xml
//相当于一个格式生成器
class FXmlBuilder:public IBuilder
{
public:
	virtual void BuilderHeader(FExportHeaderModel& EHM)override
	{
		StrResult.append("<?xml version='1.0' encoding='utf-8'>\n");
		StrResult.append("<Receipt>\n");
		StrResult.append("	<Header>\n");
		StrResult.append("		<DepID>"+EHM.GetDepId()+"</DepID>\n");
		StrResult.append("		<ExportDate>" + EHM.GetExportData() + "</ExportDate>\n");
		StrResult.append("	</Header>\n");
	}

	virtual void BuilderBody(vector<FExportDataModel*>& EDMCollection)override
	{
		StrResult.append("	<Body>\n");
		for (vector<FExportDataModel*>::iterator Iter = EDMCollection.begin(); Iter!=EDMCollection.end();Iter++)
		{
			StrResult.append("		<ID>"+(*Iter)->GetStrTransId()+"</ID>\n");
			StrResult.append("		<Amount>"+ConvertToString((*Iter)->GetStrTransId())+"</Amount>\n");
		}
		StrResult.append("	</Body>\n");
	}


	virtual void BuilderFoot(FExportFooterModel& EFM)override
	{
		StrResult.append("	<Footer>\n");
		StrResult.append("		<ExportUser>" + EFM.getExportUser()+"</ExportUser>\n");
		StrResult.append("	</Footer>\n</Receipt>\n");
	}

	virtual string GetResult()override
	{
		return StrResult;
	}
private:
	string StrResult = "";
};

//这个类相当于一个解析器
//他吧这个数据给给解析成对应的格式的
class FDirector
{
public:	
	FDirector(IBuilder* InBuilder)
	{
		Builder=InBuilder;
	}

	void Construct(FExportHeaderModel& EHM, vector<FExportDataModel*>& EDMCollection, FExportFooterModel& EFM)
	{
		Builder->BuilderHeader(EHM);
		Builder->BuilderBody(EDMCollection);
		Builder->BuilderFoot(EFM);
	}

private:
	IBuilder *Builder;
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

	IBuilder*Builder = new FXmlBuilder();
	FDirector*Director = new FDirector(Builder);
	Director->Construct(*pEhm, MyVec, *PEfm);
	cout<<Builder->GetResult()<<endl;

	system("pause");
	return 0;
}