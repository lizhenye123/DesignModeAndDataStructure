#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX_NUMBER 100

using namespace std;

//与节点链接的边的定义
struct FEdgeNode
{
	//链接的顶点
	int Adjvex;

	//权重
	int Weight;

	//下一条边
	FEdgeNode*Next;
};

//顶点
struct FVertexNode
{
	//顶点的数据
	int Value;
	//指向链接的第一条边,这里面的下一个,是当前节点可以到达的其他点的边
	FEdgeNode*First;
};

//图
struct FGraph
{
	FGraph(int InVertexNumber);
	//这个图中的所有节点
	FVertexNode*AdjList;

	//顶点数量
	int VertexNumber;

	//边的数量
	int EdgeNumber;

	//添加边
	void AddEdge(int InStart,int InTarget,int InWeight);

	//深度优先搜索，简称DFS
	bool DepthFirstSearch(int InStart, int InTarget, vector<int>& OutPath);

	//广度优先搜索,简称BFS
	bool BreadthFirstSearch(int InStart, int InTarget, vector<int>& OutPath);

	void PrintGraph();

private:
	bool bVisited[MAX_NUMBER]={false};

	//最短路径
	vector<int>ShortPith;
	//当前的最小权重
	int MinWeight;
};

