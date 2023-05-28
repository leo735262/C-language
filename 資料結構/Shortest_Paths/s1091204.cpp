#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define NumVertices 7    //���I�ƶq
#define INT_MAX 10000000 //�w�q�@�ӫܤj������ơA�ΨӥN���L���j

//��X�٨S�T�{�̵u�Z�����I
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

//distance[i] �N��q���I v �쳻�I i ���̵u���|�Afound[i]=0��ܨ� i ���̵u���|�٨S�Q���A�p�G�Q���h�Ȭ� 1�Acost �O���{�x�}
void shortestPath(int v, int cost[][NumVertices], int dist[], int n, int f[] )
{
	int i,u,w;

	//�]�w��l��
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
		cout << "�q���I " << v <<"�쳻�I " << w << " ���̵u�Z����" << dist[w] << endl;
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

	cout << "�п�J�X�o���I�G";
	cin >> source; //input source

	//Ū�J�۾F�x�}
	ifstream input("Matrix.txt",ios::in);
	if(!input)
	{
		cerr << "Can not open file Matrix.txt." << endl;   //�зǿ��~�˸m(standsard error device)
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

