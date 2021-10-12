#include<bits/stdc++.h>
using namespace std;
int lca[100001][100001];
vector<int> adj[100001];
void dfs(int node,int par)
{
	lca[node][0] = par;
	for(int child : adj[node])
	{
		if(child!=par)
		{
			dfs(child,node);
		}
	}
}
int LCA(int a,int b)
{
	if(level[b]<level[a])
	{
		swap(level[a],level[b]);
	}
	int d = level[b]-level[a];
	while(d>0)
	{
		int i = log2(d);
		b = lca[b][i];
		d-= (1<<i);
	}
	if(a==b)
	{
		return a;
	}
	for(int i=maxN;i>=0;i--)
	{
		if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i])
		{
			a = lca[a][i],b=lca[b][i];
		}
	}
	return lca[a][0];
}
int main()
{
	dfs(1,-1);
	for(int j=1;j<=maxN;j++)
	{
		for(int i=1;i<=N;i++)
		{
			if(lca[i][j-1]!=-1)
			{
				int par = lca[i][j-1];
				lca[i][j] = lca[par][j-1];
			}
		}
	}
}
