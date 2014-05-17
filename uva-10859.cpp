/*************************************************************************
    > File Name: uva-10859.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月17日 星期六 16时24分28秒
 ************************************************************************/
//ans=M*a+b
#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<bitset>
#include<sstream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
const int N=1005;
const int inf=2000;
int dp[N][2];
bool vis[N][2];
vector<int> g[N];
void init(int n)
{
	for(int i=0;i<=n;i++)
		g[i].clear();
}
int dfs(int u,int j,int f)
{
	if(vis[u][j]) return dp[u][j];
	vis[u][j]=1;
	int ans=inf;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==f) continue;
		ans+=dfs(v,1,u);
	}
	if(!j&&f>=0) ans++;
	if(j||f<0)
	{
		int sum=0;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(v==f) continue;
			sum+=dfs(v,0,u);
		}
		if(f>=0) sum++;
		ans=min(ans,sum);
	}
	dp[u][j]=ans;
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		init(n);
		int x,y;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		int res=0;
		for(int i=0;i<n;i++)
		{
			if(!vis[i][0]) 
				res+=dfs(i,0,-1);
		}
		cout<<res/inf<<" "<<(m-res%inf)<<" "<<res%inf<<endl;
	}
    return 0;
}
