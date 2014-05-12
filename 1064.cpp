/*************************************************************************
    > File Name: 1064.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月28日 星期一 16时58分23秒
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
const int N=30;
ll dp[N][N*6];
ll sum[N];
void init()
{
	memset(dp,0,sizeof(dp));
	sum[0]=1;
	for(int i=1;i<=25;i++)
		sum[i]=sum[i-1]*6;

	for(int i=1;i<=6;i++)
		dp[1][i]=1;
	
	for(int i=2;i<=25;i++)
	{
		for(int j=i;j<=i*6;j++)
		{
			for(int k=1;k<=6;k++)
				if(j-k>=i-1)
					dp[i][j]+=dp[i-1][j-k];
		}
	}
	for(int i=1;i<=25;i++)
	{
		for(int j=i*6;j>=0;j--)
			dp[i][j]+=dp[i][j+1];
	}
}
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n,m;
	cin>>t;
	init();
	for(int c=1;c<=t;c++)
	{
		cin>>n>>m;
		ll a=sum[n];
		ll b=dp[n][m];
		ll gc=gcd(a,b);
		a/=gc;
		b/=gc;
		printf("Case :%d ",c);
		if(a==1) cout<<b<<endl;
		else cout<<b<<"/"<<a<<endl;
	}
    return 0;
}
