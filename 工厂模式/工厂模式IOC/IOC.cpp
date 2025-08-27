#include <string>
#include <map>
#include <memory>
#include <functional>
#include <iostream>
using namespace std;

//IOC������
template<class T>
class IocContainer
{
public:
	IocContainer(void){}
	~IocContainer(){}

	//ע����Ҫ��������Ĺ��캯����ͨ��һ��Ψһ�ı�ʶ���Ա����Ժ����
	template<class Drived>
	void RegisterType(string StrKey)
	{
		std::function<T* ()>function = []() {return new Drived(); };
		RegisterType(StrKey,function);
	}

	//����Ψһ��ʶ������������Ӧ�Ķ���
	T* Resolve(string StrKey)
	{
		if (M_CreateMap.find(StrKey) == M_CreateMap.end())
		{
			return nullptr;
		}
		std::function<T* ()>function = M_CreateMap[StrKey];
		return function();
	}

	//���ݱ�ʶ������һ������ָ��
	std::shared_ptr<T> ResolveShared(string StrKey)
	{
		T* Ptr = Resolve(StrKey);
		return std::shared_ptr<T>(Ptr);
	}

private:
	
	//�ɴ�����Lambdaע�ᵽMap������������ֱ�Ӵ���
	void RegisterType(string StrKey,std::function<T*()> Creater)
	{
		if (M_CreateMap.find(StrKey)!=M_CreateMap.end())
		{
			throw std::invalid_argument("�Ѿ����������");
		}
		M_CreateMap.emplace(StrKey,Creater);
	}

	map<string,std::function<T*()>> M_CreateMap;
};

//���������
class ICar
{
public:
	virtual ~ICar(){}
	virtual void Test()=0;
};

class FBus:public ICar
{
public:
	FBus(){}
	virtual void Test()override
	{
		cout<<"������ Bus::Test"<<endl;
	}
};

class FTrack :public ICar
{
public:
	FTrack() {}
	virtual void Test()override
	{
		cout << "������ Track::Test" << endl;
	}
};

int main()
{
	IocContainer<ICar> CarIOC;
	CarIOC.RegisterType<FBus>("Bus");
	CarIOC.RegisterType<FTrack>("Track");

	std::shared_ptr<ICar> Bus = CarIOC.ResolveShared("Bus");
	Bus->Test();
	ICar* Track = CarIOC.Resolve("Track");
	Track->Test();

	system("pause");
	return 0;
}