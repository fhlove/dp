/*************************************************************************
    > File Name: 119-2-A.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月26日 星期三 16时20分04秒
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
const int N=4005;
int dp[N];
int main()
{
	//freopen("input.txt","r",stdin);
	int n,a[3];
	cin>>n;
	cin>>a[0]>>a[1]>>a[2];
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<3;i++)
	{
		for(int j=a[i];j<=n;j++)
		{
			if(dp[j-a[i]]>=0) dp[j]=max(dp[j],dp[j-a[i]]+1);
		}
	}
	if(dp[n]>0) cout<<dp[n]<<endl;
	else cout<<0<<endl;
	return 0;
}
