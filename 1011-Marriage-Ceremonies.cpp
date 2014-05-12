/*************************************************************************
    > File Name: 1011-Marriage-Ceremonies.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月14日 星期五 21时34分43秒
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
const int N=17;
int dp[1<<N];
int val[N][N];
int n;
int dfs(int s,int man)
{
	if(s==0) return 0;
	if(dp[s]>0) return dp[s];
	for(int i=0;i<n;i++)
	{
		if((1<<i)&s)
			dp[s]=max(dp[s],dfs(s^(1<<i),man-1)+val[man][i]);
	}
	return dp[s];
}
int main()
{
	//freopen("/home/mengshangqi/input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&val[i][j]);

		memset(dp,0,sizeof(dp));
		int s=(1<<n)-1;
		dfs(s,n-1);
		printf("Case %d: %d\n",c,dp[s]);
	}
	return 0;
}
