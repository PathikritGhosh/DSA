# include <bits/stdc++.h>
using namespace std;

vector<int> graphs[112345];
bool visited[112345];
int level[112345];

int edges,nodes;

void bfs(int root)
{
	queue<int> q;
	int tnode,ttnode;

	q.push(root);
	level[root]=1;

	while(!q.empty())
	{
		tnode=q.front();
		q.pop();
		visited[tnode]=true;

		for(int i=0;i<graphs[tnode].size();++i)
		{
			ttnode=graphs[tnode][i];
			if(visited[ttnode]==false)
			{
				q.push(ttnode);
				level[ttnode]=level[tnode]+1;
			}
		}
	}
}

int main()
{
	cin>>nodes;
	edges=nodes-1;
	int a,b;
	for(int i=0;i<edges;++i)
	{
		cin>>a>>b;
		graphs[a].push_back(b);
		graphs[b].push_back(a);
	}

	int root=1;
	bfs(root);

	int x,sum;
	cin>>x;
	sum=0;
	for(int i=1;i<=nodes;++i)
	{
		if(level[i]==x)
		{
			sum++;
		}
	}
	cout<<sum<<endl;
}
