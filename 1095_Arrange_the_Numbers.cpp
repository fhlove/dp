/*
PROG: 1095_Arrange_the_Numbers.cpp
ID: fhlove
LANG: C++
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<set>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1005;
typedef long long LL;
const LL mod=1000000007;
LL a[N],c[N][N];
int odd(int x)
{
	return x&1? -1:1;
}
void init()
{
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	a[0]=1;
	c[0][0]=1;
	for(int i=1;i<=1000;i++)
		a[i]=(a[i-1]*i)%mod;
	for(int i=1;i<=1000;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
}
LL calc(int n,int m,int k)
{
	int x=m-k;
	int y=n-m;
	LL res=0;
	for(int i=0;i<=x;i++)
	{
		res=(res+c[x][i]*a[x+y-i]*odd(i)%mod)%mod;
		res=(res+mod)%mod;
	}
	return (res*c[m][k])%mod;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	int t;
	int n,m,k;
	init();
	scanf("%d",&t);
	for(int c=1;c<=t;c++)
	{
		scanf("%d%d%d",&n,&m,&k);
		LL res=calc(n,m,k);
		printf("Case %d: %lld\n",c,res);
	}
    return 0;
}
/*
分析：容斥原理
*/
