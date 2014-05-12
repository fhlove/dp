/*************************************************************************
    > File Name: 1037.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月19日 星期六 19时56分58秒
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
const int N=16;
const int inf=10000000;
int dp[1<<N];
int blood[N];
char str[N][N];
void init(int n)
{
	for(int i=0;i<=(1<<n);i++)
			dp[i]=inf;
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
		for(int i=0;i<n;i++)
			scanf("%d",&blood[i]);
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);
		init(n);

		for(int i=0;i<n;i++)
			dp[1<<i]=blood[i];
		
		for(int s=0;s<(1<<n);s++)
		{
			for(int i=0;i<n;i++)
			{		
				if(s&(1<<i)&&dp[s]!=inf)
				{
					for(int j=0;j<n;j++)
					{
						if(s&(1<<j)) continue;
						int da=str[i][j]-'0';
						if(da==0) da=1;
						int temp=blood[j]/da+(blood[j]%da==0? 0:1);
						dp[s|(1<<j)]=min(dp[s|(1<<j)],dp[s]+temp);
					}
				}
			}
		}	
		printf("Case %d: %d\n",c,dp[(1<<n)-1]);
	}
    return 0;
}
/*
dp[s]表示武器状态为s时的最小花费
*/
