#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
* ��Ԫģʽ����Ҫ����newһ���ڴ�,Ȼ������ڴ���ͨ�õ�,�е�����,�ڵײ����û���ͦ���
* ��ͼ����Ⱦ��ʱ��,����һ����,GPU��һ����,����һ����newһ��,һ��ģ�͵������ɲ���,Ū��ɭ��ֱ��ը��
* ������Ⱦ��ʱ��,��ֻNew��һ������ģ��,Ȼ�󴴽���һ����������,�ڶ��λ����Ⱦͬһ����,ֻ������Щ���Ĵ�С��ɫ��һ��
* ��UE��ˢ��,����ʹ��MassAI��ʱ��,��ʵ��������ģʽ,Ҫ��ȻCPU��AI,GPU����,��֧�Ų�����ô�����������
*/

/*
* ��ʾ�� ������Ϸ��ͼ�л���һЩ��Ϊ����
*/

//����λ��
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

//����ģ��
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

//Ҫ�ڴ�����ʵ��������
class FTree
{
public:
	FTree(){}
	FTreeModel*Model;
	int Scale=1;
	string Color; 
	FVector2D Position;
};

//��ͼ
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

		cout<<"��λ��X:"<<Tree->Position.X<<"Y:"<< Tree->Position.Y<<"������һ��"<< Tree->Model->Mesh<<"��ɫ�ǣ�"<< Tree->Color<<"��С�ǣ�"<< Tree->Scale<<endl;
		return Tree;
	}

	void RegisterTreeModel(string TreeName, FTreeModel* Model)
	{
		if (TreeArray.find(TreeName) != TreeArray.end())
		{
			cout<<"ע�����"<<endl;
			return;
		}

		TreeArray.emplace(TreeName,Model);
	}
private:
	map<string, FTreeModel*>TreeArray;
};

int main()
{
	FTreeModel* Willow =new FTreeModel("����","��������ͼ");
	UMap*Map = new UMap();
	Map->RegisterTreeModel("����",Willow);

	Map->DrawTree("����",FVector2D(0,2),"��ɫ",1);
	Map->DrawTree("����", FVector2D(0, 5), "��ɫ", 1);
	
	system("pause");
	return 0;
}