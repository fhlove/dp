/*************************************************************************
    > File Name: poj2411.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月06日 星期四 20时23分03秒
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
const int N=13;
int n,m;
ll cont;
ll dp[N][1<<N];
void dfs(int i,int s,int id)
{
	if(id==m)
	{
		dp[i][s]+=cont;
		return;
	}
	dfs(i,s,id+1);
	if(id+2<=m&&!(s&(1<<id))&&!(s&(1<<(id+1))))
		dfs(i,s|1<<id|1<<id+1,id+2);
}
int main()
{
	//freopen("input.txt","r",stdin);
	while(cin>>n>>m&&(n||m))
	{
		if((n*m)&1) 
		{
			cout<<0<<endl;
			continue;
		}
		if(m>n) swap(n,m);
		memset(dp,0,sizeof(dp));

		cont=1;
		dfs(1,0,0);
		for(int i=2;i<=n;i++)
		{
			for(int s=0;s<(1<<m);s++)
			{
				if(dp[i-1][s]) cont=dp[i-1][s];
				else continue;
				dfs(i,~s&((1<<m)-1),0);
			}
		}
		cout<<dp[n][(1<<m)-1]<<endl;
	}
	return 0;
}
/*
分析：当前一行的状态只与上一行有关，当上一位置为0时，说明该位置可以竖着放，然后只需要判断横着放置的情况。
*/
