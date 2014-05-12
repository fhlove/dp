/*************************************************************************
    > File Name: 1021_Painful_Bases.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月02日 星期三 15时05分43秒
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
typedef long long ll;
ll dp[(1<<N)+5][20];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int base,k;
	int c=1;
	string str;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>base>>k;
		cin>>str;
		dp[0][0]=1;
		int res=0;
		int n=str.length();
		for(int s=0;s<(1<<n);s++)
		{
			for(int j=0;j<str.length();j++)
			{
				for(int mod=0;mod<k;mod++)
				{
					if(s&(1<<j)) continue;
					int now=s|(1<<j);
					int temp=str[j]-'0';
					if(str[j]>'9') temp=str[j]-'A'+10;	
					int res=(mod*base+temp)%k;
					dp[now][res]+=dp[s][mod];
				}
			}
		}
		printf("Case %d: %lld\n",c++,dp[(1<<n)-1][0]);
	}
    return 0;
}
/*
dp[s][mod]表示数字集合为s，mod的总数
*/
