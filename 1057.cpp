/*************************************************************************
    > File Name: 1057.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月23日 星期三 19时50分28秒
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
const int inf=9999999;
struct node
{
	int x,y;
};
node p[N];
char str[25][25];
int dp[1<<N][N];
int dis(node a,node b)
{
	return max(abs(a.x-b.x),abs(a.y-b.y));
}
void init(int n)
{
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			dp[i][j]=inf;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n,m;
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d%d",&n,&m);
		
		int cont=1;
		
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(str[i][j]=='x') p[0].x=i,p[0].y=j;
				else if(str[i][j]=='g') {
					p[cont].x=i;
					p[cont].y=j;
					cont++;
				}
		init(cont);

		dp[1][0]=0;
		
		for(int s=1;s<(1<<cont);s++)
		{
			for(int u=0;u<cont;u++)
			{
				if(dp[s][u]!=inf)
				{
					for(int v=0;v<cont;v++)
					{
						if((1<<v)&s) continue;
						int now=(s|(1<<v));
						dp[now][v]=min(dp[now][v],dp[s][u]+dis(p[u],p[v]));
					}
				}
			}
		}
		int ans=inf;
		for(int i=0;i<cont;i++)
			ans=min(ans,dp[(1<<cont)-1][i]+dis(p[i],p[0]));
		printf("Case %d: %d\n",c,ans);
	}
    return 0;
}
/*
分析：旅行商问题，总共最多15个点，用一个整数表示已访问的点的集合，从零点出发,然后递推即可
*/
