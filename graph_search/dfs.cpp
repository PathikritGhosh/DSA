# include <bits/stdc++.h>
using namespace std;

vector<int> graphs[112345];
bool visited[112345];

int nodes,edges;

void dfs(int current_node)
{
	visited[current_node]=true;
	for(int i=0;i<graphs[current_node].size();++i)
	{
		if(visited[graphs[current_node][i]] == false)
		{
			dfs(graphs[current_node][i]);
		}
	}
}

//only useful in a tree where edges are n-1 and nodes are n.
void dfs_parent(int current,int parent)
{
	int tnode;

	for(int i=0;i<graphs[current].size();++i)
	{
		tnode=graphs[current][i];
		if(tnode != parent)
		{
			dfs_parent(tnode,current);
		}
	}
}

void dfs_iter(int root)
{
	stack<int> s;
	s.push(root);

	int tnode,ttnode;

	while(!s.empty())
	{
		tnode=s.top();
		s.pop();
		visited[tnode]=true;

		for(int i=0;i<graphs[tnode].size();++i)
		{
			ttnode=graphs[tnode][i];
			if(visited[ttnode] == false)
			{
				s.push(ttnode);
			}
		}
	}
}

int main()
{
	int a,b;
	cin>>nodes>>edges;
	for(int i=0;i<edges;++i)
	{
		cin>>a>>b;
		graphs[a].push_back(b);
		graphs[b].push_back(a);
	}
}