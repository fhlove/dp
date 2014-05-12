/*************************************************************************
    > File Name: cf-243-2-E.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月01日 星期四 14时44分15秒
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
const int inf=99999999;
const int N=100005;
int dp[400];
int a[N],b[N];
vector<int> v[N];
void init(int n,int m)
{
	for(int i=0;i<N;i++)
		v[i].clear();
	fill(dp,dp+400,inf);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int n,m,s,e;
	while(cin>>n>>m>>s>>e)
	{
		init(n,m);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int j=1;j<=m;j++)
		{
			cin>>b[j];
			v[b[j]].push_back(j);
		}
		int res=0;
		dp[0]=-1;
		for(int i=1;i<=n;i++)
		{
			if(v[a[i]].size()==0) continue;
			for(int j=s/e;j>0;j--)
			{
				int temp=dp[j-1];
				int index=upper_bound(v[a[i]].begin(),v[a[i]].end(),temp)-v[a[i]].begin();
				if(index==v[a[i]].size()) continue;
				dp[j]=min(dp[j],v[a[i]][index]);
				if(i+j*e+dp[j]<=s) res=max(res,j);
			}
		}
		cout<<res<<endl;
	}
    return 0;
}
