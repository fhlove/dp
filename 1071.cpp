/*************************************************************************
    > File Name: 1071.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月02日 星期五 14时39分57秒
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
const int N=105;
int v[N][N];
int dp[N][N];
int path[N][N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n,m;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&v[i][j]);
		memset(path,-1,sizeof(path));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(dp[i-1][j]>dp[i][j-1])
				{
					dp[i][j]=dp[i-1][j]+v[i][j];
					path[i][j]=1;
				}else {
					dp[i][j]=dp[i][j-1]+v[i][j];
					path[i][j]=0;
				}
			}
		}
		int res=dp[n][m];
		int x=n;
		int y=m;
		while(path[x][y]!=-1)
		{
			v[x][y]=-1;
			if(path[x][y]==1) x--;
			else y--;
		}
		memset(dp,0,sizeof(dp));
		for(int i=n;i>0;i--)
		{
			for(int j=m;j>0;j--)
			{
				if(v[i][j]!=-1)
					dp[i][j]=max(dp[i+1][j],dp[i][j+1])+v[i][j];
			}
		}
		res+=dp[1][1];
		printf("Case %d: %d\n",c,res);
	}
    return 0;
}
