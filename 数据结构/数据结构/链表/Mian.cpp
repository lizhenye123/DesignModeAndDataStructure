#include "List.h"

int main()
{

	FList*List = new FList();

	for (int i=0;i<5;i++)
	{
		FListNode*TempNode = new FListNode;
		TempNode->Value = i;
		List->BrackInsert(TempNode);
	}

	FListNode* InsertNode = new FListNode;
	InsertNode->Value = 10;
	FListNode* InsertNode1 = new FListNode;
	InsertNode1->Value = 11;
	InsertNode->NextNode = InsertNode1;

	List->InsertByIndex(InsertNode,6);

	//List->ListPrint();

	int OutValue;
	List->GetValueByIndex(6, OutValue);

	FListNode* TempNode= List->GetListNodeByValue(10);
	if (TempNode)
	{
		cout<<"TempNode value = "<< TempNode->Value<<endl;
	}

	List->DeleteNodeByIndex(7);
	List->DeleteNodeByNode(TempNode);
	List->DeleteNodeByValue(11);

	//�ں�����������ɾ����,�����⻹���˵�ַ,���¿��Է��ʵ�Ұ��ַ,�ں����ﲻ���ͷ�,
	List->DestoryList();
	delete List;
	List=nullptr;

	if (List)
	{
		List->ListPrint();
	}else
	{
		cout<<"List�Ѿ�����"<<endl;
	}
	system("pause");
	return 0;
}