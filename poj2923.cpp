/*************************************************************************
    > File Name: poj2923.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月06日 星期四 19时34分19秒
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
const int N=15;
int dp[1<<11];
int w[N];
int st[1<<11];
int c1,c2,n;
bool judage(int s)
{
	bool vis[200];
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(s&(1<<i))
		{
			sum+=w[i];
			for(int j=c1;j>=w[i];j--)
				if(vis[j-w[i]]) vis[j]=1;
		}
	}
	for(int i=c1;i>=0;i--)
	{
		if(vis[i]&&sum-i<=c2) return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt","r",stdin);
	int t;
	int cases=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&c1,&c2);
		int ans=0;
		if(c1>c2) swap(c1,c2);
		for(int i=0;i<n;i++)
			cin>>w[i];
		int cont=0;
		for(int s=0;s<(1<<n);s++)
		{
			if(judage(s)) st[cont++]=s;
		}
		memset(dp,0x1f,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<cont;i++)
		{
			for(int s=(1<<n)-1;s>=0;s--)
			{
				if(s&(st[i])) continue;
				dp[s|st[i]]=min(dp[s]+1,dp[s|st[i]]);
			}
		}
		printf("Scenario #%d:\n%d\n",cases++,dp[(1<<n)-1]);
		if(t!=0) puts("");
	}
	return 0;
}
/*
分析：先预处理出来可以一次运输完的状态，然后在背包。
*/
