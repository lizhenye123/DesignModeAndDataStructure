#include "LinkMatrixGraph.h"
#include <queue>

FLinkMatrixGraph::FLinkMatrixGraph(int InNumVertices)
{
	VertexNumber = InNumVertices;
	for (int i =0;i< InNumVertices;i++)
	{
		//给顶点赋予了一个字母作为值,你也可以在构造的时候传入一个数组为值
		Vertex[i] = 'A'+i;

		for (int j =0;j< InNumVertices;j++)
		{
			//初始化链接矩阵,这都是边
			Edge[i][j] = 0;
		}
	}
}

void FLinkMatrixGraph::AddEdge(int InStart, int InEnd)
{
	if (InStart>=0 && InStart<VertexNumber && InEnd>=0 && InEnd< VertexNumber)
	{
		//如果是单向的就设置这一个就够了
		Edge[InStart][InEnd] = 1;
		//双向的要在设置一个
		Edge[InEnd][InStart] = 1;

		EdgeNumber++;
	}else
	{
		cout<<"当前输入的值超出了矩阵范围"<<endl;
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
		cout<<"DFS 超出搜索范围"<<endl;
		return false;
	}
	//递归的核心在这
	if (InStart == InTarget)
	{
		InPath.push_back(Vertex[InStart]);
		return true;
	}

	//记录访问过的节点,在这不记录 就是死循环
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
	//要搜索的顶点
	queue<int> VertexToSearchFor;
	//顶点是否被访问过
	bool TempBFSVisit[MAX_NUMBER]={false};
	//每个节点从那个节点搜索过来的,在记录每一个节点的父节点
	int Parent[MAX_NUMBER]={-1};

	VertexToSearchFor.push(InStart);
	TempBFSVisit[InStart] = true;

	//顶点不为空
	while (!VertexToSearchFor.empty())
	{
		int CurrentVertex = VertexToSearchFor.front();
		VertexToSearchFor.pop();

		//找到了
		if (CurrentVertex == InTarget)
		{
			// 回溯路径并存储在 InPath 中
			int TempVertex = InTarget;
			while (TempVertex != -1)
			{
				InPath.push_back(Vertex[TempVertex]);
				TempVertex = Parent[TempVertex];
			}
			//反转
			std::reverse(InPath.begin(), InPath.end());

			return true;
		}

		//寻找路径
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
