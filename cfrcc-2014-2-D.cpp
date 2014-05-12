/*************************************************************************
    > File Name: cfrcc-2014-2-D.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月19日 星期六 22时11分21秒
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
typedef long long ll;
const int N=21;
const ll inf=(ll(1)<<ll(60))-ll(1);

struct node
{
	ll val,bx;
};
node dp[1<<N];
struct nodes
{
	int sta;
	ll cost;
	ll x;
};
nodes a[N*20];
void init(int n)
{
	for(int i=0;i<(1<<n);i++)
	{
		dp[i].val=inf,dp[i].bx=0;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int n,m,b;
	//cin>>n>>m>>b;
	scanf("%d%d%d",&n,&m,&b);
	for(int i=0;i<n;i++)
	{
		int cont;
		//cin>>a[i].cost>>a[i].x>>cont;
		scanf("%d%d%d",&a[i].cost,&a[i].x,&cont);
		a[i].sta=0;
		int id;
		while(cont--)
		{
			scanf("%d",&id);
			id--;
			a[i].sta=a[i].sta|(1<<id);
		}
	}
	init(m);
	dp[0].val=0;
	dp[0].bx=0;
	for(int i=0;i<(1<<m);i++)
	{
		for(int j=0;j<n;j++)
		{
			int now=a[j].sta|i;
			if(dp[now].val>dp[i].val -dp[i].bx*b + max(dp[i].bx,a[j].x)*b + a[j].cost)
			{
				dp[now].val=dp[i].val-dp[i].bx*b+max(dp[i].bx,a[j].x)*b+a[j].cost;
				//cout<<dp[now].val<<endl;
				dp[now].bx=max(dp[i].bx,a[j].x);
			}else if(dp[now].val == dp[i].val - dp[i].bx * b + max(dp[i].bx,a[j].x) * b + a[j].cost && dp[now].bx > max(dp[i].bx,a[j].x))
			{
				dp[now].bx=max(dp[i].bx,a[j].x);
			}
		}
	}
	if(dp[(1<<m)-1].val==inf) printf("-1\n");
	else printf("%I64d\n",dp[(1<<m)-1].val);
    return 0;
}
