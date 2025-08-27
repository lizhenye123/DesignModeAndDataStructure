#include <iostream>
#include "Factory.h"
class IAPI
{
public:
	virtual	void Test(std::string strName)=0;
protected:
	IAPI(){};
};

class FCar : public IAPI
{
public:
	FCar(){}
	virtual	void Test(std::string strName)
	{
		std::cout<<strName<<"这个是汽车的运输路线"<<std::endl;
	}
};
REG_CLASS(FCar)

class FShip :public IAPI
{
public:
	FShip(){}
	virtual	void Test(std::string strName)
	{
		std::cout << strName << "这个是轮船的运输路线" << std::endl;
	}
};
REG_CLASS(FShip)

class FAutoFactory
{
public:
	static IAPI* CreateShipInstance()
	{
		return static_cast<IAPI*>(FObjectFactory::CreateObject("FShip"));
	}

	static IAPI* CreateCarInstance()
	{
		return static_cast<IAPI*>(FObjectFactory::CreateObject("FCar"));
	}
};


int main()
{
	IAPI* Car = FAutoFactory::CreateCarInstance();
	Car->Test("Car    ");

	IAPI* Ship = FAutoFactory::CreateShipInstance();
	Ship->Test("Ship    ");

	system("pause");
	return 0;
}