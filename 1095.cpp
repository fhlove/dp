/*************************************************************************
    > File Name: 1095.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年05月05日 星期一 21时59分31秒
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
int vec[2][2];
void init()
{
	vec[0][0]=1;
	vec[0][1]=1;
	vec[1][0]=1;
	vec[1][1]=0;
}
void mul(int a[2][2],int b[2][2])
{
	int x[2][2];
	for(int i=0;i<2;i++)
	{
		int res=0;
		for(int j=0;j<2;j++)
		{
			res=(res+a[i][j]*a[j][i])%mod;
		}
		x[i][j]=res;
	}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			a[i][j]=x[i][j];
}
void power(int x)
{
	init();
	int v[2][2];
	memset(v,0,sizeof(v));
	v[0][0]=v[1][1]=1;
	while(x)
	{
		if(x&1) mul(v,vec);
		mul(vec,vec);
		x=x<<1;
	}
	int res=0;
	res+=(v[0][0]+v[0][1]+v[]1][0]);
	cout<<res<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n;
	cin>>t;
	for(int c=1;c<=t;c++)
	{
		cin>>n;
		init();
		power(n);
	}
    return 0;
}
