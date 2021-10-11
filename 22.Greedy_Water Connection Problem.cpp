#include <bits/stdc++.h>
using namespace std;

int n, p;

int ith_pipe_ends_at[10];
int ith_pipe_receives_from[10];
int diameter[10];


vector<int> a;
vector<int> b;
vector<int> c;

int ans;

int dfs(int w)
{
	if (ith_pipe_ends_at[w] == 0) 
		return w;
	if (diameter[w] < ans)
		ans = diameter[w];
	return dfs(ith_pipe_ends_at[w]);
}

void function(int arr[][3])
{
	int i = 0;
	while (i < p) 
	{
		int q = arr[i][0];   
		int h = arr[i][1];    
		int t = arr[i][2];   
		ith_pipe_ends_at[q] = h; 
		diameter[q] = t;
		ith_pipe_receives_from[h] = q;
		i++;
	}

	a.clear();
	b.clear();
	c.clear();
	
	for (int j = 1; j <= n; ++j)
	
		if (ith_pipe_receives_from[j] == 0 && ith_pipe_ends_at[j]) {
			ans = 1000000000;
			int w = dfs(j);
			a.push_back(j);
			b.push_back(w);
			c.push_back(ans);
		}
		
	cout << a.size() << endl;
	for (int j = 0; j < a.size(); ++j)
		cout << a[j] << " " << b[j]
			<< " " << c[j] << endl;
}


int main()
{
n=9,p=6;	
memset(ith_pipe_ends_at,0,sizeof(ith_pipe_ends_at));
memset(ith_pipe_receives_from,0,sizeof(ith_pipe_receives_from));
memset(diameter,0,sizeof(diameter));
int arr[][3]={ {7,4,98},{5,9,72},{4,6,10},{2,8,22},{9,7,17},{3,1,66} };
function(arr);
return 0;
}



