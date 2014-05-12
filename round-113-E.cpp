/*************************************************************************
    > File Name: round-113-E.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月25日 星期二 21时43分26秒
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
const int mod=1000000007;
int dp[2][4];
int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int pre=(i-1)&1;
		int now=i&1;
		dp[now][0]=((dp[pre][1]+dp[pre][2])%mod+dp[pre][3])%mod;
		dp[now][1]=((dp[pre][0]+dp[pre][2])%mod+dp[pre][3])%mod;
		dp[now][2]=((dp[pre][1]+dp[pre][0])%mod+dp[pre][3])%mod;
		dp[now][3]=((dp[pre][0]+dp[pre][1])%mod+dp[pre][2])%mod;
	}
	cout<<dp[n&1][0]<<endl;
	return 0;
}
