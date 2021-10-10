#include<bits/stdc++.h>
using namespace std;
int ans=0;
void solve(vector<int> &a,int k,int idx)
{
    if(a.size()==1)
    {
        ans = a[0];
        return;
    }
    idx = (idx+k)%a.size();
    a.erase(a.begin()+idx);
    solve(a,k,idx);
}
int josephus(int n, int k)
{
   vector<int> a(n);
   for(int i=0;i<n;i++)
   {
       a[i]=i+1;
   }
   k--;
   solve(a,k,0);
   return ans;
}
int main()
{
	int n,k;
	cin>>n>>k;
	int res = josephus(n,k);
	cout<<res;
}
