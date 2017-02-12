# include <bits/stdc++.h>
using namespace std;

# define max_val 1e6
# define SIZE 100
# define ll long long int

int graphs[SIZE][SIZE];
int dist[SIZE][SIZE];

int nodes,edges;

void floyd_warshall()
{
	for(int i=1;i<=nodes;++i)
	{
		for(int j=1;j<=nodes;++j)
		{
			dist[i][j]=graphs[i][j];
		}
	}

	for(int k=1;k<=nodes;++k)
	{
		for(int i=1;i<=nodes;++i)
		{
			for(int j=1;j<=nodes;++j)
			{
				if((dist[i][k] + dist[k][j]) < dist[i][j])
				{
					dist[i][j]=dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main()
{
	cin>>edges>>nodes;
	for(int i=1;i<nodes;++i)
	{
		for(int j=1;j<nodes;++j)
		{
			if(i==j)
			{
				graphs[i][j]=0;
			}
			else
			{
				graphs[i][j]=max_val;
			}
		}
	}

	//initialize graphs

	floyd_warshall();	
}