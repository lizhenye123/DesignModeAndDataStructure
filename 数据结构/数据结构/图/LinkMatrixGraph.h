#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX_NUMBER 100

using namespace std;

struct FLinkMatrixGraph
{
	FLinkMatrixGraph(int InNumVertices);
	//顶点数组
	char Vertex[MAX_NUMBER];
	//边的链接矩阵
	int Edge[MAX_NUMBER][MAX_NUMBER];
	//顶点数量和边的数量
	int VertexNumber,EdgeNumber;

	//添加边
	void AddEdge(int InStart,int InEnd);

	//打印矩阵
	void PrintMatrix();

	//深度优先搜索，简称DFS
	//这个是递归,进入0行1列时,如果联通,他会居然1行0列,说白了就是,找到一个能进入的,就进,找不到在返回上一个层级,继续遍历
	bool DepthFirstSearch(int InStart,int InTarget,vector<char>& InPath);

	//广度优先搜索,简称BFS
	//这个的循环不会嵌套很多,他每行所有能进的都记录下来,然后在去找,而不是找到一个能进的就先进去
	bool BreadthFirstSearch(int InStart, int InTarget, vector<char>& InPath);

	//DFS循环结束以后记得清理
	void ClearVisitArr();
private:
	//DFS遍历时访问过的元素
	bool DFSVisitArr[MAX_NUMBER]{false};

	
};


