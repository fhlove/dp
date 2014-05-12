/*************************************************************************
    > File Name: 1047.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月20日 星期日 19时42分00秒
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
const int N=50;
struct node
{
	int r,g,b;
};
node house[N];
int dp[N][3];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&house[i].r,&house[i].g,&house[i].b);

		dp[1][0]=house[1].r;
		dp[1][1]=house[1].g;
		dp[1][2]=house[1].b;
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+house[i].r;
			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+house[i].g;
			dp[i][2]=min(dp[i-1][0],dp[i-1][1])+house[i].b;	
		}
		int ans=min(dp[n][0],min(dp[n][1],dp[n][2]));
		printf("Case %d: %d\n",c,ans);
	}
    return 0;
}
