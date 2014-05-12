/*************************************************************************
    > File Name: 1051.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月20日 星期日 20时00分48秒
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
const int N=100;
bool dp[N][7];
bool dp1[N][7];
char str[N];
int x[N];
bool judge(char ch)
{
	if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return true;
	return false;
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
		bool flag1=0;
		bool flag2=0;
		memset(dp,0,sizeof(dp));
		memset(dp1,0,sizeof(dp1));
		cin>>(str+1);
		dp1[0][0]=dp[0][0]=1;
		int n=strlen(str+1);
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='?') x[i]=2;
			else if(judge(str[i])) x[i]=0;
			else x[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(!dp[i-1][j]) continue;
				char ch=str[i];
				if(judge(ch)||ch=='?') dp[i][j+1]=1;
				if(!judge(ch)||ch=='?') dp1[i][1]=1;
			}
			for(int j=0;j<5;j++)
			{
				if(!dp1[i-1][j]) continue;
				char ch=str[i];
				if(!judge(ch)||ch=='?') dp1[i][j+1]=1;
				if(judge(ch)||ch=='?') dp[i][1]=1;
			}
		}
		for(int i=1;i<=n;i++)
			if(dp[i][3]||dp1[i][5]) flag1=1;
		for(int i=0;i<3;i++)
			if(dp[n][i]) flag2=1;
		for(int i=0;i<5;i++)
			if(dp1[n][i]) flag2=1;
		printf("Case %d: ",c);
		if(flag1&&flag2) cout<<"MIXED"<<endl;
		else if(flag1) cout<<"BAD"<<endl;
		else cout<<"GOOD"<<endl;

	}
    return 0;
}
/*
dp[i][j]表示一i为结尾，辅音或原音字母连续个数为j的状态是否可达
*/
