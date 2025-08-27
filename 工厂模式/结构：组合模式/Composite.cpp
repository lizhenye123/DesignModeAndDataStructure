#include <iostream>
#include <list>
#include <string>
using namespace std;

/*
* ���ģʽ������һ������������״�ṹ,������(���Ƕ�����),
* Ҳ���ӽڵ��Ҷ�ӽڵ� Ҷ�ӽڵ㲻��ӵ���ӽڵ�
* ����Ϸ�����ľ�����,���߲�û��ʹ�ù���ģʽ,Ҳû�м�����ص�����ģʽ,Ҳ���Ǿ��粻��û�з���
* ���˽���,�������Ϸ����,���ģʽ��������ʵ����
*/

/*
* ��ʾ����һ�������е��ļ��к��ļ�Ϊʾ��
* ���̾��Ǹ�,�ӽڵ�����ļ���,Ҷ�ӽڵ�����ļ�
*/

//ͳһ��һ���ӿ�
class IFile
{
public:
	virtual void Displaye()=0;
	virtual bool Add(IFile*InFile)=0;
	virtual bool Remove(IFile*InFile)=0;
	virtual list<IFile*>*GetChild()=0;
};

//�ļ�
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

	//�ļ�û���ӽڵ�û����
	virtual bool Add(IFile* InFile)override
	{
		return false;
	}

	//��Ȼ��Ҳû��ɾ��
	virtual bool Remove(IFile* InFile)override
	{
		return false;
	}

	//û���ӽڵ㷵�ؿ�
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

	//���������һ��Tab���ĸ��ո�
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
			//û�ӽڵ��
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