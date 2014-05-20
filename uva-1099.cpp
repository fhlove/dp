/*************************************************************************
    > File Name: uva-1099.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月20日 星期二 21时26分45秒
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
const int N=16;
int dp[1<<N][150];
bool vis[1<<N][150];
int s[1<<N];
int a[150];

int bitcont(int x)
{
	int res=0;
	while(x)
	{
		if(x&1) res++;
		x=x>>1;
	}
	return res;
}

int dfs(int st,int x)
{
	if(vis[st][x]) return dp[st][x];
	vis[st][x]=1;
	int res=0;
	if(bitcont(st)==1) return dp[st][x]=1;
	int y=s[st]/x;
	
	for(int s0=(st-1)&st;s0;s0=(s0-1)&st)
	{
		int s1=st-s0;
		if(s[s0]%x==0&&dfs(s0,min(x,s[s0]/x))&&dfs(s1,min(x,s[s1]/x)))
		{
			return dp[st][x]=1;
		}
		if(s[s0]%y==0&&dfs(s0,min(y,s[s0]/y))&&dfs(s1,min(y,s[s1]/y)))
		{
			return dp[st][x]=1;
		}
	}
	
	dp[st][x]=res;
	return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int n;
	int x,y;
	int t=1;
	while(cin>>n&&n)
	{
		cin>>x>>y;
		for(int i=0;i<n;i++)
			cin>>a[i];
		memset(s,0,sizeof(s));
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<n;j++)
				if(i&(1<<j)) s[i]+=a[j];
		}
		
		int all=(1<<n)-1;
		int res=0;
		if(s[all]!=x*y) res=0;
		else res=dfs(all,min(x,y));
		
		printf("Case %d: %s\n",t++,res==0? "No":"Yes");
	}
    return 0;
}
