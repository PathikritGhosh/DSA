# include <bits/stdc++.h>
using namespace std;

# define ll long long int

vector<pair<int,pair<int,int> > > graphs[112345]; //(weight,(u,v)):each index stores an edge
pair<int,int> tpair;
pair<int,pair<int,int> > ttpair;
int parent[112345];
vector<pair<int,pair<int,int> > > mst[112345];

int nodes,edges,mst_edges;

void init_set(int size)
{
	for(int i=1;i<=size;++i)
	{
		parent[i]=i;
	}
}

int find(int index,int size)
{
	if(parent[index] == index)
	{
		return index;
	}
	return find(parent[index],size);
}

void union_set(int x,int y,int size)
{
	int xset=find(x,size);
	int yset=find(y,size);
	parent[xset]=yset;
}

bool comp(vector<pair<int,pair<int,int> > > i,vector<pair<int,pair<int,int> > > j)
{
	return (i[0].first < j[0].first);
}

ll kruskal()
{
	ll temp_cost=0;
	sort(graphs,graphs+edges,comp);
	init_set(nodes);
	for(int i=0;i<edges;++i)
	{
		int t_index=graphs[i][0].second.first;
		int tt_index=graphs[i][0].second.second;
		if(find(t_index,edges) != find(tt_index,edges))
		{	
			union_set(t_index,tt_index,edges);
			temp_cost=temp_cost+graphs[i][0].first;
			ttpair.first=graphs[i][0].first;
			ttpair.second.first=t_index;
			ttpair.second.second=tt_index;
			mst[mst_edges++].push_back(ttpair);
		}
	}
	return temp_cost;
}

int main()
{
	int a,b;
	ll c;
	cin>>nodes>>edges;
	for(int i=0;i<edges;++i)
	{
		cin>>a>>b>>c;
		ttpair.first=c;
		ttpair.second.first=a;
		ttpair.second.second=b;
		graphs[i].push_back(ttpair);	
	}
	cout<<kruskal()<<endl;
}