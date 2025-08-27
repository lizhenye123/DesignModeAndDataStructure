#include "AlgorithmLibrary.h"


int main()
{
	int Arr[10]={5,7,11,15,19,21,25,26,61,99};
	int ReturnValue= FAlgorithmLibrary::BinarySearch(Arr,0,9,80);

	/*ABCE
	* SFCS
	* ADEE
	*/
	const char*Matrix="ABCESFCSADEE";
	const char*StrValue = "SEE";

	bool bReturnValue = FAlgorithmLibrary::HasPath(Matrix,3,4,StrValue);
	//cout<<ReturnValue<<endl;

	vector<FItem>items = { {10, 60}, {20, 100}, {30, 120} };
	int Capacity=50;
	vector<FItem> selectedItems;
	FAlgorithmLibrary::GreedyAlgorithm(items, Capacity, selectedItems);

	system("pause");
	return 0;
}