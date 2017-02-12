# include <bits/stdc++.h>
using namespace std;

# define max_val 1e6
# define ll long long int

bool visited[112345];
int dist[112345];
vector<pair<int,int> > graphs[112345];	//node->(weight,adj_node)
pair<int,int> tpair;

int nodes,edges,root;

void djikstra()
{
	int tnode,tweight;
	for(int i=1;i<=nodes;++i)
	{
		dist[i]=max_val;
	}
	dist[root]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,root));
	while(!q.empty())
	{
		tpair=q.top();
		q.pop();
		tnode=tpair.second;
		tweight=tpair.first;
		int ttnode,ttdist;
		if(visited[tnode]==true)
		{
			continue;
		}
		visited[tnode]=true;
		for(int i=0;i<graphs[tnode].size();++i)
		{
			ttnode=graphs[tnode][i].second;
			ttdist=graphs[tnode][i].first;
			if((dist[tnode] + ttdist) < dist[ttnode])
			{
				dist[ttnode]=dist[tnode] + ttdist;
				q.push(make_pair(dist[ttnode],ttnode));
			}
		}
	}
}

int main()
{
	cin>>nodes>>edges;
	int a,b,c;
	for(int i=0;i<edges;++i)
	{
		cin>>a>>b>>c;
		graphs[a].push_back(make_pair(c,b));
		//graphs[b].push_back(make_pair(c,a));   //use only if graph is un-directed
	}
	root=1;
	djikstra();
	for(int i=2;i<=nodes;++i)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
}