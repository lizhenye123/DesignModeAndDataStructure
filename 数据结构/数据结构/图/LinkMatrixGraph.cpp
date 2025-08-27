#include "LinkMatrixGraph.h"
#include <queue>

FLinkMatrixGraph::FLinkMatrixGraph(int InNumVertices)
{
	VertexNumber = InNumVertices;
	for (int i =0;i< InNumVertices;i++)
	{
		//�����㸳����һ����ĸ��Ϊֵ,��Ҳ�����ڹ����ʱ����һ������Ϊֵ
		Vertex[i] = 'A'+i;

		for (int j =0;j< InNumVertices;j++)
		{
			//��ʼ�����Ӿ���,�ⶼ�Ǳ�
			Edge[i][j] = 0;
		}
	}
}

void FLinkMatrixGraph::AddEdge(int InStart, int InEnd)
{
	if (InStart>=0 && InStart<VertexNumber && InEnd>=0 && InEnd< VertexNumber)
	{
		//����ǵ���ľ�������һ���͹���
		Edge[InStart][InEnd] = 1;
		//˫���Ҫ������һ��
		Edge[InEnd][InStart] = 1;

		EdgeNumber++;
	}else
	{
		cout<<"��ǰ�����ֵ�����˾���Χ"<<endl;
	}
}

void FLinkMatrixGraph::PrintMatrix()
{
	for (int i =0;i<VertexNumber;i++)
	{
		for (int j =0;j<VertexNumber;j++)
		{
			cout<< Edge[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool FLinkMatrixGraph::DepthFirstSearch(int InStart, int InTarget, vector<char>& InPath)
{
	if (InStart < 0 && InStart >= VertexNumber && InTarget < 0 && InTarget >= VertexNumber)
	{
		cout<<"DFS ����������Χ"<<endl;
		return false;
	}
	//�ݹ�ĺ�������
	if (InStart == InTarget)
	{
		InPath.push_back(Vertex[InStart]);
		return true;
	}

	//��¼���ʹ��Ľڵ�,���ⲻ��¼ ������ѭ��
	DFSVisitArr[InStart]=true;

	for (int i =0;i<VertexNumber;i++)
	{
		if (Edge[InStart][i]!=0 && DFSVisitArr[i]==false)
		{
			if (DepthFirstSearch(i,InTarget, InPath))
			{
				InPath.push_back(Vertex[InStart]);
				return true;
			}
		}
	}

	return false;
}

bool FLinkMatrixGraph::BreadthFirstSearch(int InStart, int InTarget, vector<char>& InPath)
{
	//Ҫ�����Ķ���
	queue<int> VertexToSearchFor;
	//�����Ƿ񱻷��ʹ�
	bool TempBFSVisit[MAX_NUMBER]={false};
	//ÿ���ڵ���Ǹ��ڵ�����������,�ڼ�¼ÿһ���ڵ�ĸ��ڵ�
	int Parent[MAX_NUMBER]={-1};

	VertexToSearchFor.push(InStart);
	TempBFSVisit[InStart] = true;

	//���㲻Ϊ��
	while (!VertexToSearchFor.empty())
	{
		int CurrentVertex = VertexToSearchFor.front();
		VertexToSearchFor.pop();

		//�ҵ���
		if (CurrentVertex == InTarget)
		{
			// ����·�����洢�� InPath ��
			int TempVertex = InTarget;
			while (TempVertex != -1)
			{
				InPath.push_back(Vertex[TempVertex]);
				TempVertex = Parent[TempVertex];
			}
			//��ת
			std::reverse(InPath.begin(), InPath.end());

			return true;
		}

		//Ѱ��·��
		for (int i =0;i<VertexNumber;i++)
		{
			if(Edge[CurrentVertex][i]!=0 && !TempBFSVisit[i])
			{
				VertexToSearchFor.push(i);
				TempBFSVisit[i]=true;
				Parent[i] = CurrentVertex;
			}
		}
	}

	return false;
}

void FLinkMatrixGraph::ClearVisitArr()
{
	for (int i =0;i<MAX_NUMBER;i++)
	{
		DFSVisitArr[i]=false;
	}
}
