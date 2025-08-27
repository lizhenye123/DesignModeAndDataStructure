#ifndef FACTORY_H
#define FACTORY_H
#include <string>
#include <map>

typedef void*(*Construct)();

class FObjectFactory
{
public:
	static void RegisterClass(std::string ClassName,Construct construct)
	{
		Constructs()[ClassName] = construct;
	}

	static void *CreateObject(const std::string&ClassName)
	{
		Construct construct=nullptr;
		if (Constructs().find(ClassName)!= Constructs().end())
		{
			construct= Constructs().find(ClassName)->second;
		}

		if(construct==nullptr) return nullptr;

		//吧函数解出来 调用
		return (*construct)();
	}
	
private:
	inline static std::map<std::string, Construct>&Constructs()
	{
		static std::map<std::string, Construct> constructs;
		return constructs;
	}
};

#define REG_CLASS(Class_Name)\
class Class_Name##Helper{\
public:\
	Class_Name##Helper(){\
		FObjectFactory::RegisterClass(#Class_Name,Class_Name##Helper::CreateObject);\
	}\
	static void* CreateObject(){\
		return new Class_Name;\
	}\
};\
Class_Name##Helper Class_Name##helper;

#endif // !FACTORY_H
