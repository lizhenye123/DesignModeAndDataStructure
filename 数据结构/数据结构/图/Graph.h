#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX_NUMBER 100

using namespace std;

//��ڵ����ӵıߵĶ���
struct FEdgeNode
{
	//���ӵĶ���
	int Adjvex;

	//Ȩ��
	int Weight;

	//��һ����
	FEdgeNode*Next;
};

//����
struct FVertexNode
{
	//���������
	int Value;
	//ָ�����ӵĵ�һ����,���������һ��,�ǵ�ǰ�ڵ���Ե����������ı�
	FEdgeNode*First;
};

//ͼ
struct FGraph
{
	FGraph(int InVertexNumber);
	//���ͼ�е����нڵ�
	FVertexNode*AdjList;

	//��������
	int VertexNumber;

	//�ߵ�����
	int EdgeNumber;

	//��ӱ�
	void AddEdge(int InStart,int InTarget,int InWeight);

	//����������������DFS
	bool DepthFirstSearch(int InStart, int InTarget, vector<int>& OutPath);

	//�����������,���BFS
	bool BreadthFirstSearch(int InStart, int InTarget, vector<int>& OutPath);

	void PrintGraph();

private:
	bool bVisited[MAX_NUMBER]={false};

	//���·��
	vector<int>ShortPith;
	//��ǰ����СȨ��
	int MinWeight;
};

