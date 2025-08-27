#include "Graph.h"
#include <queue>

FGraph::FGraph(int InVertexNumber)
{
	AdjList = new FVertexNode[InVertexNumber];
	VertexNumber = InVertexNumber;
	for (int i =0;i< InVertexNumber;i++)
	{
		AdjList[i].Value = i;
		AdjList[i].First = nullptr;
	}

	EdgeNumber = 0;
}

void FGraph::AddEdge(int InStart, int InTarget, int InWeight)
{
	if (InStart<0 ||InStart>=VertexNumber|| InTarget<0|| InTarget>=VertexNumber)
	{
		cout<<"���ʧ��,����Index�ķ�Χ"<<endl;
		return;
	}

	FEdgeNode*EdgeNode = new FEdgeNode();
	EdgeNode->Weight = InWeight;
	EdgeNode->Adjvex = InStart;
	//���ǰ�������������,ǰ�巨
	EdgeNode->Next = AdjList[InStart].First;
	AdjList[InStart].First = EdgeNode;

	EdgeNumber++;
}

bool FGraph::DepthFirstSearch(int InStart, int InTarget, vector<int>& OutPath)
{
	bVisited[InStart] = true;
	OutPath.push_back(InStart);

	if (InStart == InTarget)
	{
		//�ҵ�Ŀ���
		return true;
	}

	FEdgeNode*EdgeNode = AdjList[InStart].First;
	while (EdgeNode!=nullptr)
	{
		if (!bVisited[EdgeNode->Adjvex])
		{
			if (DepthFirstSearch(EdgeNode->Adjvex,InTarget,OutPath))
			{
				//����·�����ҵ�Ŀ�궥��,���سɹ�
				return true;
			}
		}
		EdgeNode = EdgeNode->Next;
	}

	OutPath.pop_back();
	return false;
}



bool FGraph::BreadthFirstSearch(int InStart, int InTarget, vector<int>& OutPath)
{
	//Ҫ�����Ķ���
	queue<int> VertexToSearchFor;
	//���ʹ��Ľڵ�
	bool TempVisited[MAX_NUMBER] ={false};
	//�ڵ�ĸ��ڵ�,�ڵ���Ǹ��ڵ������
	int Parent[MAX_NUMBER]={-1};

	VertexToSearchFor.push(InStart);
	TempVisited[InStart] = true;

	while (!VertexToSearchFor.empty())
	{
		int CurrentIndex = VertexToSearchFor.front();
		VertexToSearchFor.pop();

		if (CurrentIndex == InTarget)
		{	
			int TempVertex = InTarget;
			while (TempVertex!=-1)
			{
				OutPath.push_back(TempVertex);
				TempVertex = Parent[TempVertex];
			}
			reverse(OutPath.begin(), OutPath.end());
			return true;
		}

		FEdgeNode*EdgeNode = AdjList[CurrentIndex].First;
		while (EdgeNode!=nullptr)
		{
			if (!TempVisited[EdgeNode->Adjvex])
			{
				VertexToSearchFor.push(EdgeNode->Adjvex);
				TempVisited[EdgeNode->Adjvex] = true;
				Parent[EdgeNode->Adjvex] = CurrentIndex;
			}

			EdgeNode= EdgeNode->Next;
		}
	}

	return false;
}

void FGraph::PrintGraph()
{	
	for (int i =0;i<VertexNumber;i++)
	{	
		FEdgeNode*EdgeNode = AdjList[i].First;
		cout<<i<<"�Žڵ����ӣ�";
		while (EdgeNode!=nullptr)
		{
			cout<<"->"<< EdgeNode->Adjvex<<"Value="<< AdjList[i].Value;
			EdgeNode = EdgeNode->Next;
		}
		cout<<endl;
	}
}
