/*************************************************************************
    > File Name: Labyrinth.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月16日 星期五 21时01分56秒
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
int dp[N][N][2];
int v[N][N];
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
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&v[i][j]);
		
		for(int i=1;i<=n;i++)
		{
			dp[i][1][0]=dp[i-1][1][0]+v[i][1];
			dp[i][1][1]=dp[i-1][1][1]+v[i][1];
		}

		for(int i=2;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==1) dp[j][i][0]=max(dp[j][i-1][0],dp[j][i-1][1])+v[j][i];
				else {
					dp[j][i][0]=max(dp[j-1][i][0],max(dp[j][i-1][0],dp[j][i-1][1]))+v[j][i];
				}
			}

			for(int j=n;j>=1;j--)
			{
				if(j==n) dp[j][i][1]=max(dp[j][i-1][0],dp[j][i-1][1])+v[j][i];
				else {
					dp[j][i][1]=max(dp[j+1][i][1],max(dp[j][i-1][0],dp[j][i-1][1]))+v[j][i];
				}
			}
		}



		printf("Case #%d:\n%d\n",c,max(dp[1][m][0],dp[1][m][1]));
	}
    return 0;
}
