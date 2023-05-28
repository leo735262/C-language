#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define NumVertices 7    //頂點數量
#define INT_MAX 10000000 //定義一個很大的正整數，用來代替無限大

//找出還沒確認最短距離的點
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if(distance[i] < min && found[i] == 0)
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

//distance[i] 代表從頂點 v 到頂點 i 的最短路徑，found[i]=0表示到 i 的最短路徑還沒被找到，如果被找到則值為 1，cost 是相臨矩陣
void shortestPath(int v, int cost[][NumVertices], int dist[], int n, int f[] )
{
	int i,u,w;

	//設定初始值
	for (i = 0; i < n; i++)
	{
		f[i] = 0;
		dist[i] = INT_MAX;
	}
//	found[v] = 1;

	dist[v]=0;

	for(i = 0; i < n-1; i++)
	{
		u = choose(dist,n,f);
		f[u]=1;
		for(w = 0; w < n; w++)
		{
			if (f[w]==0 && cost[u][w] > 0)
			{
				if (dist[u] + cost[u][w] < dist[w])
				{
					dist[w] = dist[u] + cost[u][w];
				}
			}
		}
	}

	for(w = 0; w < n; w++)
	{
		cout << "從頂點 " << v <<"到頂點 " << w << " 的最短距離為" << dist[w] << endl;
	}
//	for(w = 0; w < n; w++)
//	{
//		cout << found[w] << endl;
//	}

}

int main(void)
{
	int adjMatrix[NumVertices][NumVertices];
	int distance[NumVertices];
	int found[NumVertices];
	int source;

	cout << "請輸入出發頂點：";
	cin >> source; //input source

	//讀入相鄰矩陣
	ifstream input("Matrix.txt",ios::in);
	if(!input)
	{
		cerr << "Can not open file Matrix.txt." << endl;   //標準錯誤裝置(standsard error device)
		return 0;
	}
	else
	{
		for(int i=0; i<NumVertices;i++)
		{
			for(int j=0; j<NumVertices;j++)
			{
				input >> adjMatrix[i][j];
			}
		}
		shortestPath(source, adjMatrix, distance, 7, found);
	}

	system("PAUSE");
	return 0;

}

