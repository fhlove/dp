/*************************************************************************
    > File Name: 1033.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月13日 星期日 15时19分03秒
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
const int N=105;
string str;
int dp[N][N];
void init(int n)
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(i==j) dp[i][j]=0;
			else dp[i][j]=inf;
}
int dfs(int l,int r)
{
	if(l>r) return 0;
	int &res=dp[l][r];
	if(res!=inf) return res;
	if(str[l]==str[r]) res=min(res,dfs(l+1,r-1));

	res=min(min(res,dfs(l+1,r)+1),dfs(l,r-1)+1);
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>str;
		int n=str.length();
		init(n);
		int ans=dfs(0,n-1);
		printf("Case %d: ",c);
		cout<<ans<<endl;
	}
    return 0;
}
/*
区间dp，dp[i][j]表示区间 i 到 j变成回文字符所要添加的最少的字符个数。
*/
