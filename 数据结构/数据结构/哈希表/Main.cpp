#include "FHashTable.h"

int main()
{
	FHashTable*HashTable=new FHashTable();

	for (int i=0;i<5;i++)
	{
		HashTable->InsertValue(i+10);
	}

	int Value = HashTable->GetNodeByValue(12);
	Value = HashTable->GetHashKey(12);

	HashTable->DeleteNode(12);
	HashTable->DestoryHash();
	
	HashTable->PrintHash();
	system("pause");
	return 0;
}