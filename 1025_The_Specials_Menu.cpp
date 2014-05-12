/*************************************************************************
    > File Name: 1025_The_Specials_Menu.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月02日 星期三 15时37分51秒
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
typedef long long ll;
string str;
ll dp[N][N];
void init()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=str.length();i++)
		dp[i][i]=1;
}
ll dfs(int l,int r)
{
	if(l>r) return 0;
	if(l==r) return dp[l][r];
	if(dp[l][r]>0) return dp[l][r];
	if(str[l]==str[r]) 
	{
		dp[l][r]=dfs(l+1,r)+dfs(l,r-1)-dfs(l+1,r-1)+dfs(l+1,r-1)+1;
	}else {
		dp[l][r]=dfs(l+1,r)+dfs(l,r-1)-dfs(l+1,r-1);
	}
	return dp[l][r];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	cin>>t;
	int c=1;
	while(t--)
	{
		cin>>str;
		init();
		ll ans=dfs(0,str.length()-1);
		printf("Case %d: %lld\n",c++,ans);
	}
    return 0;
}

（1）i==j:f[i][j]=1;
（2）s[i]!=s[j]:f[i][j]=f[i+1][j]+f[i][j-1]-f[i+1][j-1];
（3）s[i]==s[j]:f[i][j]=（f[i+1][j]+f[i][j-1]-f[i+1][j-1]）+(f[i+1][j-1]+1)（加1是因为中间[i+1,j-1]的全部删掉也是一种）。
