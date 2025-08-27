#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
* 组合模式：他是一种面向对象的树状结构,他是树(不是二叉树),
* 也有子节点和叶子节点 叶子节点不能拥有子节点
* 在游戏开发的经历中,笔者并没有使用过此模式,也没有见过相关的这种模式,也许是境界不到没有发现
* 个人建议,如果是游戏开发,这个模式看不看其实都行
*/

/*
* 此示例以一个电脑中的文件夹和文件为示例
* 磁盘就是根,子节点就是文件夹,叶子节点就是文件
*/

//统一的一个接口
class IFile
{
public:
	virtual void Displaye()=0;
	virtual bool Add(IFile*InFile)=0;
	virtual bool Remove(IFile*InFile)=0;
	virtual list<IFile*>*GetChild()=0;
};

//文件
class FFile:public IFile
{
public:
	FFile(string InName)
	{
		Name = InName;
	}
	virtual void Displaye() override
	{
		cout<<Name<<endl;
	}

	//文件没有子节点没发加
	virtual bool Add(IFile* InFile)override
	{
		return false;
	}

	//自然他也没法删了
	virtual bool Remove(IFile* InFile)override
	{
		return false;
	}

	//没有子节点返回空
	virtual list<IFile*>* GetChild()override
	{
		return nullptr;
	}
private:
	string Name;
};

class FFolder :public IFile
{
public:
	FFolder(string InName)
	{
		Name = InName;
		ListFiles = new list<IFile *>;
	}
	virtual void Displaye() override
	{
		cout << Name << endl;
	}

	virtual bool Add(IFile* InFile)override
	{
		ListFiles->push_back(InFile);
		return true;
	}

	virtual bool Remove(IFile* InFile)override
	{
		ListFiles->remove(InFile);
		return true;
	}

	virtual list<IFile*>* GetChild()override
	{
		return ListFiles;
	}

private:
	string Name;
	list<IFile*>* ListFiles;
};

void ShowTree(IFile*InRoot,int InLevel)
{
	if (InRoot == nullptr)
	{
		return;
	}

	int i =0;

	//这输出的是一个Tab键四个空格
	for (i=0;i<InLevel;i++)
	{
		cout<<"\t";
	}

	InRoot->Displaye();
	list<IFile*>* TempList = InRoot->GetChild();
	if (TempList != nullptr)
	{
		for (list<IFile*>::iterator Iter = TempList->begin();Iter!=TempList->end();Iter++)
		{
			//没子节点的
			if ((*Iter)->GetChild() == nullptr)
			{
				for (i = 0; i < InLevel; i++)
				{
					cout << "\t";
				}
				
				(*Iter)->Displaye();
			}else
			{
				ShowTree(*Iter, InLevel + 1);
			}
		}
	}
}

int main()
{
	FFolder*FolderRoot = new FFolder("C:");
	FFolder*Folder1 = new FFolder("Program Files");
	FFolder* Folder2 = new FFolder("Adobe");

	FFile*File = new FFile("A.txt");
	FFile*File1 = new FFile("B.txt");

	FolderRoot->Add(Folder1);
	Folder1->Add(Folder2);
	Folder1->Add(File);
	Folder2->Add(File1);

	list<IFile*>* TempList = FolderRoot->GetChild();
	ShowTree(FolderRoot,0);

	system("pause");
	return 0;
}