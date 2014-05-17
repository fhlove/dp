/*************************************************************************
    > File Name: uva-11825.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月17日 星期六 14时47分45秒
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
const int N=18;
int p[N];
int co[1<<N],dp[1<<N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int c=1;
	int n,m;
	int x;
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			p[i]=(1<<i);
			cin>>m;
			int st=0;
			while(m--)
			{
				cin>>x;
				p[i]=p[i]|(1<<x);
			}	
		}
		memset(co,0,sizeof(co));
		memset(dp,0,sizeof(dp));
		for(int s=0;s<(1<<n);s++)
		{
			for(int i=0;i<n;i++)
			{
				if(s&(1<<i)) co[s]|=p[i];
			}
		}

		int all=(1<<n)-1;
		for(int s=0;s<(1<<n);s++)
		{
			for(int s0=s;s0;s0=(s0-1)&s)
			{
				if(co[s0]==all) dp[s]=max(dp[s],dp[s^s0]+1);
			}
		}
		printf("Case %d: %d\n",c++,dp[all]);
	}
    return 0;
}
