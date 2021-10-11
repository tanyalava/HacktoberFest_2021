#include<bits/stdc++.h>
using namespace std;
int vis[100001],in[100001],low[100001];
vector<int> ar[100001];
int timer;
void dfs(int n,int par)
{
	vis[n]=1;
	in[n] = low[n] = timer;
	timer++;
	for(int i=0;i<ar[n].size();i++)
	{
		int child = ar[n][i];
		if(child==par)
		{
			continue;
		}
		if(vis[child]==1)
		{
			//edge child-node is a back edge
			low[n] = min(low[n],in[child]);
		}
		else
		{
			//edge child-node is a forward edge
			dfs(child,n);
			if(low[child]>in[n])
			{
				cout<<n<<" - "<<child<<" is a bridge\n";
			}
			low[n] = min(low[n],low[child]);
		}
	}
}
int main()
{
	int n,m,x,y;
	cin>>n>>m;
	while(m--)
	{
		cin>>x>>y;
		ar[x].push_back(y);
		ar[y].push_back(x);
	}
	dfs(1,-1);
}
