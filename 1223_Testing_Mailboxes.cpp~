/*************************************************************************
    > File Name: 1223_Testing_Mailboxes.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月02日 星期三 16时31分49秒
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
const int N=150;
const int inf=9999999;
int dp[N][N][N];
int dfs(int x,int l,int r)
{	
	if(l>r) return 0;
	int &res=dp[x][l][r];
	if(res>0) return res;
	res=inf;
	for(int i=l;i<=r;i++)
	{
		res=min(res,i+max(dfs(x-1,l,i-1),dfs(x,i+1,r)));
	}
	return res;
}
void init()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j++)
			dp[1][i][j]=(i+j)*(j-i+1)/2;
	for(int i=2;i<N;i++)
	{
		for(int j=1;j<N;j++)
		{
			for(int k=j;k<N;k++)
				dfs(i,j,k);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int k,m;
	cin>>t;
	init();
	int c=1;
	while(t--)
	{
		cin>>k>>m;
		printf("Case %d: %d\n",c++,dp[k][1][m]);
	}
    return 0;
}
/*
dp[i][j][k]表示用i 个箱子测试 j到 k的值所要的最小花费
*/
