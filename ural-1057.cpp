/*************************************************************************
    > File Name: ural-1057.cpp
    > Author: mengshangqi
    > Mail: mengshangqi@gmail.com 
    > Created Time: 2014年04月24日 星期四 21时24分43秒
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
const int N=33;
int c[N][N];
void init()
{
	memset(c,0,sizeof(c));
	c[0][0]=1;
	c[0][1]=0;
	for(int i=1;i<N;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
}
int binary(int x,int b)
{
	int bit[N];
	int cont=0;
	while(x)
	{
		bit[cont++]=x%b;
		x/=b;
	}
	int res=0;
	for(int i=cont-1;i>=0;i--)
	{
		if(bit[i]>1)
		{
			for(int j=i;j>=0;j--)
				res|=(1<<j);
			break;
		}else {
			res|=(bit[i]<<i);
		}
	}
	return res;
}
int calc(int x,int k)
{
	int cont=0;
	int res=0;
	for(int i=31;i>0;i--)
	{
		if(x&(1<<i))
		{
			cont++;
			if(cont>k) break;
			x=x^(1<<i);
		}
		if((1<<(i-1))<=x)
		{
			res+=c[i-1][k-cont];
		}
	}
	//cout<<x<<endl;
	if(cont+x==k) res++;
	return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	init();
	int x,y,k,b;
	while(cin>>x>>y>>k>>b)
	{
		int ans=calc(binary(y,b),k)-calc(binary(x-1,b),k);
		cout<<ans<<endl;
	}
    return 0;
}
