/*************************************************************************
    > File Name: uva-11584.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年06月03日 星期二 17时36分02秒
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
const int N=10000;
const int inf=1e7+7;
int dp[N];
char str[N];
bool judge(int l,int r)
{
	while(l<r)
	{
		if(str[l]!=str[r]) return false;
		l++;
		r--;
	}
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%s",str+1);
		int n=strlen(str+1);
		dp[1]=1;
		for(int i=2;i<=n;i++)
		{
			int temp=inf;
			for(int j=1;j<i;j++)
			{
				if(judge(j,i)) temp=min(temp,dp[j-1]);
			}
			dp[i]=min(temp+1,dp[i-1]+1);
		}
		cout<<dp[n]<<endl;
	}
    return 0;
}
