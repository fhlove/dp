/*************************************************************************
    > File Name: Anniversary_party.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月11日 星期二 21时18分35秒
 ************************************************************************/

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
const int N=6005;
vector<int> g[N];
bool vis[N];
int val[N];
int dp[N][2];
void init(int n)
{
	for(int i=0;i<=n;i++)
		g[i].clear();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		dp[i][1]=val[i],dp[i][0]=0;
}
void dfs(int x)
{
	for(int i=0;i<(int)g[x].size();i++)
	{
		dfs(g[x][i]);
		dp[x][1]+=(dp[g[x][i]][0]);
		dp[x][0]+=max(dp[g[x][i]][0],dp[g[x][i]][1]);
	}
}
int main()
{
	freopen("/home/mengshangqi/input.txt","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int x,y;
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		init(n);
		while(scanf("%d%d",&x,&y)&&(x||y))
		{
			g[y].push_back(x);
			vis[x]=1;
		}
		int point=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]) {
				point=i;
				break;
			}
		dfs(point);
		printf("%d\n",max(dp[point][0],dp[point][1]));
	}
	return 0;
}
