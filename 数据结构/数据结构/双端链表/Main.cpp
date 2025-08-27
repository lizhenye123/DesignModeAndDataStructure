#include "DoubleList.h"
using namespace std;

int main()
{
	FDoubleList*List = new FDoubleList();

	FDoubleListNode*ListNode = new FDoubleListNode(10);
	FDoubleListNode* ListNode1 = new FDoubleListNode(11);

	for (int i =0;i<5;i++)
	{
		FDoubleListNode* TempListNode = new FDoubleListNode(i);
		List->BrackInsert(TempListNode);
	}

	ListNode->NextNode = ListNode1;
	ListNode1->LastNode = ListNode;
	List->InsertNodeByIndex(ListNode,3);

	FDoubleListNode* Node = List->GetNodeByIndex(3);
	Node = List->GetNodeByValue(1);

	//List->DeleteNodeByIndex(3);
	//List->DeleteNodeByNode(Node);
	//List->DeleteNodeByValue(10);

	List->DestoryList();

	List->ListPrint();
	system("pause");
	return 0;
}