#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0,ans=0;
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum==k)
		{
			ans = i+1;
		}
		if(mp.find(sum)==mp.end())
		{
			mp[sum]=i;
		}
		if(mp.find(sum-k)!=mp.end())
		{
			ans = max(ans,i-mp[sum-k]);
		}
	}
	cout<<ans;
	return 0;
}
