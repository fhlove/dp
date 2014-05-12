/*************************************************************************
    > File Name: 1032.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月13日 星期日 13时51分57秒
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
const int N=50;
typedef long long ll;
ll dp[N][2];
void init()
{
	memset(dp,0,sizeof(dp));
	for(int i=2;i<=32;i++)
	{
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i][0]+(1<<(i-2));
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	ll n;
	init();
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>n;
		ll cont=0;
		ll ans=0;
		for(int i=31;i>=0;i--)
		{
			if((1<<i)&n)
			{
				ans+=dp[i+1][0];
				ans+=cont*(1<<i);
				if(i+1<32 && (1<<(i+1))&n) cont++;
			}
		}
		ans+=cont;
		printf("Case %d: ",c);
		cout<<ans<<endl;
	}
    return 0;
}
/*
预处理出来dp[i][j]表示首位为j，长度为i的数字包含的连续一的个数。
*/
