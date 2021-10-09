#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int sum=0,ans=0,j=0,i=0;
		while(j<n)
		{
			sum = sum + a[j];
			if(j-i+1<k)
			{
				j++;
			}
			else if(j-i+1==k)
			{
				ans = max(ans,sum);
				sum = sum-a[i];
				i++;
				j++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
