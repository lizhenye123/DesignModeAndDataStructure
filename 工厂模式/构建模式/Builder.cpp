#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*
* ��ʾ����ʵ��Ŀ����һ�������˵�������
* �����˵����ݣ�
* ������|�˶�����|����ID|���ѽ��|������
* �ֳ�����,����Ϊ,������������ڲ�ͬ�������п��ܲ�һ��
*/

/*
* ����Ҫ�ṹ,��һ��������,�Լ��ͻ���Ҫʹ�õĺϳɼӹ���
* �Ե���.txt��.xml�ļ���ʽΪ��
* txt|xml �����ڲ�ʵ�ְ�����ת���ɶ�Ӧ��ʽ�Ĳ���
* ����һ���ⲿ�ĺϳ���,��������������������,
* �������̫��,���˸о�û��Ҫ��ô��,��̫����,
*/

//������д����,�����ַ���
template<class T>
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
//�൱��һ����ʽ������
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


//���˵�������txt
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

//������Xml
//�൱��һ����ʽ������
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

//������൱��һ��������
//����������ݸ��������ɶ�Ӧ�ĸ�ʽ��
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
	FExportHeaderModel* pEhm = new FExportHeaderModel("�Ͼ�1֧��", "6��1��");
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