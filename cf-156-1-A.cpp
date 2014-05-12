/*************************************************************************
    > File Name: cf-156-1-A.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月06日 星期二 21时09分19秒
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
int dp[N][N];
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		map<int,int> last;
		int res=1;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				dp[i][j]=2;
				if(last.count(a[j])!=0)
				{
					int id=last[a[j]];
					dp[i][j]=max(dp[i][j],dp[id][i]+1);
				}
				res=max(res,dp[i][j]);
			}
			last[a[i]]=i;
		}
		cout<<res<<endl;
	}
    return 0;
}
/*
分析：dp[i][j]表示前一位是a[i],后一位是a[j]的最长的序列长度
*/
