# include <bits/stdc++.h>
using namespace std;

# define ll long long int
# define max_val 1e6
bool visited[112345];
vector<pair	<int,int> > adj[112345];	//node->(weight,node)
pair<int,int> tpair;	//(weight,node)
pair<int,int> mst[112345];

int nodes,edges,root;

ll prim()
{
	for(int i=1;i<=nodes;++i)
	{
		mst[i].first=-1;
		mst[i].second=max_val;
	}

	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	ll cost=0;

	q.push(make_pair(0,root));
	mst[root].second=0;

	while(!q.empty())
	{
		tpair=q.top();
		q.pop();
		int tnode=tpair.second;
		int ttnode;

		//check for cycle before pushing
		if(visited[tnode]==true)
		{
			continue;
		}
		cost=cost+tpair.first;
		visited[tnode]=true;

		for(int i=0;i<adj[tnode].size();++i)
		{
			ttnode=adj[tnode][i].second;
			if(visited[ttnode]==false)
			{
				q.push(adj[tnode][i]);
				
			}
		}
	}
	return cost;
}	

int main()
{
	cin>>nodes>>edges;
	int a,b,c;
	for(int i=0;i<edges;++i)
	{
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(c,b));
		adj[b].push_back(make_pair(c,a));
	}
	root=1;
	cout<<prim()<<endl;
}	