/*************************************************************************
    > File Name: 1038.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月19日 星期六 21时15分10秒
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
const int N=100005;
double dp[N];
void init()
{
	dp[1]=0;
	for(int i=2;i<N;i++)
	{
		double sum=0;
		int cont=0;
		for(int j=1;j<=(int)sqrt(i);j++)
		{
			if(i%j==0)
			{
				cont++;
				sum+=dp[i/j];
				if(j*j!=i)
				{
					cont++;
					sum+=dp[j];
				}
			}
		}
		sum+=cont;
		dp[i]=sum/(cont-1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	scanf("%d",&t);
	int n;
	init();
	for(int c=1;c<=t;c++)
	{
		scanf("%d",&n);
		printf("Case %d: %.6lf\n",c,dp[n]);
	}
    return 0;
}
/*
dp[i]表示i的期望，dp[i]=(dp[a1]+dp[a2]+dp[a3]+...........dp[ak]+k)/k;
*/
