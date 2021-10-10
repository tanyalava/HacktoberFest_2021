#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int a, b, cost;
};
int n, m, v;
vector<edge> e;
const int INF = 1000000000;
void solve()
{
    vector<int> d (n, INF);
    d[v] = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);
                
    for(int i=0;i<d.size();i++)
	{
		cout<<d[i]<<" ";
	}            
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>e[i].a>>e[i].b>>e[i].cost;
	}
	solve();
	return 0;
}
