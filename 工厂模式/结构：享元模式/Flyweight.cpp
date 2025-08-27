#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* 享元模式：主要是在new一块内存,然后这块内存是通用的,有点像单例,在底层运用还是挺多的
* 在图形渲染的时候,比如一个树,GPU渲一堆树,不是一个树new一个,一个模型的面数可不少,弄个森林直接炸了
* 他在渲染的时候,是只New了一个树的模型,然后创建了一堆树的数据,在多个位置渲染同一个树,只不过这些树的大小颜色不一样
* 在UE中刷树,或者使用MassAI的时候,其实就是这种模式,要不然CPU算AI,GPU算树,是支撑不了那么大的数据量的
*/

/*
* 本示例 以在游戏地图中绘制一些树为列子
*/

//树的位置
struct FVector2D
{
	FVector2D(){}
	FVector2D(int InX,int InY)
	{
		X=InX;
		Y=InY;
	}

	bool operator==(const FVector2D &InOther)
	{
		return X == InOther.X && InOther.Y == Y;
	}

	int X;
	int Y;
};

//树的模型
class FTreeModel
{
public:	
	FTreeModel(string InMesh, string InTexture)
	{
		Mesh = InMesh;
		InTexture = InTexture;
	}
	string Mesh;
	string Texture;
};

//要在创建中实例化的树
class FTree
{
public:
	FTree(){}
	FTreeModel*Model;
	int Scale=1;
	string Color; 
	FVector2D Position;
};

//地图
class UMap
{
public:
	vector<FVector2D> Postion;

	FTree* DrawTree(string TreeName,const FVector2D& Position,const string& Color,const int &Scale)
	{
		FTree*Tree =new FTree();
		Tree->Model = TreeArray.find(TreeName)->second;
		Tree->Position= Position;
		Tree->Color = Color;
		Tree->Scale = Scale;

		cout<<"在位置X:"<<Tree->Position.X<<"Y:"<< Tree->Position.Y<<"绘制了一颗"<< Tree->Model->Mesh<<"颜色是："<< Tree->Color<<"大小是："<< Tree->Scale<<endl;
		return Tree;
	}

	void RegisterTreeModel(string TreeName, FTreeModel* Model)
	{
		if (TreeArray.find(TreeName) != TreeArray.end())
		{
			cout<<"注册过了"<<endl;
			return;
		}

		TreeArray.emplace(TreeName,Model);
	}
private:
	map<string, FTreeModel*>TreeArray;
};

int main()
{
	FTreeModel* Willow =new FTreeModel("柳树","柳树的贴图");
	UMap*Map = new UMap();
	Map->RegisterTreeModel("柳树",Willow);

	Map->DrawTree("柳树",FVector2D(0,2),"白色",1);
	Map->DrawTree("柳树", FVector2D(0, 5), "白色", 1);
	
	system("pause");
	return 0;
}