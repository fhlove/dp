/*************************************************************************
    > File Name: 1017_Brush.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月01日 星期二 20时31分19秒
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
struct node {
	int x,y;
};
node p[N];
int mv[N];
int dp[N][N];
bool cmp(node a,node b)
{
	return a.y<b.y;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n,w,k;
	cin>>t;
	int c=1;
	while(t--)
	{
		cin>>n>>w>>k;
		for(int i=1;i<=n;i++)
			cin>>p[i].x>>p[i].y;
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int cont=0;
			int yy=p[i].y-w;
			for(int j=1;j<=i;j++)
				if(p[j].y>=yy) cont++;
			mv[i]=cont;
		}
		memset(dp,0,sizeof(dp));	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(i>=mv[i])
				{
					dp[i][j]=max(dp[i-1][j],dp[i-mv[i]][j-1]+mv[i]);
				}
			}
		}
		printf("Case %d: %d\n",c++,dp[n][k]);
	}
    return 0;
}
