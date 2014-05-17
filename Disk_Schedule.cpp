/*************************************************************************
    > File Name: Disk_Schedule.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月17日 星期六 15时21分08秒
 ************************************************************************/
//双调欧几里得
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
typedef pair<int,int> PII;
const int N=1005;
PII a[N];
int dp[N][N];
int dis(PII x,PII y)
{
	int res=0;
	res+=(abs(x.first-y.first))*400;

	int temp=abs(x.second-y.second);

	res+=min(temp,360-temp);
	
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d",&n);
		
		a[0].first=0;
		a[0].second=0;
		
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i].first,&a[i].second);
		memset(dp,0x1f,sizeof(dp));
		for(int i=0;i<=n;i++)
			dp[i][0]=dis(a[i],a[0]);

		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<i-1;j++)
			{
				dp[i][j]=dp[i-1][j]+dis(a[i],a[i-1]);

				dp[i][i-1]=min(dp[i][i-1],dp[i-1][j]+dis(a[i],a[j]));
			}
		}
		printf("%d\n",dp[n][n-1]+dis(a[n],a[n-1])+n*10);
	}
    return 0;
}
