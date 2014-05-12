/*************************************************************************
    > File Name: 1018_Brush.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月01日 星期二 21时41分23秒
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
const int N=20;
const int inf=9999999;
struct node
{
	int x,y;
};
node p[N];
int stat[N*N];
int dp[(1<<17)];
bool judge(int x1,int y1,int x2,int y2)
{
	if(x1*y2==x2*y1) return true;
	return false;
}
void init(int &cont,int n)
{
	cont=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int st=0;
			st=st|(1<<i)|(1<<j);
			int fx=p[j].x-p[i].x;
			int fy=p[j].y-p[i].y;
			for(int k=j+1;k<n;k++)
			{
				int gx=p[k].x-p[i].x;
				int gy=p[k].y-p[i].y;
				if(judge(fx,fy,gx,gy))
					st=st|(1<<k);
			}
			stat[cont++]=st;
		}
	}
}
int dfs(int st,int cont)
{
	if(st==0) return 0;
	if(dp[st]!=inf) return dp[st];
	for(int i=0;i<cont;i++)
	{
		if(stat[i]&st)
			dp[st]=min(dp[st],dfs(st-(st&stat[i]),cont)+1);
	}
	return dp[st];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n;
	int c=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int cont=0;
		for(int i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		init(cont,n);
		int st=(1<<n)-1;
		for(int i=0;i<=st;i++)
			dp[i]=inf;
		sort(stat,stat+cont);
		int size=unique(stat,stat+cont)-stat;
		dfs(st,size);	
		printf("Case %d: %d\n",c++,dp[st]);
	}
    return 0;
}
