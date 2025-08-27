#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX_NUMBER 100

using namespace std;

struct FLinkMatrixGraph
{
	FLinkMatrixGraph(int InNumVertices);
	//��������
	char Vertex[MAX_NUMBER];
	//�ߵ����Ӿ���
	int Edge[MAX_NUMBER][MAX_NUMBER];
	//���������ͱߵ�����
	int VertexNumber,EdgeNumber;

	//��ӱ�
	void AddEdge(int InStart,int InEnd);

	//��ӡ����
	void PrintMatrix();

	//����������������DFS
	//����ǵݹ�,����0��1��ʱ,�����ͨ,�����Ȼ1��0��,˵���˾���,�ҵ�һ���ܽ����,�ͽ�,�Ҳ����ڷ�����һ���㼶,��������
	bool DepthFirstSearch(int InStart,int InTarget,vector<char>& InPath);

	//�����������,���BFS
	//�����ѭ������Ƕ�׺ܶ�,��ÿ�������ܽ��Ķ���¼����,Ȼ����ȥ��,�������ҵ�һ���ܽ��ľ��Ƚ�ȥ
	bool BreadthFirstSearch(int InStart, int InTarget, vector<char>& InPath);

	//DFSѭ�������Ժ�ǵ�����
	void ClearVisitArr();
private:
	//DFS����ʱ���ʹ���Ԫ��
	bool DFSVisitArr[MAX_NUMBER]{false};

	
};


