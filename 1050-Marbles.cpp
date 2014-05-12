/*************************************************************************
    > File Name: 1050-Marbles.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月31日 星期一 20时51分46秒
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
const int N=501;
double dp[N][N];
void init()
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<N;i++)
		dp[0][i]=1;
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if((i+j)&1)
			{
				dp[i][j]=dp[i-1][j-1]*(i*1.0/(i+j))+dp[i][j-2]*(j*1.0/(i+j));
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int cont=1;
	int n;
	init();
	cin>>n;
	while(n--)
	{
		int r,b;
		cin>>r>>b;
		printf("Case %d: ",cont++);
		cout<<dp[r][b]<<endl;
	}
    return 0;
}
