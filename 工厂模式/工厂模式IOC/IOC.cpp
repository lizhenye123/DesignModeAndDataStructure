#include <string>
#include <map>
#include <memory>
#include <functional>
#include <iostream>
using namespace std;

//IOC的容器
template<class T>
class IocContainer
{
public:
	IocContainer(void){}
	~IocContainer(){}

	//注册需要创建对象的构造函数，通过一个唯一的标识，以便于以后查找
	template<class Drived>
	void RegisterType(string StrKey)
	{
		std::function<T* ()>function = []() {return new Drived(); };
		RegisterType(StrKey,function);
	}

	//根据唯一标识符，创建出对应的对象
	T* Resolve(string StrKey)
	{
		if (M_CreateMap.find(StrKey) == M_CreateMap.end())
		{
			return nullptr;
		}
		std::function<T* ()>function = M_CreateMap[StrKey];
		return function();
	}

	//根据标识符返回一个智能指针
	std::shared_ptr<T> ResolveShared(string StrKey)
	{
		T* Ptr = Resolve(StrKey);
		return std::shared_ptr<T>(Ptr);
	}

private:
	
	//吧创建的Lambda注册到Map里，方便根据名字直接创建
	void RegisterType(string StrKey,std::function<T*()> Creater)
	{
		if (M_CreateMap.find(StrKey)!=M_CreateMap.end())
		{
			throw std::invalid_argument("已经存在这个键");
		}
		M_CreateMap.emplace(StrKey,Creater);
	}

	map<string,std::function<T*()>> M_CreateMap;
};

//车类的虚类
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
		cout<<"现在是 Bus::Test"<<endl;
	}
};

class FTrack :public ICar
{
public:
	FTrack() {}
	virtual void Test()override
	{
		cout << "现在是 Track::Test" << endl;
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