/*************************************************************************
    > File Name: hdu-1438.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年03月03日 星期一 21时02分11秒
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
typedef long long ll;
const int N=33;
ll dp[N][16][5][2];
int cont[16];
int main()
{
	freopen("input.txt","r",stdin);
	memset(cont,0,sizeof(cont));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i&(1<<j)) cont[i]++;
		}
	}
	for(int i=0;i<4;i++)
		dp[1][1<<i][i][0]=1;

	for(int i=2;i<=31;i++)
		for(int j=0;j<16;j++)
			for(int k=0;k<4;k++)
			{
				for(int kk=0;kk<4;kk++)
				{
					int status=j|(1<<kk);
					dp[i][status][kk][1]+=dp[i-1][j][k][1];
					if(abs(k-kk)==3) dp[i][status][kk][1]+=dp[i-1][j][k][0];
					else dp[i][status][kk][0]+=dp[i-1][j][k][0];
				}
			}

	for(int i=2;i<=31;i++)
	{
		ll res=0;
		for(int j=0;j<16;j++)
			for(int k=0;k<4;k++)
				if(cont[j]>=3) res+=dp[i][j][k][1];
		cout<<"N="<<i<<": "<<res<<endl;
	}
	return 0;
}
/*
分析：dp[i][status][j][k]表示前 i 个锁孔 status锁孔状态，最后一个锁孔是 j，k 是 0 或者 1 表示是否存在锁孔相差 3，的总数。
*/
