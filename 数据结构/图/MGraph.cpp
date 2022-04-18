//============================================================================  
// Name        : MGraph.cpp
// Author      : Yuhang_Shang  
// Date        : 2021.11.20
// Copyright   : all rights reserved  
// Github      : www.github.com/tlxxsyh
// Website     : www.shangyuhang.icu
// Description : 1.通过邻接矩阵方式建立无向网图
//               2.DFS
//				 3.BFS
//============================================================================

#include <iostream>
#include <algorithm>
#include <cstdbool>
#include <queue>

using namespace std;

#define MAXVEX 100      //最大顶点数
typedef char VertexType; //顶点类型
typedef int EdgeType;	//权值类型


//访问标志的数组,0为未访问
bool visited[MAXVEX];

//邻接矩阵结构
typedef struct
{
	VertexType vexs[MAXVEX];         //顶点表
	EdgeType arc[MAXVEX][MAXVEX];	 //邻接矩阵，可看作边表
	int numNodes, numEdges;			 //图中当前的顶点数和边数
}MGraph;

void CreateMGraph(MGraph* G);    //建立无向网图的邻接矩阵
void DFS(MGraph G, int i);       //邻接矩阵的深度优先递归
void BFS(MGraph G, int i);       //邻接矩阵的广度优先遍历

int main()
{
	MGraph map;
	MGraph* p = &map;
	CreateMGraph(p);
	cout << "深度优先遍历：" << endl;
	DFS(map,0);
	for (int i = 0; i < map.numNodes; i++)    //初始化访问数组
		visited[i] = 0;
	cout << endl;
	cout << "广度优先遍历：" << endl;
	BFS(map,0);
	return 0;
}

//建立无向网图的邻接矩阵表示
void CreateMGraph(MGraph* G)
{
	int i, j, k, w;
	cout << "输入顶点数和边数：" << endl;
	//输入顶点数和边数
	cin >> G->numNodes >> G->numEdges;
	cout << "输入各个顶点的名称：";
	//读入顶点信息,建立顶点表
	for (i = 0; i < G->numNodes; i++) 
		cin >> G->vexs[i];
	//邻接矩阵初始化
	for (i = 0; i < G->numNodes; i++)
		for (j = 0; j < G->numNodes; j++)
			G->arc[i][j] = 0;
	//读入numEdges条边，建立邻接矩阵
	for (k = 0; k < G->numEdges; k++) 
	{
		cout << "输入边(vi,vj)上的下标i，下标j和权w：" << endl;
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		//无向图，矩阵对称
		G->arc[j][i] = G->arc[i][j];
	}
	cout << "无向网图构造完成" << endl;
}

//邻接矩阵的深度优先递归
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = 1;
	cout << G.vexs[i];
	//从此点遍历所有方向，若方向可行则直接访问该点
	for (j = 0; j < G.numEdges; j++){
		//路径权值为1表示连通
		if (G.arc[i][j] == 1 && !visited[j]){
			//递归调用下一个点
			DFS(G, j);
		}
	}	
}


//邻接矩阵的广度优先遍历
void BFS(MGraph G, int i)
{
	//申请队列
	queue<int> r;
	//申请临时变量j
	int j;

	r.push(i);           //起点入队
	visited[i] = 1;	     //起点标记为已访问
	cout << G.vexs[i];   //输出起点
	while (!r.empty())
	{
		//遍历所有方向所有可行点，全部都访问
		for (j = 0; j < G.numNodes; j++)
		{
			//若是可以连通且未访问过
			if (G.arc[r.front()][j] == 1 && !visited[j])
			{
				r.push(j);
				visited[j] = 1;
				cout << G.vexs[j];
			}
		}
		r.pop();
	}
}


