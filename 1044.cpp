/*************************************************************************
    > File Name: 1044.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月19日 星期六 21时29分39秒
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
const int N=1005;
set<int> v[N];
char str[N];
int dp[N];
void init()
{

	int n=strlen(str);
	for(int i=0;i<n;i++)
		v[i].clear();

	for(int i=0;i<n;i++)
	{
		int l=i;
		int r=i;
		while(str[l]==str[r]&&l>=0&&r<n)
		{
			v[r].insert(l);
			l--;
			r++;
		}

		l=i;
		r=i+1;
		while(str[l]==str[r]&&l>=0&&r<n)
		{
			v[r].insert(l);
			l--;
			r++;	
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		
		scanf("%s",str);
		int n=strlen(str);
		init();
		memset(dp,0x1f,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<n;i++)
		{
			int res=dp[i-1]+1;
			for(set<int>:: iterator it=v[i].begin();it!=v[i].end();it++)
			{
				int temp=*it;
				//printf("%d   %d\n",temp,i);
				res=min(res,dp[temp-1]+1);
			}
			dp[i]=res;
		}
		printf("Case %d: %d\n",c,dp[n-1]);
	}
    return 0;
}
/*
dp[i]表示一i结尾的字符串中回文串的最少个数，首先预处理出来每个回文串的两端，
然后就是背包问题了
*/
