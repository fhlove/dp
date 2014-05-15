/*
PROG: uva-10891.cpp
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=105;
const int inf=10e8;
int dp[N][N];
int sum[N];
bool vis[N][N];
int a[N];
int calc(int l,int r)
{
	if(vis[l][r]) return dp[l][r];
	
	int res=0;
	
	for(int i=l+1;i<=r;i++)
		res=min(res,calc(i,r));
	
	for(int i=l;i<r;i++)
		res=min(res,calc(l,i));

	res=sum[r]-sum[l-1]-res;
	
	vis[l][r]=1;
	dp[l][r]=res;
	
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int n;
	while(cin>>n&&n)
	{
		memset(vis,0,sizeof(vis));
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		int res=calc(1,n);
		cout<<res*2-sum[n]<<endl;
	}
    return 0;
}
