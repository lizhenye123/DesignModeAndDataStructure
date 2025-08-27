#include "BinarySearchTree.h"

int main()
{
	int TestArr[] = {19,11,25,7,17,21,61,5,26,99};
	FBinarySearchTree  *Tree= new FBinarySearchTree(19);

	for (int i = 1; i<10;i++)
	{
		FBinarySearchTreeNode* Node = new FBinarySearchTreeNode(TestArr[i]);
		Tree->InsertTreeNode(Node);
	}
	Tree->DeleteNode(7);
	Tree->PrintValue();
	system("pause");
	return 0;
}