/*************************************************************************
    > File Name: 1013_Love_Calculator.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月01日 星期二 17时05分36秒
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
const int N=200;
typedef long long ll;
ll dp[N][N][N];
ll lcs(string str1,string str2)
{
	ll dp[N][N];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=str1.length();i++)
	{
		for(int j=1;j<=str2.length();j++)
		{
			if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[str1.length()][str2.length()];
}
ll calc(string str1,string str2,int n)
{
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=str1.length();j++)
		{
			for(int k=0;k<=str2.length();k++)
			{
				if(dp[i][j][k])
				{
					if(str1[j]==str2[k]) dp[i+1][j+1][k+1]+=dp[i][j][k];
					else {
						dp[i+1][j+1][k]+=dp[i][j][k];
						dp[i+1][j][k+1]+=dp[i][j][k];
					}
				}
			}
		}
	}
	return dp[n][str1.length()][str2.length()];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	string str1,str2;
	int cont=1;
	cin>>t;
	while(t--)
	{
		cin>>str1>>str2;
		int res=lcs(str1,str2);
		res=str1.length()+str2.length()-res;
		ll ans=calc(str1,str2,res);
		printf("Case %d: %d %lld\n",cont++,res,ans);
	}
    return 0;
}
/*
dp[i][j][k]表示 str1 前 j 个字符和 str2 前 k 个字符构成长度为 i 的字符串种类。
*/
